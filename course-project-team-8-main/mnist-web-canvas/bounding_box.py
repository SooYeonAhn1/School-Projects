# Bounding box code built based on "https://www.youtube.com/watch?v=6DjFscX4I_c"
# currently works for printed text example (input_imaeg\HELLO_WORLD.png)
# need more time to figure out how to get it to work for written text

# Expected Behavior: Identifies individual characters in a given image from the input_image folder.
#                    Crops the image into individual images of characters.
#                    Stores the cropped images in the cropped_image folder.
#######################################################################################################

# import matplotlib.pyplot as plt
import pytesseract
import cv2
import numpy as np
from PIL import Image, ImageFilter
import os
from os import listdir
pytesseract.pytesseract.tesseract_cmd = r'C:\\Program Files\\Tesseract-OCR\\tesseract.exe'
#                                          ^^ change this for your device
# ### actual code
# filename = "C:\\Users\\USER\\cs222\\course-project-team-8\\Bounding Box\\input_image\\my_handwriting.png"
filename = r'uploads\predict.png'
img = cv2.imread(filename)
img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)

### used to resize image for easier display of "Result"
# image = Image.open(filename)
# h, w = image.size
# ig = image.resize((500, 200))
# ig = cv2.resize(img, (0,0), fx = 2, fy = 1)
# rescale_filename = "C:\\Users\\USER\\cs222\\course-project-team-8\\Bounding Box\\input_image\\resized_handwriting.png"
# cv2.imwrite(rescale_filename, ig)



### inverted image
# inverted_img = cv2.bitwise_not(img)
# cv2.imshow("invert", inverted_img)

# ### grayscale image first before anything else
# def get_grayscale(img):
#     return cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
# # img = get_grayscale(img)

# ### normalizing image (brings pixel range from 0-255)
# norm_img = np.zeros((img.shape[0], img.shape[1]))
# img = cv2.normalize(img, norm_img, 0, 255, cv2.NORM_MINMAX)
# cv2.imshow("normal",img)

# # ### set dpi differently
# def fix_dpi(file_name) :
#     im = Image.open(file_name)
#     im.save("C:\\Users\\USER\\cs222\\course-project-team-8\\Bounding Box\\input_image\\fix_dpi.png", dpi = (450, 450))

# # fix_dpi(filename)


# ### binarize image
# def thresh_img(img):
#     # grayscale_image = get_grayscale(img)
#     thresh, binary_img = cv2.threshold(img, 0, 255, cv2.THRESH_BINARY_INV + cv2.THRESH_OTSU)
#     return binary_img
# #cv2.imshow("binarize", im_bw)


# ### blur image
# def blur_image(img) :
#     return cv2.GaussianBlur(img, (9, 9), 0)
#     # return img.filter(ImageFilter.BLUR)


# ### deskew image
# ### completely based on this code: https://becominghuman.ai/how-to-automatically-deskew-straighten-a-text-image-using-opencv-a0c30aed83df
# # find rotate angle
# def getSkewAngle(img) -> float:
#     copy_img = img.copy()
#     gray_copy_img = get_grayscale(copy_img)
#     blur_copy_img = blur_image(gray_copy_img)
#     thresh_copy_img = thresh_img(blur_copy_img)

#     kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (30, 5))
#     dilate = cv2.dilate(thresh_copy_img, kernel, iterations=5)

#     contours = cv2.findContours(dilate, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)[0]
#     contours = sorted(contours, key = cv2.contourArea, reverse = True)

#     largestContour = contours[0]
#     minAreaRect = cv2.minAreaRect(largestContour)

#     angle = minAreaRect[-1]
#     if angle < -45:
#         angle = 90 + angle
#     return -1.0 * angle

# # rotate image in opposite direction
# def rotateImage(img):
#     angle = getSkewAngle(img)
#     (h, w) = img.shape[:2]
#     center = (w // 2, h // 2)
#     M = cv2.getRotationMatrix2D(center, angle * -1, 1.0)
#     img = cv2.warpAffine(img, M, (w, h), flags=cv2.INTER_CUBIC, borderMode=cv2.BORDER_REPLICATE)
#     return img

# rotate_img = rotateImage(img)
# cv2.imshow('rotate', rotate_img)
# cv2.imwrite("C:\\Users\\USER\\cs222\\course-project-team-8\\Bounding Box\\cropped_image\\rotated.png", rotate_img)



##### detecting individual characters #####
# def boundingbox(filename):
folder_dir = r'uploads'
for images in os.listdir(folder_dir):
    if (images.startswith("predict") and images.endswith("png")):
        print(folder_dir + images)
        img = cv2.imread(folder_dir +"\\" + images)
        hImg, wImg,_ = img.shape
        boxes = pytesseract.image_to_boxes(img)
        ### i is a variable that will be used when naming the cropped images
        i = 0

        for b in boxes.splitlines():
            ### to name individual letters differently
            i = i + 1
            ### merge data into list based on space
            b = b.split(' ')    
            x,y,w,h = int(b[1]), int(b[2]), int(b[3]), int(b[4])

            ### printing boxes on img
            ### image to box | x y coordinates | x + w y + h coordinates | color | thickness
            # cv2.rectangle(img, (x, hImg - y), (w, hImg - h), (0, 255, 0), 3)

            ### cropping the identified letters into individual images
            cropped_image = img[hImg- h:hImg - y, x:w]

            ### give a name to the cropped image and save it in the cropped_image folder
            cropped_image_name = 'output_image/cropped' + str(i) + ".png"

            ### writing the actual image as a file
            cv2.imwrite(cropped_image_name, cropped_image)

            # cv2.imshow("Result", img)
            # cv2.waitKey(0)
