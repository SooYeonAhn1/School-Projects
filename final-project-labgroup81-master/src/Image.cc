#include "/home/vagrant/src/Final Project/final-project-labgroup81/includes/Image.hpp"
#include <vector>
#include <stdexcept>
#include <algorithm>

Image::Image(const std::string& filepath) {
    height = 0;
    width = 0;
    std::ifstream input_file(filepath);
    if (!input_file.good()) {
      throw std::runtime_error("file not found");
  }
    input_file >> *this;
    input_file.close();

}

Image::Image(Image& image) {
  height = image.height;
  width = image.width;
  original_image = image.original_image;
  processed_image = image.processed_image;
}

void Image::ToPPM(const std::string filename) const {
std::ofstream ofs{filename};

  ofs << "P3" << std::endl;
  ofs << width << " " << height << std::endl;
  ofs << "255" << std::endl;

  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      ofs << processed_image[row][col].GetRed() << std::endl;
      ofs << processed_image[row][col].GetGreen() << std::endl;
      ofs << processed_image[row][col].GetBlue() << std::endl;
    }
  }
}

void Image::RevertToOriginal(){
  processed_image = original_image;
}

Pixel* Image::GetProcessedPixelAt(size_t i, size_t j) {
  return &processed_image.at(i).at(j);
}

void Image::TestImage(int new_width, int new_height) {
  height = new_height;
  width = new_width;

  std::vector<std::vector<Pixel>> newguy(height); // size pixel vector
  for (int i = 0; i < height; i++) {
    newguy[i].resize(width);
  }
  float h = height;
  float w = width;
  float height_multiplier = 255 / h;
  float width_multiplier = 255 / w;
  for (int i = 0; i < height; i++) {
    int red = i * height_multiplier;
    int green_height = ((h - i)*height_multiplier) / 2;
    for (int j = 0; j < width; j++) {
      int blue = j * width_multiplier;
      int green_width = ((w - j)*width_multiplier) / 2;
      Pixel p(red, green_width + green_height, blue);
      newguy[i][j] = p;
    }
  }

  original_image = processed_image = newguy;
}

void Image::Grayscale() {
  int brightness;

  for(int i = 0; i < height; ++i) {
    for(int j = 0; j < width; ++j) {
      Pixel* processed_pixel = GetProcessedPixelAt(i, j);
      brightness = (processed_pixel->GetEnergy())/3;
      processed_pixel->SetRed(brightness);
      processed_pixel->SetGreen(brightness);
      processed_pixel->SetBlue(brightness);
    }
  }
}

void Image::Redscale() {
  for(int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      Pixel* processed_pixel = GetProcessedPixelAt(i, j);
      processed_pixel->SetBlue(0);
      processed_pixel->SetGreen(0);
    }
  }
}

void Image::Bluescale() {
for(int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      Pixel* processed_pixel = GetProcessedPixelAt(i, j);
      processed_pixel->SetRed(0);
      processed_pixel->SetGreen(0);
    }
  }
}

void Image::Greenscale() {
for(int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      Pixel* processed_pixel = GetProcessedPixelAt(i, j);
      processed_pixel->SetBlue(0);
      processed_pixel->SetRed(0);
    }
  }
}

void Image::Magentascale() {
for(int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      Pixel* processed_pixel = GetProcessedPixelAt(i, j);
      int magenta = (processed_pixel->GetBlue() + processed_pixel->GetRed()) / 2;
      processed_pixel->SetGreen(0);
      processed_pixel->SetRed(magenta);
      processed_pixel->SetBlue(magenta);
    }
  }
}

void Image::Yellowscale() {
for(int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      Pixel* pixel = GetProcessedPixelAt(i, j);
      int yellow = (pixel->GetRed() + pixel->GetGreen()) / 2;
      pixel->SetBlue(0);
      pixel->SetGreen(yellow);
      pixel->SetRed(yellow);
    }
  }
}

void Image::Cyanscale() {
for(int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      Pixel* pixel = GetProcessedPixelAt(i, j);
      int cyan = (pixel->GetBlue() + pixel->GetGreen()) / 2;
      pixel->SetRed(0);
      pixel->SetBlue(cyan);
      pixel->SetGreen(cyan);
    }
  }
}

