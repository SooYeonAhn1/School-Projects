const express = require('express')
const rp = require('request-promise')
const fs = require('fs')
const exec = require('child_process').exec;
const multer = require('multer');
const uuid = require('uuid').v4;
const jQuery = require('jquery');
const router = express.Router();
const path = require("path");
const {createWorker} = require('tesseract.js');
const worker = createWorker();
const AdmZip = require("adm-zip");
const app = express()
app.use(express.static(__dirname));
app.listen(8088);

//Storage

const store = multer.diskStorage ({
  destination: (req, file, cb)=> { //takes a request response and a callback
     cb(null, "./uploads"); //call back gets called whenever we upload a file
  },
  filename: (req,file,cb) => {
      cb(null, "predict"+".png");
  }

});

const upload = multer({storage: store}).single('avatar');



//Routes

app.get('/uploads', (req,res)=> { 
  res.sendFile(__dirname + "/html_files/index1.html");
});

app.get('/homepage', (req,res)=> {
 res.sendFile(__dirname + "/html_files/about.html");

});


app.get('/mlmodel', (req, res) => {
  res.sendFile(__dirname + "/html_files/index.html");

})

app.get('/boundingbox', function(req, res) {
  res.sendFile(__dirname + '/boundingbox.html');
});

app.get('/download-cropped-images', (req, res)=> {
  res.download(__dirname + "/output_image/cropped.zip")
})

app.get('/about', (req,res)=> {
  res.sendFile(__dirname + "/html_files/explanation.html");
});


//----------------------------------------------


app.get('/favicon.ico', (req, res) => {
  res.send(fs.readFileSync(__dirname + "/favicon.ico"))
})


app.post('/mlmodel', (req, res) => {
  res.sendFile(__dirname + "/html_files/index.html");
  upload(req, res, err => {
      if (err) {
      } else {
          const file = req.file
         
          console.log(file);
      }
  });
});


app.get('/predict', (req, res) => {
  const img = req.query.img
  if(!img) {
    return res.send("Usage: /predict?img=IMG_STR")
  }

  exec('python ml_model/fnn.py -m ml_model/mnist.model -p ' + '"[[' + img + ']]"',
      function (error, stdout, stderr) {
          res.send(stdout);
          //console.log('stderr: ' + stderr);
          if (error !== null) {
               console.log('exec error: ' + error);
          }
      });
})


//----------------------------------------------------
//Other Storage


const storage = multer.diskStorage ({
  destination: (req, file, cb)=> { //takes a request response and a callback
     cb(null, "./uploads"); //call back gets called whenever we upload a file
  },
  filename: (req,file,cb) => {
      cb(null, file.originalname);
  }

});

const uploaded = multer({storage: storage}).single('avatar');


app.post("/uploads", (req, res) => {
 uploaded(req,res, err=> {
  console.log(req.file)
  fs.readFile(`./uploads/${req.file.originalname}`, (err, data) => {
   if(err) return console.log('This is your error', err); //prints our error
   async function getTextFromImage() {
    await worker.load()
    await worker.loadLanguage('eng')
    await worker.initialize('eng')
    const { data: { text } } = await worker.recognize(data); //takes the user input file and converts it to text
    
        
    res.send(text);
    console.log(text);
    await worker.terminate()
    
    }
    
    getTextFromImage();
  });
 });
});

//---------------------------------------------------


app.post("/boundingbox", (req,res) => {
  upload(req,res, err => {
    console.log("Bounding Box Clicked");
    console.log(req.file);



  // Move the uploaded image to our upload folder
  //image.mv(path);
  const {spawn} = require('child_process');
  const boundingbox = spawn('python',[__dirname + '/bounding_box.py']);

  boundingbox.stdout.on('data', (data) =>{
      console.log(`stdout: ${data}`);
  });

  boundingbox.stderr.on('data', (data) => {
      console.error(`stderr: ${data}`);
  });

  boundingbox.on('close', (code) => {
      console.error(`bounding box exited with code ${code}`);
  });
  // https://javascript.plainenglish.io/how-to-create-zip-files-with-node-js-505e720ceee1 referenced for creating zip files
  var zipper = require('zip-local');
  const zip = new AdmZip();
  const outputFile = "./output_image/cropped.zip";
  zip.addLocalFolder("./output_image");
  zip.writeZip(outputFile);
  console.log(`Created ${outputFile} successfully`);
  
 // zipper.sync.zip("./output_image").compress().save("cropped.zip");

  res.sendFile(__dirname + '/downloadimage.html');
  });
  
  //console.log("Bounding Box clicked");
  
  //if (!image) return res.sendStatus(400);

  // If no image submitted, exit
  //if (!image) return res.sendStatus(400);

  // Move the uploaded image to our upload folder
  //image.mv(__dirname + '/input_image/' + image.name);

  // res.sendStatus(200);
  // res.redirect(__dirname + '/boundingbox.html');

  
});

app.get('/delete-uploaded-images', (req, res)=> {
  const fsExtra = require('fs-extra');
  fsExtra.emptyDirSync(__dirname + "/input_image");
  fsExtra.emptyDirSync(__dirname + "/output_image");
  res.sendFile(__dirname + '/boundingbox.html');
})


