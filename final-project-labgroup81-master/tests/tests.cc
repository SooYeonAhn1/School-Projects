#ifndef CATCH_CONFIG_MAIN
#define CATCH_CONFIG_MAIN
#endif

#include <catch/catch.hpp>
#include <string>

#include "/home/vagrant/src/final-project-labgroup81/includes/Image.hpp"


TEST_CASE("", "") {
}

TEST_CASE("Brighten") {
  Image test("unit_test.ppm");
  test.Brighten(20);
  REQUIRE(test.GetProcessedPixelAt(0,0)->GetRed()==20);
  REQUIRE(test.GetProcessedPixelAt(0,0)->GetGreen()==20);
  REQUIRE(test.GetProcessedPixelAt(0,0)->GetBlue()==20);

  REQUIRE(test.GetProcessedPixelAt(0,1)->GetRed()==255);
  REQUIRE(test.GetProcessedPixelAt(0,1)->GetGreen()==255);
  REQUIRE(test.GetProcessedPixelAt(0,1)->GetBlue()==255);

  REQUIRE(test.GetProcessedPixelAt(1,0)->GetRed()==147);
  REQUIRE(test.GetProcessedPixelAt(1,0)->GetGreen()==147);
  REQUIRE(test.GetProcessedPixelAt(1,0)->GetBlue()==147);

  REQUIRE(test.GetProcessedPixelAt(1,1)->GetRed()==33);
  REQUIRE(test.GetProcessedPixelAt(1,1)->GetGreen()==120);
  REQUIRE(test.GetProcessedPixelAt(1,1)->GetBlue()==255); 
}

TEST_CASE("testing contrast","[contrast]") {
  SECTION("out of range exception") {
    Image test("unit_test.ppm");
    REQUIRE_THROWS(test.Contrast(256));
    REQUIRE_THROWS(test.Contrast(-256));
  };

  SECTION("add 100") {
    Image test("unit_test.ppm");
    test.Contrast(100);
    REQUIRE(test.GetProcessedPixelAt(0,0)->GetRed() == 0);
    REQUIRE(test.GetProcessedPixelAt(0,0)->GetGreen() == 0);
    REQUIRE(test.GetProcessedPixelAt(0,0)->GetBlue() == 0);

    REQUIRE(test.GetProcessedPixelAt(0,1)->GetRed() == 255);
    REQUIRE(test.GetProcessedPixelAt(0,1)->GetGreen() == 255);
    REQUIRE(test.GetProcessedPixelAt(0,1)->GetBlue() == 255);

    REQUIRE(test.GetProcessedPixelAt(1,0)->GetRed() == 27);
    REQUIRE(test.GetProcessedPixelAt(1,0)->GetGreen() == 27);
    REQUIRE(test.GetProcessedPixelAt(1,0)->GetBlue() == 27);

    REQUIRE(test.GetProcessedPixelAt(1,1)->GetRed() == 0);
    REQUIRE(test.GetProcessedPixelAt(1,1)->GetGreen() == 0);
    REQUIRE(test.GetProcessedPixelAt(1,1)->GetBlue() == 148);
  };

  SECTION("subtract 100") {
    Image test("unit_test.ppm");
    test.Contrast(-100);
    REQUIRE(test.GetProcessedPixelAt(0,0)->GetRed() == 100);
    REQUIRE(test.GetProcessedPixelAt(0,0)->GetGreen() == 100);
    REQUIRE(test.GetProcessedPixelAt(0,0)->GetBlue() == 100);

    REQUIRE(test.GetProcessedPixelAt(0,1)->GetRed() == 155);
    REQUIRE(test.GetProcessedPixelAt(0,1)->GetGreen() == 155);
    REQUIRE(test.GetProcessedPixelAt(0,1)->GetBlue() == 155);

    REQUIRE(test.GetProcessedPixelAt(1,0)->GetRed() == 127);
    REQUIRE(test.GetProcessedPixelAt(1,0)->GetGreen() == 127);
    REQUIRE(test.GetProcessedPixelAt(1,0)->GetBlue() == 127);

    REQUIRE(test.GetProcessedPixelAt(1,1)->GetRed() == 113);
    REQUIRE(test.GetProcessedPixelAt(1,1)->GetGreen() == 127);
    REQUIRE(test.GetProcessedPixelAt(1,1)->GetBlue() == 127);
  };
}

