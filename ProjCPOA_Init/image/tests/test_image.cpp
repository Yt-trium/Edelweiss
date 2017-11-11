#include <iostream>

#include "gradientsobel.h"
#include "image2d.h"
#include "image2grey.h"

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
    Image2Grey i2(24, 24);

    // i1.save("img1.pgm");
    i2.save("img2.pgm");
}

TEST(test_image_grey, load)
{
    Image2Grey i1(10, 10);

    i1.load("img1.pgm");

    // std::cout << i1 << std::endl;
}
/*
TEST(test_image_grey, subSample)
{
    Image2Grey i1(10, 10);
    Image2Grey i2(5, 5);
    Image2Grey* i2ptr;
    i2ptr = &i2;
    i2ptr = i1.subSample();

    std::cout << i2 << std::endl;
}
*/

TEST(gradient_sobel, t1)
{
    Image2Grey i1(10, 10);
    GradientSobel::gradient55(i1);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    setlocale(LC_CTYPE, "");
    return RUN_ALL_TESTS();
}
