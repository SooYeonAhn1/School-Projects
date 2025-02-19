const express = require('express');
const fileUpload = require('express-fileupload');
const PORT = 1234;
const app = express();
const fs = require('fs');
app.use(express.static('public'));

app.use(fileUpload());

app.get('/', function(req, res) {
    res.sendFile(__dirname + '/boundingbox.html');
});

// app.post('/submit', (req,res) => { 

// });

app.post('/boundingbox', (req,res) => {
    console.log("Bounding Box clicked");

    const { image } = req.files;

    // If no image submitted, exit
    if (!image) return res.sendStatus(400);

    // check if image name already exists in folder
    var num = 1;
    path = __dirname + '/input_image/' + image.name;
    console.log(image.name.substr(0, image.name.length - 4));
    while (fs.existsSync(path)) {
        path = __dirname + '/input_image/' + image.name.substr(0, image.name.length - 4) + num.toString() + '.png';
        num++;
    }

    // Move the uploaded image to our upload folder
    image.mv(path);

    // res.sendStatus(200);
    // res.redirect(__dirname + '/boundingbox.html');


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

    zipper.sync.zip(__dirname + "/output_image/").compress().save(__dirname + "/output_image/cropped.zip");

    res.sendFile(__dirname + '/downloadimage.html');
});

// app.post('/', (req, res) => {
//     // console.log("Bounding Box clicked");
//     console.log("submit images clicked");

//     const { image } = req.files;

//     // If no image submitted, exit
//     if (!image) return res.sendStatus(400);

//     // check if image name already exists in folder
//     var num = 1;
//     path = __dirname + '/input_image/' + image.name;
//     console.log(image.name.substr(0, image.name.length - 4));
//     while (fs.existsSync(path)) {
//         path = __dirname + '/input_image/' + image.name.substr(0, image.name.length - 4) + num.toString() + '.png';
//         num++;
//     }

//     // Move the uploaded image to our upload folder
//     image.mv(path);
//     // import alert from 'alert'
//     const alert = require('alert');
//     alert('File succesfully uploaded')

//     // res.sendStatus(200);
//     // res.redirect(__dirname + '/boundingbox.html');
//     res.sendFile(__dirname + '/boundingbox.html');
// });

app.get('/download-cropped-images', (req, res)=> {
    res.download(__dirname + "/output_image/cropped.zip");
})

app.get('/delete-uploaded-images', (req, res)=> {
    const fsExtra = require('fs-extra');
    fsExtra.emptyDirSync(__dirname + "/input_image");
    fsExtra.emptyDirSync(__dirname + "/output_image");
    res.sendFile(__dirname + '/boundingbox.html');
})
app.listen(PORT, () => console.log(`Hey Im running on port ${PORT}`));