TEST_CASE("testing blur", "[blur]") {
  SECTION("Exceptions") {
    Image test("unit_test.ppm");
    REQUIRE_THROWS(test.Blur(0));
    REQUIRE_THROWS(test.Blur(4));
  };

  SECTION("param 2") {
    Image test("unit_test.ppm");
    test.Blur(2);
    REQUIRE(test.GetProcessedPixelAt(0,0)->GetRed() == 98);
    REQUIRE(test.GetProcessedPixelAt(0,0)->GetGreen() == 120);
    REQUIRE(test.GetProcessedPixelAt(0,0)->GetBlue() == 157);

    REQUIRE(test.GetProcessedPixelAt(0,1)->GetRed() == 98);
    REQUIRE(test.GetProcessedPixelAt(0,1)->GetGreen() == 120);
    REQUIRE(test.GetProcessedPixelAt(0,1)->GetBlue() == 157);

    REQUIRE(test.GetProcessedPixelAt(1,0)->GetRed() == 98);
    REQUIRE(test.GetProcessedPixelAt(1,0)->GetGreen() == 120);
    REQUIRE(test.GetProcessedPixelAt(1,0)->GetBlue() == 157);

    REQUIRE(test.GetProcessedPixelAt(1,1)->GetRed() == 98);
    REQUIRE(test.GetProcessedPixelAt(1,1)->GetGreen() == 120);
    REQUIRE(test.GetProcessedPixelAt(1,1)->GetBlue() == 157);
  };

  SECTION("param 1") {
    Image test("unit_test.ppm");
    test.Blur(1);
    REQUIRE(test.GetProcessedPixelAt(0,0)->GetRed() == 0);
    REQUIRE(test.GetProcessedPixelAt(0,0)->GetGreen() == 0);
    REQUIRE(test.GetProcessedPixelAt(0,0)->GetBlue() == 0);

    REQUIRE(test.GetProcessedPixelAt(0,1)->GetRed() == 255);
    REQUIRE(test.GetProcessedPixelAt(0,1)->GetGreen() == 255);
    REQUIRE(test.GetProcessedPixelAt(0,1)->GetBlue() == 255);

    REQUIRE(test.GetProcessedPixelAt(1,0)->GetRed() == 127);
    REQUIRE(test.GetProcessedPixelAt(1,0)->GetGreen() == 127);
    REQUIRE(test.GetProcessedPixelAt(1,0)->GetBlue() == 127);

    REQUIRE(test.GetProcessedPixelAt(1,1)->GetRed() == 13);
    REQUIRE(test.GetProcessedPixelAt(1,1)->GetGreen() == 100);
    REQUIRE(test.GetProcessedPixelAt(1,1)->GetBlue() == 248);
  };
}

TEST_CASE("testing flip", "[flip]") {
  SECTION("Vertical flip") {
    Image test("unit_test.ppm");
    test.VerticalFlip();
    REQUIRE(test.GetProcessedPixelAt(0,0)->GetRed() == 255);
    REQUIRE(test.GetProcessedPixelAt(0,0)->GetGreen() == 255);
    REQUIRE(test.GetProcessedPixelAt(0,0)->GetBlue() == 255);

    REQUIRE(test.GetProcessedPixelAt(0,1)->GetRed() == 0);
    REQUIRE(test.GetProcessedPixelAt(0,1)->GetGreen() == 0);
    REQUIRE(test.GetProcessedPixelAt(0,1)->GetBlue() == 0);

    REQUIRE(test.GetProcessedPixelAt(1,0)->GetRed() == 13);
    REQUIRE(test.GetProcessedPixelAt(1,0)->GetGreen() == 100);
    REQUIRE(test.GetProcessedPixelAt(1,0)->GetBlue() == 248);

    REQUIRE(test.GetProcessedPixelAt(1,1)->GetRed() == 127);
    REQUIRE(test.GetProcessedPixelAt(1,1)->GetGreen() == 127);
    REQUIRE(test.GetProcessedPixelAt(1,1)->GetBlue() == 127);
  };

  SECTION("Horizontal flip") {
    Image test("unit_test.ppm");
    test.HorizontalFlip();
    REQUIRE(test.GetProcessedPixelAt(0,0)->GetRed() == 127);
    REQUIRE(test.GetProcessedPixelAt(0,0)->GetGreen() == 127);
    REQUIRE(test.GetProcessedPixelAt(0,0)->GetBlue() == 127);

    REQUIRE(test.GetProcessedPixelAt(0,1)->GetRed() == 13);
    REQUIRE(test.GetProcessedPixelAt(0,1)->GetGreen() == 100);
    REQUIRE(test.GetProcessedPixelAt(0,1)->GetBlue() == 248);

    REQUIRE(test.GetProcessedPixelAt(1,0)->GetRed() == 0);
    REQUIRE(test.GetProcessedPixelAt(1,0)->GetGreen() == 0);
    REQUIRE(test.GetProcessedPixelAt(1,0)->GetBlue() == 0);

    REQUIRE(test.GetProcessedPixelAt(1,1)->GetRed() == 255);
    REQUIRE(test.GetProcessedPixelAt(1,1)->GetGreen() == 255);
    REQUIRE(test.GetProcessedPixelAt(1,1)->GetBlue() == 255);
  };
}

