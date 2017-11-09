#include <iostream>

#include "image2d.h"

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

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    setlocale(LC_CTYPE, "");
    return RUN_ALL_TESTS();
}
