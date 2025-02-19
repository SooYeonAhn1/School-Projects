LabGroup81 Final Project

Build:
-Once the desired sequence of edits as been written in the main funciton of driver.cc, 
write in the terminal:
    "make exec"
-Once that is finished, write in terminal:
    "./bin/exec"
  and any new ppm files created will be saved in the folder


Use:
- Must have a valid ppm file saved in folder.

- To load image to process, in the main funciton of driver.cc write:
     "Image image_name("filename.ppm");"
 This will create an Image object from which the image processing will occur.

- if no ppm image available, writing:
     "Image image_name;
      image_name.TestImage(desired width integer, desired height integer);"
  will create a colorful image of custom dimensions.

- To save an image to a new ppm file after editing, write:
    "image_name.ToPPM("newfilename.ppm");"
  This will save a new file of the new image into your folder.

- To undo all changes and revert back to the original image(the same image stored in the original ppm file), write:
    "image_name.RevertToOriginal();"

- To copy a new Image object from a previously declared and edited Image object, write:
    "Image new_image_name(old_image_name);"
  After processing new_image_name as much as the user wants, writing:
    "new_image_name.RevertToOriginal();"
  will return the image back to the state it was in when it was copied from the old image.

- The list of image-processing-functions are as follows:
    "imagename.Grayscale();
              .Redscale();
              .Greenscale();
              .Bluescale();
              .Magentascale();
              .Yellowscale();
              .Cyanscale();
              .Negative();
              .Contrast(integer value between -255 and 255);
              .Blur(integer value);
              .Brighten(integer value);
              .HorizontalFlip();
              .VerticalFlip();
              .Merge(second_image_name); (where image_name has the same dimensions and second_image_name)"


    

Test:

- In terminal, write "make tests"
- Once finished, write "./bin/tests" to run test cases