TEST_CASE("testing RevertToOriginal", "[RevertToOriginal]") {
  Image test("unit_test.ppm");
  test.Contrast(-50);
  test.Contrast(30);
  REQUIRE_FALSE(test.GetProcessedPixelAt(0,0)->GetRed() == 0);
  REQUIRE_FALSE(test.GetProcessedPixelAt(0,0)->GetGreen() == 0);
  REQUIRE_FALSE(test.GetProcessedPixelAt(0,0)->GetBlue() == 0);

  REQUIRE_FALSE(test.GetProcessedPixelAt(0,1)->GetRed() == 255);
  REQUIRE_FALSE(test.GetProcessedPixelAt(0,1)->GetGreen() == 255);
  REQUIRE_FALSE(test.GetProcessedPixelAt(0,1)->GetBlue() == 255);

  REQUIRE_FALSE(test.GetProcessedPixelAt(1,0)->GetRed() == 127);
  REQUIRE_FALSE(test.GetProcessedPixelAt(1,0)->GetGreen() == 127);
  REQUIRE_FALSE(test.GetProcessedPixelAt(1,0)->GetBlue() == 127);

  REQUIRE_FALSE(test.GetProcessedPixelAt(1,1)->GetRed() == 13);
  REQUIRE_FALSE(test.GetProcessedPixelAt(1,1)->GetGreen() == 100);
  REQUIRE_FALSE(test.GetProcessedPixelAt(1,1)->GetBlue() == 248);

  test.RevertToOriginal();
  REQUIRE(test.GetProcessedPixelAt(0,0)->GetRed() == 0);
  REQUIRE(test.GetProcessedPixelAt(0,0)->GetGreen() == 0);
  REQUIRE(test.GetProcessedPixelAt(0,0)->GetBlue() == 0);

  REQUIRE(test.GetProcessedPixelAt(0,1)->GetRed() == 255);
  REQUIRE(test.GetProcessedPixelAt(0,1)->GetGreen() == 255);
  REQUIRE(test.GetProcessedPixelAt(0,1)->GetBlue() == 255);

  REQUIRE(test.GetProcessedPixelAt(1,0)->GetRed() == 127);
  REQUIRE(test.GetProcessedPixelAt(1,0)->GetGreen() == 127);
  REQUIRE(test.GetProcessedPixelAt(1,0)->GetBlue() == 127);

  REQUIRE(test.GetProcessedPixelAt(1,1)->GetRed() == 13);
  REQUIRE(test.GetProcessedPixelAt(1,1)->GetGreen() == 100);
  REQUIRE(test.GetProcessedPixelAt(1,1)->GetBlue() == 248);
}

TEST_CASE("testing redscale", "[redscale]") {
  Image test("unit_test.ppm");
  test.Redscale();

  REQUIRE(test.GetProcessedPixelAt(0, 0)->GetRed() == 0);
  REQUIRE(test.GetProcessedPixelAt(0, 0)->GetGreen() == 0);
  REQUIRE(test.GetProcessedPixelAt(0, 0)->GetBlue() == 0);

  REQUIRE(test.GetProcessedPixelAt(0, 1)->GetRed() == 255);
  REQUIRE(test.GetProcessedPixelAt(0, 1)->GetGreen() == 0);
  REQUIRE(test.GetProcessedPixelAt(0, 1)->GetBlue() == 0);

  REQUIRE(test.GetProcessedPixelAt(1, 0)->GetRed() == 127);
  REQUIRE(test.GetProcessedPixelAt(1, 0)->GetGreen() == 0);
  REQUIRE(test.GetProcessedPixelAt(1, 0)->GetBlue() == 0);

  REQUIRE(test.GetProcessedPixelAt(1, 1)->GetRed() == 13);
  REQUIRE(test.GetProcessedPixelAt(1, 1)->GetGreen() == 0);
  REQUIRE(test.GetProcessedPixelAt(1, 1)->GetBlue() == 0);
}