void Image::Negative() {
  std::vector<std::vector<Pixel>> newguy(height); // size pixel vector
  for (int i = 0; i < height; i++) {
    newguy[i].resize(width);
  }

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      Pixel old = processed_image[i][j];
      Pixel p;
      p.SetRed(255 - old.GetRed());
      p.SetGreen(255 - old.GetGreen());
      p.SetBlue(255 - old.GetBlue());
      newguy[i][j] = p;
    }
  }

  processed_image = newguy;
}

void Image::Contrast(int to_contrast) {
  if (to_contrast < -255 || to_contrast > 255) { // throws runtime error if_contrast is out of range
    throw std::runtime_error("input value should be between +/- 255");
  }
  int new_red; // calculated red value
  int new_blue; // calculated blue value
  int new_green; // calculated green value
  int mid = 382;
  Pixel* pix; // saves copy of pixel to decrease runtime
  if (to_contrast > 0) {
    for (int row = 0; row < height; ++row) {
      for (int col = 0; col < width; ++col) {
        pix = GetProcessedPixelAt(row, col);
        setColorVal(new_red, new_green, new_blue, pix);
        if (mid < pix->GetEnergy()) {
          calculateColor(new_red, new_green, new_blue, to_contrast);
        } else { // mid >=  pix.GetEnergy()
          calculateColor(new_red, new_green, new_blue, -to_contrast);
        }
        pix->SetRed(new_red);
        pix->SetGreen(new_green);
        pix->SetBlue(new_blue);
      }
    }
  } else if (to_contrast < 0) {
    int midval = 255 / 2;
    for (int row = 0; row < height; ++row) {
      for (int col = 0; col < width; ++col) {
        pix = GetProcessedPixelAt(row, col);
        setColorVal(new_red, new_green, new_blue, pix);
        if (mid < pix->GetEnergy()) {
          calculateColor(new_red, new_green, new_blue, to_contrast);
          if (new_red < midval) {
            pix->SetRed(midval);
          } else {
            pix->SetRed(new_red);
          }
          if (new_blue < midval) {
            pix->SetBlue(midval);
          } else {
            pix->SetBlue(new_blue);
          }
          if (new_green < midval) {
            pix->SetGreen(midval);
          } else {
            pix->SetGreen(new_green);
          }
        } else { // mid >= pix.GetEnergy()
          calculateColor(new_red, new_green, new_blue, -to_contrast);
          if (new_red > midval) {
            pix->SetRed(midval);
          } else {
            pix->SetRed(new_red);
          }
          if (new_blue > midval) {
            pix->SetBlue(midval);
          } else {
            pix->SetBlue(new_blue);
          }
          if (new_green > midval) {
            pix->SetGreen(midval);
          } else {
            pix->SetGreen(new_green);
          }
        }
      }
    }
  }
}

// contrast helper function
void Image::calculateColor(int& new_red, int& new_green, int& new_blue, int to_contrast) {
  new_red = new_red + to_contrast;
  new_blue = new_blue + to_contrast;          
  new_green = new_green + to_contrast;
  new_red = std::min(std::max(new_red, 0),255);
  new_blue = std::min(std::max(new_blue, 0),255);
  new_green = std::min(std::max(new_green, 0),255);
}

// contrast helper function
void Image::setColorVal(int& new_red, int& new_green, int& new_blue, Pixel* pix) {
  new_red = pix->GetRed();
  new_blue = pix->GetBlue();         
  new_green = pix->GetGreen();
}

void Image::Merge(Image& to_merge) {
  if (height != to_merge.GetHeight() || width != to_merge.GetWidth()) {
    throw std::runtime_error("pictures do not fit with one another");
  }

  std::vector<std::vector<Pixel>> newguy(height); // size pixel vector
  for (int i = 0; i < height; i++) {
    newguy[i].resize(width);
  }

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (i%2 == 1 && j%2 == 1) {
        newguy[i][j] = to_merge.GetProcessed()[i][j];
      } else {
        newguy[i][j] = processed_image[i][j];
      }
    }
  }

  processed_image = newguy;
}

