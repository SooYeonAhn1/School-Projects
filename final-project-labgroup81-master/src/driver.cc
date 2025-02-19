#include "Image.hpp"
#include "Pixel.hpp"

#include <iostream>
#include <fstream>

int main() {

Image merge_with;
merge_with.TestImage(507, 285);

Image ocean("ocean.ppm");

ocean.Merge(merge_with);
ocean.ToPPM("merged.ppm");

ocean.Contrast(20);
ocean.ToPPM("contrast_20");
ocean.RevertToOriginal();

ocean.Contrast(-20);
ocean.ToPPM("contrast_-20");
ocean.RevertToOriginal();

Image test;
test.TestImage(75, 75);

test.Grayscale();
test.ToPPM("grayscale.ppm");
test.RevertToOriginal();

test.Redscale();
test.ToPPM("redscale.ppm");
test.RevertToOriginal();

test.Greenscale();
test.ToPPM("greenscale.ppm");
test.RevertToOriginal();

test.Bluescale();
test.ToPPM("bluescale.ppm");
test.RevertToOriginal();

test.Magentascale();
test.ToPPM("magetnascale.ppm");
test.RevertToOriginal();

test.Yellowscale();
test.ToPPM("yellowscale.ppm");
test.RevertToOriginal();

test.Cyanscale();
test.ToPPM("Cyanscale.ppm");
test.RevertToOriginal();

test.Negative();
test.ToPPM("negative.ppm");
test.RevertToOriginal();

test.Contrast(15);
test.ToPPM("contrast_15.ppm");
test.RevertToOriginal();

test.Contrast(-15);
test.ToPPM("contrast_-15.ppm");
test.RevertToOriginal();

test.Brighten(50);
test.ToPPM("brighten_50.ppm");
test.RevertToOriginal();

test.Brighten(-50);
test.ToPPM("brighten_-50.ppm");
test.RevertToOriginal();

test.Blur(30);
test.ToPPM("blur_30.ppm");
test.RevertToOriginal();

test.VerticalFlip();
test.ToPPM("vertical_flip.ppm");
test.RevertToOriginal();

test.HorizontalFlip();
test.ToPPM("Horizontal_flip.ppm");
test.RevertToOriginal();

test.ToPPM("test.ppm");

std::cout << "\n" << "It is Finished" << std::endl;

return 0;
}