TEST_CASE("testing greenscale", "[greenscale]") {
  Image test("unit_test.ppm");
  test.Greenscale();

  REQUIRE(test.GetProcessedPixelAt(0, 0)->GetRed() == 0);
  REQUIRE(test.GetProcessedPixelAt(0, 0)->GetGreen() == 0);
  REQUIRE(test.GetProcessedPixelAt(0, 0)->GetBlue() == 0);

  REQUIRE(test.GetProcessedPixelAt(0, 1)->GetRed() == 0);
  REQUIRE(test.GetProcessedPixelAt(0, 1)->GetGreen() == 255);
  REQUIRE(test.GetProcessedPixelAt(0, 1)->GetBlue() == 0);

  REQUIRE(test.GetProcessedPixelAt(1, 0)->GetRed() == 0);
  REQUIRE(test.GetProcessedPixelAt(1, 0)->GetGreen() == 127);
  REQUIRE(test.GetProcessedPixelAt(1, 0)->GetBlue() == 0);

  REQUIRE(test.GetProcessedPixelAt(1, 1)->GetRed() == 0);
  REQUIRE(test.GetProcessedPixelAt(1, 1)->GetGreen() == 100);
  REQUIRE(test.GetProcessedPixelAt(1, 1)->GetBlue() == 0);
}

TEST_CASE("testing bluescale", "[bluescale]") {
  Image test("unit_test.ppm");
  test.Bluescale();

  REQUIRE(test.GetProcessedPixelAt(0, 0)->GetRed() == 0);
  REQUIRE(test.GetProcessedPixelAt(0, 0)->GetGreen() == 0);
  REQUIRE(test.GetProcessedPixelAt(0, 0)->GetBlue() == 0);

  REQUIRE(test.GetProcessedPixelAt(0, 1)->GetRed() == 0);
  REQUIRE(test.GetProcessedPixelAt(0, 1)->GetGreen() == 0);
  REQUIRE(test.GetProcessedPixelAt(0, 1)->GetBlue() == 255);

  REQUIRE(test.GetProcessedPixelAt(1, 0)->GetRed() == 0);
  REQUIRE(test.GetProcessedPixelAt(1, 0)->GetGreen() == 0);
  REQUIRE(test.GetProcessedPixelAt(1, 0)->GetBlue() == 127);

  REQUIRE(test.GetProcessedPixelAt(1, 1)->GetRed() == 0);
  REQUIRE(test.GetProcessedPixelAt(1, 1)->GetGreen() == 0);
  REQUIRE(test.GetProcessedPixelAt(1, 1)->GetBlue() == 248);
}

TEST_CASE("testing magentascale", "[magentascale]") {
  Image test("unit_test.ppm");
  test.Magentascale();

  REQUIRE(test.GetProcessedPixelAt(0, 0)->GetRed() == 0);
  REQUIRE(test.GetProcessedPixelAt(0, 0)->GetGreen() == 0);
  REQUIRE(test.GetProcessedPixelAt(0, 0)->GetBlue() == 0);

  REQUIRE(test.GetProcessedPixelAt(0, 1)->GetRed() == 255);
  REQUIRE(test.GetProcessedPixelAt(0, 1)->GetGreen() == 0);
  REQUIRE(test.GetProcessedPixelAt(0, 1)->GetBlue() == 255);

  REQUIRE(test.GetProcessedPixelAt(1, 0)->GetRed() == 127);
  REQUIRE(test.GetProcessedPixelAt(1, 0)->GetGreen() == 0);
  REQUIRE(test.GetProcessedPixelAt(1, 0)->GetBlue() == 127);

  REQUIRE(test.GetProcessedPixelAt(1, 1)->GetRed() == 130);
  REQUIRE(test.GetProcessedPixelAt(1, 1)->GetGreen() == 0);
  REQUIRE(test.GetProcessedPixelAt(1, 1)->GetBlue() == 130);
}