void Image::Blur(int to_blur) {
  if (to_blur > height || to_blur > width || to_blur < 1) {
    throw std::runtime_error("to_blur should be between 1 - height/width of the image");
  }
  if (to_blur == 1) {
    return;
  }
  Pixel* pix;
  int total_red = 0;
  int total_green = 0;
  int total_blue = 0;
  int blur_red = 0;
  int blur_green = 0;
  int blur_blue = 0;
  int remaining_col = 0;
  int remaining_row = 0;
  int temp_height = height - (height % to_blur);
  int loc = 0;
  while (loc + to_blur <= width) {
    total_red = 0;
    total_green = 0;
    total_blue = 0;
    for (int i = 0; i < temp_height; i++) {
      for (int j = loc; j < loc + to_blur; j++) {
        pix = GetProcessedPixelAt(i, j);
        total_red += pix->GetRed();
        total_green += pix->GetGreen();
        total_blue += pix->GetBlue();
      }
      if ((i + 1) % to_blur == 0) {
        blur_red = static_cast<int> (total_red / (to_blur * to_blur));
        blur_green = static_cast<int> (total_green / (to_blur * to_blur));
        blur_blue = static_cast<int> (total_blue / (to_blur * to_blur));
        for (int row = i - to_blur + 1; row <= i; row++) {
          for (int col = loc; col < loc + to_blur; col++) {
            pix = GetProcessedPixelAt(row, col);
            pix->SetBlue(blur_blue);
            pix->SetGreen(blur_green);
            pix->SetRed(blur_red);
          }
        }
        total_red = 0;
        total_green = 0;
        total_blue = 0;
      }
    }
    loc += to_blur;
  }

  // remaining pixels on lower horizontal
  if (temp_height != height) {
    int temp_loc = 0;
    while (temp_loc + to_blur <= width) {
      total_red = 0;
      total_green = 0;
      total_blue = 0;
      for (int i = temp_height; i < height; i++) {
        for (int j = temp_loc; j < temp_loc + to_blur; j++) {
          pix = GetProcessedPixelAt(i, j);
          total_red += pix->GetRed();
          total_green += pix->GetGreen();
          total_blue += pix->GetBlue();
        }
      }
      blur_red = static_cast<int> (total_red / (to_blur * (height - temp_height)));
      blur_green = static_cast<int> (total_green / (to_blur * (height - temp_height)));
      blur_blue = static_cast<int> (total_blue / (to_blur * (height - temp_height)));
      for (int i = temp_height; i < height; i++) {
        for (int j = temp_loc; j < temp_loc + to_blur; j++) {
          pix = GetProcessedPixelAt(i, j);
          pix->SetBlue(blur_blue);
          pix->SetGreen(blur_green);
          pix->SetRed(blur_red);
        }
      }
      temp_loc += to_blur;
    }
    remaining_col = temp_loc;
  }
  // remaining pixels on left vertical
  if (loc + to_blur > width && loc != width) {
    int temp_loc = 0;
    while (temp_loc + to_blur <= height) {
      total_red = 0;
      total_green = 0;
      total_blue = 0;
      for (int i = loc; i < width; i++) {
        for (int j = temp_loc; j < temp_loc + to_blur; j++) {
          pix = GetProcessedPixelAt(j, i);
          total_red += pix->GetRed();
          total_green += pix->GetGreen();
          total_blue += pix->GetBlue();
        }
      }
      blur_red = static_cast<int> (total_red / (to_blur * (width - loc)));
      blur_green = static_cast<int> (total_green / (to_blur * (width - loc)));
      blur_blue = static_cast<int> (total_blue / (to_blur * (width - loc)));
      for (int i = loc; i < width; i++) {
        for (int j = temp_loc; j < temp_loc + to_blur; j++) {
          pix = GetProcessedPixelAt(j, i);
          pix->SetBlue(blur_blue);
          pix->SetGreen(blur_green);
          pix->SetRed(blur_red);
        }
      }
      temp_loc += to_blur;
    }
    remaining_row = temp_loc;
  }

  // remaining corner pixels
  if (remaining_row != 0 || remaining_col != 0) {
    total_red = 0;
    total_green = 0;
    total_blue = 0;
    for (int i = remaining_row; i < height; i++) {
      for (int j = remaining_col; j < width; j++) {
          pix = GetProcessedPixelAt(i, j);
          total_red += pix->GetRed();
          total_green += pix->GetGreen();
          total_blue += pix->GetBlue();
      }
    }
    blur_red = static_cast<int> (total_red / ((height - remaining_row) * (width - remaining_col)));
    blur_green = static_cast<int> (total_green / ((height - remaining_row) * (width - remaining_col)));
    blur_blue = static_cast<int> (total_blue / ((height - remaining_row) * (width - remaining_col)));
    for (int i = remaining_row; i < height; i++) {
      for (int j = remaining_col; j < width; j++) {
          pix = GetProcessedPixelAt(i, j);
          pix->SetBlue(blur_blue);
          pix->SetGreen(blur_green);
          pix->SetRed(blur_red);
      }
    }
  }
}

