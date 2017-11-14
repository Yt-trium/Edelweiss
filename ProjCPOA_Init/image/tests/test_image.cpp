#include <iostream>

#include "gradientsobel.h"
#include "image2d.h"
#include "image2grey.h"
#include "image2rgb.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(test_image, cstr)
{
    Image2D<int> i1(800, 600);
    Image2D<int> i2();
    // Image2D<int> i3(i1);
}

TEST(test_image, eq1)
{
    Image2D<int> i1(800, 600);
    Image2D<int> i2(800, 600);
}

TEST(test_image, crop)
{
    Image2D<int> i1(20, 20);
    Image2D<int> i2(10, 10);
    i2 = *i1.crop(5, 5, 15, 15);
}

TEST(test_image_grey, save)
{
    Image2Grey i1(10, 10);
    Image2Grey i2(20, 20);

    for (std::size_t x = 0; x < i1.width(); x++) {
        for (std::size_t y = 0; y < i1.height(); y++) {
            i1(x, y) = x + y * 10;
        }
    }

    i1.save("img1.pgm");
    i2.save("img2.pgm");
}

TEST(test_image_grey, load)
{
    Image2Grey i1(10, 10);

    i1.load("img1.pgm");

    // std::cout << i1 << std::endl;
}

TEST(test_image_grey, io)
{
    Image2Grey i1(10, 10);

    i1.load("img1.pgm");
    i1.save("img1_.pgm");

    // std::cout << i1 << std::endl;
}

TEST(test_image_grey, subSample)
{
    Image2Grey i1(10, 10);
    i1.load("img1.pgm");

    Image2Grey* i2;

    i2 = Image2Grey::subSample(i1);

    // std::cout << (*i2);

    i2->save("img1_subsample.pgm");

    delete i2;
}

TEST(gradient_sobel, t1)
{
    Image2Grey i1(10, 10);
    Image2D<Vec2f> x = GradientSobel::gradient55(i1);
}

TEST(test_image_rgb, save)
{
    Image2RGB i1(10, 10);
    Image2RGB i2(20, 20);

    Vec3uc a;
    for (std::size_t x = 0; x < i1.width(); x++) {
        for (std::size_t y = 0; y < i1.height(); y++) {
            a[0] = x + y * 10;
            a[1] = x + y * 2;
            a[2] = x + y * 3;
            i1(x, y) = a;
        }
    }

    i1.save("img1.ppm");
    i2.save("img2.ppm");
}

TEST(test_image_rgb, load)
{
    Image2RGB i1(10, 10);

    i1.load("img1.ppm");

    // std::cout << i1 << std::endl;
}

TEST(test_image_rgb, io)
{
    Image2RGB i1(10, 10);

    i1.load("img1.ppm");
    i1.save("img1_.ppm");

    // std::cout << i1 << std::endl;
}

TEST(test_image_grey, threshold)
{
    Image2Grey i1(10, 10);
    i1.load("img1.pgm");

    Image2Grey* i2;

    i2 = Image2Grey::threshold(i1, 30);

    // std::cout << (*i2);

    i2->save("img1_threshold.pgm");

    delete i2;
}

TEST(test_image_grey, smooth)
{
    Image2Grey i1(10, 10);
    i1.load("img1.pgm");

    Image2Grey* i2;

    i2 = Image2Grey::smooth(i1, 1);

    // std::cout << (*i2);

    i2->save("img1_smooth.pgm");

    delete i2;
}

TEST(test_image_grey, smooth2)
{
    Image2Grey i1(620, 637);
    i1.load("lapin.pgm");
    i1.save("lapin1.pgm");

    Image2Grey* i2;

    i2 = Image2Grey::smooth(i1, 1);

    // std::cout << (*i2);

    i2->save("lapin_smooth.pgm");
    i2 = Image2Grey::smooth(i1, 2);
    i2->save("lapin_smooth2.pgm");
    i2 = Image2Grey::smooth(i1, 3);
    i2->save("lapin_smooth3.pgm");

    delete i2;
}
TEST(test_image_grey, threshold2)
{
    Image2Grey i1(620, 637);
    i1.load("lapin.pgm");

    Image2Grey* i2;

    i2 = Image2Grey::threshold(i1, 130);

    // std::cout << (*i2);

    i2->save("lapinthreshold.pgm");

    delete i2;
}
TEST(test_image_grey, subSample2)
{
    Image2Grey i1(620, 637);
    i1.load("lapin.pgm");

    Image2Grey* i2;

    i2 = Image2Grey::subSample(i1);

    // std::cout << (*i2);

    i2->save("lapin_subsample.pgm");

    delete i2;
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    setlocale(LC_CTYPE, "");
    return RUN_ALL_TESTS();
}
