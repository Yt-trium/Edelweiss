#include <iostream>

#include "matrix33d.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(test_matrix, identity)
{
    Matrix33d m1 = Matrix33d::identity();
    Matrix33d m2;
    m2[0][0] = 1;
    m2[1][1] = 1;
    m2[2][2] = 1;
}
TEST(test_matrix, out_of_range)
{
    Matrix33d m1 = Matrix33d::identity();

    EXPECT_NO_THROW(m1[1][1]);
    EXPECT_THROW(m1[3][3], std::out_of_range);
    EXPECT_THROW(m1[1][3], std::out_of_range);
    EXPECT_THROW(m1[3][1], std::out_of_range);
    EXPECT_THROW(m1[3][1], std::out_of_range);
}
TEST(test_matrix, inverse)
{
    Matrix33d m1;
    m1[0][0] = 2;
    m1[0][1] = 3;
    m1[0][2] = 4;
    m1[1][0] = 5;
    m1[1][1] = 6;
    m1[1][2] = 7;
    m1[2][0] = 8;
    m1[2][1] = 9;
    m1[2][2] = 8;

    Matrix33d m2 = m1.inverse();

    Matrix33d m3;
    m3[0][0] = (-5. / 2.);
    m3[0][1] = (2.);
    m3[0][2] = (-1. / 2.);
    m3[1][0] = (8. / 3.);
    m3[1][1] = (-8. / 3.);
    m3[1][2] = (1.);
    m3[2][0] = (-1. / 2.);
    m3[2][1] = (1.);
    m3[2][2] = (-1. / 2.);

    std::cout << m2 << std::endl;
    std::cout << m3 << std::endl;

    EXPECT_EQ(m2[0][0], m3[0][0]);
    EXPECT_EQ(m2[0][1], m3[0][1]);
    EXPECT_EQ(m2[0][2], m3[0][2]);
    EXPECT_EQ(m2[1][0], m3[1][0]);
    EXPECT_EQ(m2[1][1], m3[1][1]);
    EXPECT_EQ(m2[1][2], m3[1][2]);
    EXPECT_EQ(m2[2][0], m3[2][0]);
    EXPECT_EQ(m2[2][1], m3[2][1]);
    EXPECT_EQ(m2[2][2], m3[2][2]);
}

/*
      std::cout << "translate(3.5f,2.4f) "<<  std::endl;
      m1.translate(3.5f,2.4f);
      std::cout << m1 <<  std::endl;

      x = 0.0;
      y = 0.0;
      m1.applyTransformation(x,y);
      std::cout << "0,0 => "<< x << "," << y << std::endl;

      m1.rotate(0.4);
      Matrix33d m2 = m1.inverse();

      std::cout << m1 << std::endl<<"*"<< std::endl<<m2<< "=" << std::endl<<
     m1*m2 << std::endl;
*/

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    setlocale(LC_CTYPE, "");
    return RUN_ALL_TESTS();
}
