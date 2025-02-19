# MachineLearning Handwriting Recogintion App

## Introduction

Our application is an image to text converter, and basic handwriting recognition software that allows users to easily convert an image with text on it into quickly searchable text. Additionally, we have included a basic digit conversion, in order to help users decipher difficult digits. While there are other applications that do similar things to our program, the quick and efficient use of ours puts it above others, as well as including digit conversion with bounding boxes to allow for lower resolution or harder to read fonts to be recognized. 

## Technical Architecture 

![image](https://user-images.githubusercontent.com/90123334/206929731-73f06c6c-d708-4a87-8304-65da6543520b.png)


### Homepage: ###

The role of our homepage is to give the user a landing page where everything can be easily accessible. The homepage is where we can access and have an interaction between the other components. In our homepage we list the title of our website, the creators of the website, and a link to our github repository. In order to make our website user friendly we created a navbar with routes to our 3 different features on our website, the ImgToText converter, the MLModel feature, and BoundingBox. We also included an about tab to give the user some more detail regarding our project. Connor worked on this feature.

### Optical Character Recognition Feature: ###

The role of our Optical Character Recognition feature is to convert an image of text to text. We thought this feature would be a useful and effective addition to our application because we wanted to give the user an ability to be able to use find f and find a certain word or phrase. But with images users don’t have this option. You can only choose one file at a time and then it will convert it to text. Something that makes our app versatile is that if given simple html code it doesn't print out the code. For instance if given html code for buttons it will actually create 3 buttons instead of simply printing out the code in text. This makes our website very useful because now if you'd like to test any simple html code our website can give you the result. Leena worked on this feature.


### Handwritten Digit Prediction: ###

The role of our Handwritten digit prediction is to help the user decipher through handwritten digits. Sometimes you find yourself struggling to read a digit that is messy or struggling to read your own handwriting. You can upload a picture of the handwritten digit and it will produce a prediction. It also gives you the confidence of its prediction. Additionally the handwritten digit prediction is a file upload that can turn into a canvas. The canvas allows you to go over the digit in white to highlight the digit because when the digit gets predicted the image becomes blurry. Leena worked on this feature.

### Bounding Box: ###

The role of our bounding box feature is to take words or sentences in text and break them into png files of each character. Or take a set of numbers and break them into digits. Then the user is able to download these as zip file to their computer. We thought this would make our website more versatile because our plan was to use the broken up charcters or numbers and put into our ml model feature and predict each individual characters and digits and put it together to print the predicted string. However we couldn’t do what we planned in the time allotted so our bounding box feature can only take words and split them into characters. This can be useful if youd like to use the letters in graphic design projects or would like to arrange a set of characters a certain way for a project. This feature can allow you to be creative with the characters of a sentence/world. Sue worked on this feature.

### Languages and Libraries Used: ###

Languages we used were, python, javascript, and html.

Python libraries we used were tensorflow, keras, matplot, numpy, pytesseract, cv2, Image, Image filter, and listdir.

Javascript libraries we used were express, file, jquery, multer, path, request, request-promise, socket.io, tesseract.js, upload, fs-extra, and zip-local.

## Development ##

Problem 1: Primary Language
Initially, we planned on using Swift as our primary language and creating an IOS app using CoreML and CreateML. At the beginning of our project, we encountered an issue where Connor and I could not get swift to run on our device. This is because Swift is primarily used in macOS and Linux, and for Windows users, swift was not supported. We tried to use a virtual machine and install mac and run swift in the virtual machine. However, there was an error during the installation, so we could not get swift to run on our devices. Instead, we switched to using python as our primary language and using node js to develop a web application. This was because python and node js are supported in both mac and windows. We learned that we should consider the devices that we are using when choosing the language of the project.
 
Problem 2: Communication
Another issue we had was the lack of communication between team members. For the first few weeks, we did not communicate with each other about what we are doing for the week. We did not split the project for each person nor communicate which part we were working on. This made us do overlapping parts of the project, which decreased the efficiency of teamwork. Later in the semester, we split the work that we were going to do and let each other know. This made us do separate parts of the project, increasing the efficiency of teamwork and making it easier for us to finish the project. During this process, we learned that making sure that everyone understands their roles and responsibilities is crucial for efficient teamwork.


## Installation Instructions

**In terminal run:**

git clone https://github.com/CS222-UIUC/course-project-team-8

npm install

## **To Run the Server**

node mnist.js

*Runs on LocalHost:8088*

## Group members and roles

**Leena Abdelrahman:**

* Created the routes for the website and integrated all the features onto the website

* Created the Optical Character Recogintion Feature 

* Created the MLModel prediction feature

**Sue Ahn:**

* Created the bounding box feature

**Connor French:**

*  Worked on website and connecting routes

[![Watch the video](https://user-images.githubusercontent.com/90123334/209387622-1d03f551-c69a-42e3-be7f-c465748d4fb5.png)](https://drive.google.com/file/d/1h_tl_bvMlRlHj8Q_iyWDa0SWcdybwRa5/view?usp=sharing)
