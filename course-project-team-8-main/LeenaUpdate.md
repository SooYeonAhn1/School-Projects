**Week of 9/30**

This week I learned what models were and watched a couple of videos on deep learning in order to better understand how to approach creating a model and integrating it into an app. I learned about neural networks, kernel filters, convolution, padding, and more. I watched a tutorial video on how to create and train a model with python instead of through coreML on xcode due to the limited accessibility of Xcode on our devices. 

I followed a tutorial video that was introducing the basics of machine learning while walking you through how to build a machine learning model that is able to read handwritten digits. Since I'm unfamiliar with deep learning I found watching a video and having an example to look back on helpful. I used TensorFlow which is an open-source library developed by google for machine learning applications. The data set that was used in the video was MNIST Data Set which is contained in TensorFlow.

Video link: Deep Learning- Handwritten Digits Recognition Tutorial | Tensorflow | CNN | for beginners

My plan for next week is to make sure I complete the tutorial and try to edit the model to take a different data set of handwritten text and then train the model. 


**Week of 10/7**

This week I completed the tutorial and learned how to train the model with the MNIST data set to read hand written digits.
This makes our group on track with the schedule we wrote. I also wrote my own test images to see how accurate the model is with outside data. My plan for next week is to find more data sets to train my model with so it becomes more accurate to messy handwriting. I also want to train my model with the ENMIST data set of handwritten letters that Sue suggested to use. Then I want to start training my model to read groups of words and numbers by using OCR. In my freetime I plan to continue learning web development. I started a udemy web devolopment course a couple months ago that I plan to make some progress on this week. 

**Week of 10/14**

This week I completed creating a model that can characters. I wasn't able to retrain the previous model that read digits to also read characters. Emnist provided a data set called 'By Class' that has both numbers and letters so I could train a new model. However when I ran it on datalore and it had a 67% accuracy. I made a few changes to the model in hopes of improving the accuracy however as of today I haven't been able to run my code anymore on Datalore because I'm out of memory and I need to upgrade. I spent today trying to find an alternate software to run my model. I tried to use MaxPooling to max reduce my data set but I found no sucess. I changed my data set to soley letters. This week I plan to continue to test my new model and I also plan to  transition to creating the website. I do plan to continue with my web development course on udemy and also watch some videos on react.

**Week of 10/21**

I was trying to use the gradio software to help deploy my machine learning model but also add a feature to our website that allows our machine learning model to learn from user input. I am still in the process of creating this feature but I do plan to have it continuously learn from user input.

I hope to have the user upload an image of their handwriting and then my model will make a prediction. Then the user can go in and say if the model was correct and if not the user can type in the corrections. If time permits we could also have an accuracy feature. I'm still unsure why it's not generating a number as an output but I'm currently debugging that. 



def predict_image(img): ##reshaping the inputed image
    img_3d=img.reshape(-1, 28, 28)
    im_resize=img_3d/255.0
    prediction=model.predict(x_testr)
    pred=np.argmax(prediction)
    print(pred)
   
iface = gr.Interface(predict_image, inputs="sketchpad", outputs="label") ##deploying it as skechpad 
 
iface = gr.Interface(predict_image, inputs="image", outputs="label") ##this allows me to test my model using an uploaded image
 
iface.launch(debug='True', share='True')

