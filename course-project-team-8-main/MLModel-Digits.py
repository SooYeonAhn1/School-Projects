import tensorflow as tf 

mnist = tf.keras.datasets.mnist ##this line acceses the dataset
##these are all handwritten characters 28x28 sized images of 0-9

(x_train, y_train),(x_test, y_test) = mnist.load_data()
##putting the data set into 2 seperate train and test data sets
x_train.shape ##outputs (6000, 28, 28) 6000 images of size 28x28

##--------------------------------------------

import matplotlib.pyplot as plt

plt.imshow(x_train[0])
plt.show()
plt.imshow(x_train[0])
plt.imshow(x_train[0], cmap = plt.cm.binary)

##this grabs the first test image and puts it on a grah
##and also it makes it black and white by putting it into binary

## print (x_train[0]) ##prints out the 5 in pixels of rgb values 


##now we have to normalize the image so its in the gray scale not RGB values
x_train = tf.keras.utils.normalize (x_train, axis = 1)
x_test = tf.keras.utils.normalize(x_test, axis = 1)
plt.imshow(x_train[0], cmap = plt.cm.binary)

print (x_train[0]) ##this prints the values in grey scale from 0-1

print (y_train[0])

##---------------------------------------------

import numpy as np

##now we are resizing the image here so we could apply the convolution 
##operation 


IMG_SIZE=28
x_trainr = np.array(x_train).reshape(-1, IMG_SIZE, IMG_SIZE, 1)
x_testr = np.array(x_test).reshape(-1, IMG_SIZE, IMG_SIZE, 1)

##this is increasing train/test by one dimension for kernal filter operation 

print ("Training Samples Dimension ", x_trainr.shape)
print ("Testing Samples dimension ", x_testr.shape)

##good link to understand kernal filter/convolution operations 
## https://towardsdatascience.com/convolution-neural-networks-a-beginners-guide-implementing-a-mnist-hand-written-digit-8aa60330d022

##---------------------------------------------

##here were going to start creating our machine learning model

from tensorflow.keras.models import Sequential 
from tensorflow.keras.layers import Dense, Dropout, Activation, Flatten, Conv2D, MaxPooling2D

##creating a neural network
## a neural network are able to learn and pick up patterns

model = Sequential()


##First Convolution layer   
model.add(Conv2D(64, (3,3), input_shape = x_trainr.shape[1:])) ##64 stands for number of colors/filters, and each filter has a 3 by 3 size
##our input image is x_trainr and were only grabbing (28,28,1) a single image from (60000, 28, 28, 1)


model.add(Activation("relu")) ##our activation function to make it non-linear. Removes all values <0 and keeps all values >0
model.add(MaxPooling2D(pool_size=(2,2))) ##Maxpooling single maximum value of 2x2 matrix then drops the rest of the values 

##Second Convolution layer   
model.add(Activation("relu"))
model.add(MaxPooling2D(pool_size=(2,2)))

##Third Convolution layer  
model.add(Conv2D(64, (3,3)))
model.add(Activation("relu"))
model.add(MaxPooling2D(pool_size=(2,2)))

##Fully connected layer 
model.add(Flatten())  ##you need to flatten first so that 2d becomes 1d
model.add(Dense(64)) #64 neurons 
model.add(Activation("relu")) #final activation layer 

## Last fully connected layer, this output must equal number of classes, 10 (0-9)
model.add(Dense(10)) ##the last dense layer should be = to 10
model.add(Activation('softmax')) ## activation function is changed to softmax

model.summary()

print ("Totaling Training Samples = ", len(x_trainr))

model.compile(loss ="sparse_categorical_crossentropy", optimizer ="adam", metrics=['accuracy'])  ##compiling the model 
model.fit(x_trainr,y_train,epochs=5,validation_split = 0.3) ##training the model 
##data is xtrainr label is ytrain (the digit)

test_loss, test_acc = model.evaluate(x_testr, y_test)
print ("Test loss on 10,000 test samples", test_loss )
print ("Validation Accuracy on 10,000 test samples", test_acc )

## Predictions new_model.predict([x_test]) there is a specialied method for efficently saving your model, to name all inputs
## therefore instead of usign new model loaded, for now only for predictions I am using model
predicions = model.predict([x_testr])
print (predicions) ##actually these predictions are based on one encoeding so these are only arrays containing

# in order to understand, convert the predicions from one encoding, we need to use numpy for that 
print (np.argmax(predicions[0])) 

## now to check that is our answer is true or not 
plt.imshow(x_test[0]) 

##^^ tests the number 7 from the data set and then prints it out

# in order to understand, convert the predicions from one encoding, we need to use numpy for that 
print (np.argmax(predicions[128])) ##printing the number

## now to check that is our answer is true or not 
plt.imshow(x_test[128]) ## basically printing what it reads 

##tests the number 8 from the data set then prints it out

##Here I inputted my own png to test my model
##i uploaded the png to the notebook so i could access it 
##I wrote the number 6 and it looks like it can read 6

import cv2
import matplotlib.pyplot as plt
import numpy as np



img = cv2.imread('imagesix.png')
plt.imshow(img)

img.shape

gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

gray.shape

resized = cv2.resize(gray, (28,28),interpolation = cv2.INTER_AREA)

resized.shape

##now we normalize the image after we resize it

newimg = tf.keras.utils.normalize(resized, axis = 1) ##0 to 1 scaling
newimg = np.array(newimg).reshape(-1, IMG_SIZE, IMG_SIZE,1) 

newimg.shape

predicions = model.predict(newimg)

print (np.argmax(predicions))

##Here im testing out another test image that I made of the number 5

import cv2
import matplotlib.pyplot as plt
import numpy as np



img = cv2.imread('five.png')
plt.imshow(img)

img.shape

gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

gray.shape

resized = cv2.resize(gray, (28,28),interpolation = cv2.INTER_AREA)

resized.shape

##now we normalize the image after we resize it

newimg = tf.keras.utils.normalize(resized, axis = 1) ##0 to 1 scaling
newimg = np.array(newimg).reshape(-1, IMG_SIZE, IMG_SIZE,1) 

newimg.shape

predicions = model.predict(newimg)

print (np.argmax(predicions))



def predict_image(img): ##reshaping the inputed image
    img_3d=img.reshape(-1, 28, 28)
    im_resize=img_3d/255.0
    prediction=model.predict(x_testr)
    pred=np.argmax(prediction)
    print(pred)
    
iface = gr.Interface(predict_image, inputs="sketchpad", outputs="label")


iface.launch(debug='True', share='True')



##Link to code: https://datalore.jetbrains.com/notebook/FMzJtBLkMHracU8fQKRr1A/3hbMAg8gpjou5CrTbZXmMG/
