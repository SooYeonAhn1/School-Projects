#ifndef PIXEL_HPP
#define PIXEL_HPP

class Pixel {
public:
  Pixel() = default;

  Pixel(int r, int g, int b): red(r), green(g), blue(b) {
  }

  int GetRed() const { return red; }

  int GetGreen() const { return green; }

  int GetBlue() const { return blue; }

  void SetRed(int r) { red = r; }

  void SetGreen(int g) { green = g; }

  void SetBlue(int b) { blue = b; }

  int GetEnergy() {
      return red + green + blue;
  }

  int GetMaxColorValue() const { return maxColorValue; }

  

//   friend bool operator==(const Pixel& lhs, const Pixel& rhs) {
//     return lhs.red == rhs.red && lhs.green == rhs.green &&
//            lhs.blue == rhs.blue;

  

private:
  int red;
  int green;
  int blue;
  int maxColorValue = 255;
};

#endif