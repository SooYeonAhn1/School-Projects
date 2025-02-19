#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "Pixel.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class Image {
public:

  Image() = default;

  Image(const std::string& filepath);

  Image(Image& image);

  Image& operator=(const Image& image);

  ~Image() = default;

  void ToPPM(const std::string filename) const; // X

  void RevertToOriginal(); // X

  void TestImage(int height, int width);

  Pixel* GetProcessedPixelAt(size_t i, size_t j); // X

  int GetHeight() {
    return height;
  }

  int GetWidth() {
    return width;
  }

  std::vector<std::vector<Pixel>> GetOriginal() {
    return original_image;
  }

  std::vector<std::vector<Pixel>> GetProcessed() {
    return processed_image;
  }
///////////////// functions that will modify processed_image////////////////
  void Grayscale(); // X

  void Bluescale(); // X

  void Redscale(); // X

  void Greenscale(); // X

  void Magentascale();

  void Yellowscale();

  void Cyanscale();

  void Negative();

  void Contrast(int to_contrast);

  void Brighten(int to_brighten);

  void Merge(Image& to_merge);

  void Blur(int to_blur);

  void HorizontalFlip();

  void VerticalFlip();

  
///////////////////////////////////////////////////////////////////////////////

  friend std::istream& operator>>(std::istream& is, Image& image); // X
//creates 2d vector image from ppm file

  friend std::ostream& operator<<(std::ostream& os, const Image& image); // X
//turns 2d vector image to ppm format

//Mirror?
//crop?
private:

  int height;

  int width;

  std::vector<std::vector<Pixel> > original_image;

  std::vector<std::vector<Pixel> > processed_image;

// will follow PPM format as in seam carver, 
// private helper functions (contrast)
  void calculateColor(int& new_red, int& new_green, int& new_blue, int to_contrast);
  void setColorVal(int& new_red, int& new_green, int& new_blue, Pixel* pix);
};


#endif