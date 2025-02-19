const express = require("express");
const app = express();
const fs = require("fs"); //used to read files 
const multer = require("multer"); //upload files to our server 
const {createWorker} = require("tesseract.js");
const worker = createWorker(); ({
   logger: m => console.log(m)
});
const path = require("path");


//Storage

const storage = multer.diskStorage ({
    destination: (req, file, cb)=> { //takes a request response and a callback
       cb(null, "./uploads"); //call back gets called whenever we upload a file
    },
    filename: (req,file,cb) => {
        cb(null, file.originalname);
    }

});
const upload = multer({storage: storage}).single('avatar');

app.set("view engine", "ejs"); 
app.set("views", path.join(__dirname, "views"));
//Routes
app.get('/uploads', (req,res)=> { //./upload gets to the upload site
    res.render('index');
});
app.get('/homepage', (req,res)=> { 
   res.render('about');
});
app.get('/homepage', (req,res)=> { 
   res.render('about');
});
app.get('/about', (req,res)=> { 
    res.render('explanation');
 });
app.get('/works', (req,res)=> { //./upload gets to the upload site
   res.render('mlmodel');
});


app.post("/uploads", (req, res) => {
   upload(req,res, err=> {
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

//Start up our server 
const PORT = 5000 || process.env.PORT;
app.listen(PORT, () => console.log(`Hey Im running on port ${PORT}`));

// app.get('/uploads', (req,res) => {
//     console.log("hey")
// })