TEST_CASE("testing yellowscale", "[yellowscale]") {
  Image test("unit_test.ppm");
  test.Yellowscale();

  REQUIRE(test.GetProcessedPixelAt(0, 0)->GetRed() == 0);
  REQUIRE(test.GetProcessedPixelAt(0, 0)->GetGreen() == 0);
  REQUIRE(test.GetProcessedPixelAt(0, 0)->GetBlue() == 0);

  REQUIRE(test.GetProcessedPixelAt(0, 1)->GetRed() == 255);
  REQUIRE(test.GetProcessedPixelAt(0, 1)->GetGreen() == 255);
  REQUIRE(test.GetProcessedPixelAt(0, 1)->GetBlue() == 0);

  REQUIRE(test.GetProcessedPixelAt(1, 0)->GetRed() == 127);
  REQUIRE(test.GetProcessedPixelAt(1, 0)->GetGreen() == 127);
  REQUIRE(test.GetProcessedPixelAt(1, 0)->GetBlue() == 0);

  REQUIRE(test.GetProcessedPixelAt(1, 1)->GetRed() == 56);
  REQUIRE(test.GetProcessedPixelAt(1, 1)->GetGreen() == 56);
  REQUIRE(test.GetProcessedPixelAt(1, 1)->GetBlue() == 0);
}

TEST_CASE("testing cyanscale", "[cyanscale]") {
  Image test("unit_test.ppm");
  test.Cyanscale();

  REQUIRE(test.GetProcessedPixelAt(0, 0)->GetRed() == 0);
  REQUIRE(test.GetProcessedPixelAt(0, 0)->GetGreen() == 0);
  REQUIRE(test.GetProcessedPixelAt(0, 0)->GetBlue() == 0);

  REQUIRE(test.GetProcessedPixelAt(0, 1)->GetRed() == 0);
  REQUIRE(test.GetProcessedPixelAt(0, 1)->GetGreen() == 255);
  REQUIRE(test.GetProcessedPixelAt(0, 1)->GetBlue() == 255);

  REQUIRE(test.GetProcessedPixelAt(1, 0)->GetRed() == 0);
  REQUIRE(test.GetProcessedPixelAt(1, 0)->GetGreen() == 127);
  REQUIRE(test.GetProcessedPixelAt(1, 0)->GetBlue() == 127);

  REQUIRE(test.GetProcessedPixelAt(1, 1)->GetRed() == 0);
  REQUIRE(test.GetProcessedPixelAt(1, 1)->GetGreen() == 174);
  REQUIRE(test.GetProcessedPixelAt(1, 1)->GetBlue() == 174);
}

TEST_CASE("testing negative", "[negative]") {
  Image test("unit_test.ppm");
  test.Negative();

  REQUIRE(test.GetProcessedPixelAt(0, 0)->GetRed() == 255);
  REQUIRE(test.GetProcessedPixelAt(0, 0)->GetGreen() == 255);
  REQUIRE(test.GetProcessedPixelAt(0, 0)->GetBlue() == 255);

  REQUIRE(test.GetProcessedPixelAt(0, 1)->GetRed() == 0);
  REQUIRE(test.GetProcessedPixelAt(0, 1)->GetGreen() == 0);
  REQUIRE(test.GetProcessedPixelAt(0, 1)->GetBlue() == 0);

  REQUIRE(test.GetProcessedPixelAt(1, 0)->GetRed() == 128);
  REQUIRE(test.GetProcessedPixelAt(1, 0)->GetGreen() == 128);
  REQUIRE(test.GetProcessedPixelAt(1, 0)->GetBlue() == 128);

  REQUIRE(test.GetProcessedPixelAt(1, 1)->GetRed() == 242);
  REQUIRE(test.GetProcessedPixelAt(1, 1)->GetGreen() == 155);
  REQUIRE(test.GetProcessedPixelAt(1, 1)->GetBlue() == 7);
}

TEST_CASE("testing grayscale", "[grayscale]") {
  Image test("unit_test.ppm");
  test.Grayscale();

  REQUIRE(test.GetProcessedPixelAt(0, 0)->GetRed() == 0);
  REQUIRE(test.GetProcessedPixelAt(0, 0)->GetGreen() == 0);
  REQUIRE(test.GetProcessedPixelAt(0, 0)->GetBlue() == 0);

  REQUIRE(test.GetProcessedPixelAt(0, 1)->GetRed() == 255);
  REQUIRE(test.GetProcessedPixelAt(0, 1)->GetGreen() == 255);
  REQUIRE(test.GetProcessedPixelAt(0, 1)->GetBlue() == 255);

  REQUIRE(test.GetProcessedPixelAt(1, 0)->GetRed() == 127);
  REQUIRE(test.GetProcessedPixelAt(1, 0)->GetGreen() == 127);
  REQUIRE(test.GetProcessedPixelAt(1, 0)->GetBlue() == 127);

  REQUIRE(test.GetProcessedPixelAt(1, 1)->GetRed() == 120);
  REQUIRE(test.GetProcessedPixelAt(1, 1)->GetGreen() == 120);
  REQUIRE(test.GetProcessedPixelAt(1, 1)->GetBlue() == 120);
}

