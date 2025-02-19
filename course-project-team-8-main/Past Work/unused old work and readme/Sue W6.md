The group decided to use Swift on Xcode to build the handwriting recognition application (a reference to the project proposal). As a windows user, I could not use Xcode on my device so I tried to make a VirtualBox that uses macOS to use Xcode instead. Based on videos and websites as follows:

- https://www.youtube.com/watch?v=YC_PlSk7U8w
- https://www.makeuseof.com/tag/macos-windows-10-virtual-machine/
- https://www.youtube.com/watch?v=kIXPsAM1iLI
- https://drive.google.com/file/d/1e1zv9y5d8lOBZHYJFJUZchruHxu1ou7Q/view

Unfortunately, this did not work as expected, so the group decided to shift from Xcode to Datalore to build the project.

The following is the code that I worked on after changing to Datalore.

<img width="392" alt="image" src="https://user-images.githubusercontent.com/89664901/193346585-7666febd-623b-4a7c-b021-176a54fc8025.png">
<img width="303" alt="image" src="https://user-images.githubusercontent.com/89664901/193346299-5da58e79-21a1-48ec-8c84-e73563161822.png">

The first image is the code. It extracts the content from the tgz file to a new folder.
The second image is the output of the current code, which is the contents of the file extracted from the tgz file.

Due to the lack of prior experience using python and being new to Datalore, not much work could be done in a day. The commented five lines at the bottom of the first image is the list for next week that I hope to get done by Thursday.

**W7**
In week 6 I planned on finishing the following tasks:
* Filter out null data
* Form data into a list
* Do the same for other .txt files
* Split data into train and test
* Train data + test data => test accuracy

There was no such thing as null data in the .txt files they were all properly formatted when printed, so filtering out null data was unnecessary. I did convert the data into a list and did the same for other .txt files. While I was writing code to prepare the data for machine learning, I realized that we did not have important data. So a few tasks were added:
* Download image
* filter out unnecessary data

This was because the .txt file did not contain the data as expected. More specifically, the data contained in the .txt file only contained the name of the image, what word it represents, and other information regarding the image and not the image itself. The images need to be imported separately into the notebook which is completed. Also, other information except for the name of the image and what word it represents seemed unnecessary, so we decided to remove the unnecessary data, which is still in progress.

During the meeting, it seemed like the data we had seemed inadequate for training, so I searched for a new dataset that contained letters.
Because we are using TensorFlow, we decided to use the following data from emnist:
https://www.tensorflow.org/datasets/catalog/emnist
 
