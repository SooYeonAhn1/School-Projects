import pytesseract
# import PIL.Image
import cv2
# import tensorflow
import easyocr
# import keras_ocr
# import pandas as pd


pytesseract.pytesseract.tesseract_cmd = "C:\\Program Files (x86)\\Tesseract-OCR\\tesseract.exe"

### import text from image
# fontimage = "C:\\Users\\USER\\cs222\\course-project-team-8\\Bounding Box\\input_image\\HELLO_WORLD.png"
# handwritingimage = "C:\\Users\\USER\\cs222\\course-project-team-8\\Bounding Box\\input_image\\resized_image.png"
folder_path = 'C:\\Users\\USER\\cs222\\course-project-team-8\\Bounding Box\\input_image'
name = '\\HELLO_WORLD'
test_image = folder_path + name + '.png'

text_image = cv2.imread(test_image)

### extracts text from images of texts that are written in a font
def extract_text(text_image):
    configtext = r"--psm 0 --oem 3"
    text = pytesseract.image_to_string(PIL.Image.open(image), config=configtext)
    print(text)
    output_folder_path = 'C:\\Users\\USER\\cs222\\course-project-team-8\\Bounding Box\\image_to_text_output'
    output_text = output_folder_path + name + '.txt'
    text_file = open(output_text, "w", encoding="utf-8")
    text_file.write(text)
    text_file.close()

### based on https://www.youtube.com/watch?v=oyqNdcbKhew
def find_word(img, word):
    reader = easyocr.Reader(['en'], gpu=False)
    results = reader.readtext(img)
    size = len(results)
    word = word.lower()
    # print(results)
    for i in range(size):
        string_found = results[i][1].lower()
        # print(string_found)
        if word in string_found:
            x,y,w,h = results[i][0][0][0], results[i][0][0][1], results[i][0][1][0], results[i][0][2][1]
            cv2.rectangle(img, (x, y), (w, h), (0, 255, 0), 3)
    output_folder_path = 'C:\\Users\\USER\\cs222\\course-project-team-8\\Bounding Box\\output_image'
    output_name = output_folder_path + name + '.png'
    cv2.imwrite(output_name, img)

find_word(text_image, 'hello')
    