![alt text](https://i.postimg.cc/G4MNgJHD/Screenshot-2022-10-21-185250.png)



I also followed this youtube video tutorial and using OCR and was able to extract text from an image which is something we also want to be able to use in our website. 

https://datalore.jetbrains.com/notebook/FMzJtBLkMHracU8fQKRr1A/ADzeMXaaIFWDHqVJgXpv9z/

OCR Text recognition with Python and API (ocr.space)


![alt text](https://i.postimg.cc/v1cKJgVN/Screenshot-2022-10-21-185217.png)




I found this youtube video that deploys their ml model on a webpage and I hope to use their code as a template for deploying my machine learning model since im not familiar with deploying a Machine learning model to a website. I want to add different features such as uploading an image and also allowing it to learn from user input. I plan to have my machine-learning model deployed on a website by next week

https://www.youtube.com/watch?v=Pc8WdnIdXZg
https://github.com/nachi-hebbar/Forest-Fire-Prediction-Website 

**Week of 10/28**

I made a feature for our website using Optical Character Regongition. I followed a tutorial on youtube. However, I found some difficulty getting my code to work after the video because the tesseract version, a python package, that was needed for the code to compile had been deprecated.  When I used an updated version of tesseract and followed the instructions on video one of the methods wouldn’t work. So I found a solution on StackOverflow that converted an image to text. However, I had to figure out how to use a file upload and put that into a function. Next week I plan to try to deploy my machine learning model to a website. Im having trouble finding a tutorial video on how to do that so I plan to find some github templates in order to assist me. Also my ocr feature only works for text not handwritten text.

Youtube link: https://www.youtube.com/watch?v=a1I3tcALTlc

![alt text](https://i.ibb.co/YZkFfrj/ocr3.png)
![alt text](https://i.ibb.co/Pwbt7NC/ocr2.png)
![alt text](https://i.ibb.co/sqt7pbY/ocr1.png)


**Week of 11/04**

This week I worked on routing for the website. I wanted to add multiple pages to the website to add pages for each feature of our website. I also created the homepage of our website. I created a page for uploads and a page for the homepage. Its an outline currently but I plan to add more text and color to it soon. My goal for next week is to deploy my machine learning model and also start merging our groups code into one website instead of multiple different ones through routing. I found a github template that deploys a machine learning model that I will attempt to get to work and expand from there becuase I haven't been able to find tutorials to assist me in deploying a machine learning model. 

![alt text](https://i.ibb.co/tbnHq9X/homepage.png)
![alt text](https://i.ibb.co/GWq9fwN/uploads.png)

Github template: https://github.com/suryachereddy/Tensorflow_MNIST_Web

**Week of 11/11**

This week I worked on trying to deploy the model onto the website. I tried to follow a blog post by geeks for geeks but my code would not work because I couldn't get the canvas to show up. Then I found a couple templates on github that depolyed their models and I got them to run on my machine. I found a template that allows you to train your own model and use it on the website. However I ran it the first time and it predicted the number I wrote but recently it stopped working. The code for it is under mnist-node.js. I found another template however, that does predict what you drew. I hope by next week I can get it to take a file upload. If I can get it to take a file upload then we could integrate Sue's bounding boxes which takes handwriting and seperates it into png's of characters. Then I want to upload those characters into the depolyed model and have it predict those characters. Afterwards I hope that we can put those characters together to form a word.

First template:
![image](https://user-images.githubusercontent.com/90123334/201458962-52b0639e-b29c-4e3e-ab30-fce780182b2c.png)
![image](https://user-images.githubusercontent.com/90123334/201459000-39fd844b-d776-43ca-888a-820d797e7e9e.png)

Github template: https://github.com/danazkari/mnist-nodejs

Second template:
![image](https://user-images.githubusercontent.com/90123334/201459680-cab79df4-6e14-4516-9c15-6833a1fa96c0.png)
![image](https://user-images.githubusercontent.com/90123334/201459723-21c4b4ea-5aec-46cd-aaf8-aafb89c50797.png)

Github template: https://github.com/obackhoff/mnist-web-canvas
 
**Week of 11/18**

This week I tried to get the template I found to take a file upload instead of a canvas and have the model predict the number that was in the file upload. However I struggled to get the file upload feature to work. The prediction would not display onto the canvas. The only thing that would display was just the file that was uploaded. I also haven't added it to the OCR website because it doesn't work. I plan to add it once I get the feature to work. For fall break I will try to get it to take a file upload. This week I worked on fixing the image to text converter feature on the website. However, it crashes the first time you try to convert an image but after refreshing it works. 

![image](https://user-images.githubusercontent.com/90123334/202836326-6ff8b0a9-d4c7-450c-a85f-730192a1e0af.png)
![image](https://user-images.githubusercontent.com/90123334/202836389-868e0e3a-da56-4622-9b15-b8831f704ea0.png)
![image](https://user-images.githubusercontent.com/90123334/202836764-caf1ca4f-1238-47f9-a212-6f4213e9bcc3.png)

**Week of 12/2**

Over fall break and this week I worked on making sure the OCR feature doesn't crash anymore. I got it to stop crashing as often and I also started testing it with random images from google and it seems that it is working. It doesn't work however when there is alot of noise in the photo. I also made some progress on taking a file upload and having it predict the handwritten digit. Currently it takes a fileupload and then it prints the data and converts the image into pixels. I have a template I found on github that takes a canvas sketch and predicts it im trying to change it to take a file upload. 

![image](https://user-images.githubusercontent.com/90123334/205426056-c5f65f8d-5cc2-4051-b7be-83f7553715af.png)

![image](https://user-images.githubusercontent.com/90123334/205426085-7a7c7ff5-f475-46ab-afec-7dec39ccea9c.png)

![image](https://user-images.githubusercontent.com/90123334/205426090-64c2fe44-8b59-477d-9e18-8964c1b999eb.png)