TEST_CASE("testing merge", "[merge]") {
  SECTION("exception") {
    Image test("unit_test.ppm");
    Image ocean("ocean.ppm");
    REQUIRE_THROWS(test.Merge(ocean));
    REQUIRE_THROWS(ocean.Merge(test));

  }
  SECTION("param 1") {
    Image test("unit_test.ppm");
    Image test2("unit_test_2.ppm");
    test.Merge(test2);

    REQUIRE(test.GetProcessedPixelAt(0, 0)->GetRed() == 0);
    REQUIRE(test.GetProcessedPixelAt(0, 0)->GetGreen() == 0);
    REQUIRE(test.GetProcessedPixelAt(0, 0)->GetBlue() == 0);

    REQUIRE(test.GetProcessedPixelAt(0, 1)->GetRed() == 255);
    REQUIRE(test.GetProcessedPixelAt(0, 1)->GetGreen() == 255);
    REQUIRE(test.GetProcessedPixelAt(0, 1)->GetBlue() == 255);

    REQUIRE(test.GetProcessedPixelAt(1, 0)->GetRed() == 127);
    REQUIRE(test.GetProcessedPixelAt(1, 0)->GetGreen() == 127);
    REQUIRE(test.GetProcessedPixelAt(1, 0)->GetBlue() == 127);

    REQUIRE(test.GetProcessedPixelAt(1, 1)->GetRed() == 130);
    REQUIRE(test.GetProcessedPixelAt(1, 1)->GetGreen() == 100);
    REQUIRE(test.GetProcessedPixelAt(1, 1)->GetBlue() == 248);
  }
  SECTION("Param 2") {
    Image test("unit_test.ppm");
    Image test2("unit_test_2.ppm");
    test2.Merge(test);

    REQUIRE(test2.GetProcessedPixelAt(0, 0)->GetRed() == 40);
    REQUIRE(test2.GetProcessedPixelAt(0, 0)->GetGreen() == 40);
    REQUIRE(test2.GetProcessedPixelAt(0, 0)->GetBlue() == 40);

    REQUIRE(test2.GetProcessedPixelAt(0, 1)->GetRed() == 0);
    REQUIRE(test2.GetProcessedPixelAt(0, 1)->GetGreen() == 255);
    REQUIRE(test2.GetProcessedPixelAt(0, 1)->GetBlue() == 255);

    REQUIRE(test2.GetProcessedPixelAt(1, 0)->GetRed() == 200);
    REQUIRE(test2.GetProcessedPixelAt(1, 0)->GetGreen() == 7);
    REQUIRE(test2.GetProcessedPixelAt(1, 0)->GetBlue() == 127);

    REQUIRE(test2.GetProcessedPixelAt(1, 1)->GetRed() == 13);
    REQUIRE(test2.GetProcessedPixelAt(1, 1)->GetGreen() == 100);
    REQUIRE(test2.GetProcessedPixelAt(1, 1)->GetBlue() == 248);
  }
}

TEST_CASE("Grayscale") {
  Image test("unit_test.ppm");
  test.Grayscale();
  REQUIRE(test.GetProcessedPixelAt(0,0)->GetRed()==0);
  REQUIRE(test.GetProcessedPixelAt(0,0)->GetGreen()==0);
  REQUIRE(test.GetProcessedPixelAt(0,0)->GetBlue()==0);

  REQUIRE(test.GetProcessedPixelAt(0,1)->GetRed()==255);
  REQUIRE(test.GetProcessedPixelAt(0,1)->GetGreen()==255);
  REQUIRE(test.GetProcessedPixelAt(0,1)->GetBlue()==255);

  REQUIRE(test.GetProcessedPixelAt(1,0)->GetRed()==127);
  REQUIRE(test.GetProcessedPixelAt(1,0)->GetGreen()==127);
  REQUIRE(test.GetProcessedPixelAt(1,0)->GetBlue()==127);

  REQUIRE(test.GetProcessedPixelAt(1,1)->GetRed()==120);
  REQUIRE(test.GetProcessedPixelAt(1,1)->GetGreen()==120);
  REQUIRE(test.GetProcessedPixelAt(1,1)->GetBlue()==120); 
}