void Image::HorizontalFlip() {
  std::vector<std::vector<Pixel>> newguy(height); // size pixel vector
  for (int i = 0; i < height; i++) {
    newguy[i].resize(width);
  }

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      newguy[i][j] = processed_image[height - 1 - i][j];
    }
  }
  processed_image = newguy;
}

void Image::VerticalFlip() {
  std::vector<std::vector<Pixel>> newguy(height); // size pixel vector
  for (int i = 0; i < height; i++) {
    newguy[i].resize(width);
  }

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      newguy[i][j] = processed_image[i][width - 1 - j];
    }
  }
  processed_image = newguy;
}

//creates 2d vector image from ppm file
std::istream& operator>>(std::istream& is, Image& image) {
     //image.Clear();
     std::string line;
  
    getline(is, line); // ignore magic number line

    getline(is, line); // check to see if there's a comment line
    if (line[0] == '#') {
        getline(is, line);
    }

    int space = line.find_first_of(' '); // parse width and height
    image.width = std::stoi(line.substr(0, space));
    image.height = std::stoi(line.substr(space + 1));

    getline(is, line); // get max color value
    int max_color = std::stoi(line);
    max_color--;

    std::vector<std::vector<Pixel>> newguy(image.height); // size pixel vector
    for (int i = 0; i < image.height; i++) {
        newguy[i].resize(image.width);
    }
 
    for (int row = 0; row < image.height; row++) { // fill pixel vector
        for (int col = 0; col < image.width; col++) {
            getline(is, line);
            int red_ = std::stoi(line);
            getline(is, line);
            int green_ = std::stoi(line);
            getline(is, line);
            int blue_ = std::stoi(line);

            Pixel p(red_, green_, blue_);
            newguy[row][col] = p;
        }
    }

    image.original_image = newguy;
    image.processed_image = newguy;
 
    return is;
}

//turns 2d vector image to ppm format
std::ostream& operator<<(std::ostream& os, const Image& image) {
  os << "P3" << std::endl;
  os << image.width << " " << image.height << std::endl;
  os << "255" << std::endl;

  for (int row = 0; row < image.height; row++) {
    for (int col = 0; col < image.width; col++) {
      os << image.processed_image[row][col].GetRed() << std::endl;
      os << image.processed_image[row][col].GetGreen() << std::endl;
      os << image.processed_image[row][col].GetBlue() << std::endl;
    }
  }
  return os;
}

void Image::Brighten(int to_brighten) {
  for(int i = 0; i < height; ++i) {
    for(int j = 0; j < width; ++j) {
      Pixel* processed_pixel = GetProcessedPixelAt(i, j);
      int red = processed_pixel->GetRed();
      int green = processed_pixel->GetGreen();
      int blue = processed_pixel->GetBlue();

      int newred = red + to_brighten;
      int newgreen = green + to_brighten;
      int newblue = blue + to_brighten;
      processed_pixel->SetRed(std::min(std::max(newred, 0),255));
      processed_pixel->SetGreen(std::min(std::max(newgreen, 0),255));
      processed_pixel->SetBlue(std::min(std::max(newblue, 0),255));
    }
  }
}