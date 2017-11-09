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
    EXPECT_EQ(m1, m2);
}
/*
TEST(test_matrix, out_of_range)
{
    Matrix33d m1 = Matrix33d::identity();

    EXPECT_NO_THROW(m1[1][1]);
    EXPECT_THROW(m1[3][3], std::out_of_range);
    EXPECT_THROW(m1[1][3], std::out_of_range);
    EXPECT_THROW(m1[3][1], std::out_of_range);
    EXPECT_THROW(m1[3][1], std::out_of_range);
}
*/
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

    EXPECT_EQ(m2[0][0], m3[0][0]);
    EXPECT_EQ(m2[0][1], m3[0][1]);
    EXPECT_EQ(m2[0][2], m3[0][2]);
    EXPECT_EQ(m2[1][0], m3[1][0]);
    EXPECT_EQ(m2[1][1], m3[1][1]);
    EXPECT_EQ(m2[1][2], m3[1][2]);
    EXPECT_EQ(m2[2][0], m3[2][0]);
    EXPECT_EQ(m2[2][1], m3[2][1]);
    EXPECT_EQ(m2[2][2], m3[2][2]);
    EXPECT_EQ(m3, m2);
}
TEST(test_matrix, multiplication1)
{
    Matrix33d m1 = Matrix33d::translate(3.5, 2.4);
    Matrix33d m2 = Matrix33d::translate(-3.5, -2.4);

    Vec3f v1;
    Vec3f v2;
    v1[0] = 2.3;
    v1[1] = 4.6;
    v1[2] = 1.;

    // std::cout << v1 << std::endl;
    v2 = m1 * v1;
    // std::cout << v2 << std::endl;
    v2 = m2 * v2;
    // std::cout << v2 << std::endl;

    EXPECT_NEAR(v1[0], v2[0], 0.00001);
    EXPECT_NEAR(v1[1], v2[1], 0.00001);
    EXPECT_NEAR(v1[2], v2[2], 0.00001);
}
TEST(test_matrix, multiplication2)
{
    Matrix33d m1 = Matrix33d::translate(3.5, 2.4);
    Matrix33d m2 = Matrix33d::translate(-3.5, -2.4);

    Vec2f v1;
    Vec2f v2;
    v1[0] = 2.3;
    v1[1] = 4.6;
    // std::cout << v1 << std::endl;
    v2 = m1 * v1;
    // std::cout << v2 << std::endl;
    v2 = m2 * v2;
    // std::cout << v2 << std::endl;

    EXPECT_NEAR(v1[0], v2[0], 0.00001);
    EXPECT_NEAR(v1[1], v2[1], 0.00001);
}
TEST(test_matrix, transformation1)
{
    Matrix33d m1 = Matrix33d::translate(3.5, 2.4);
    Matrix33d m2 = Matrix33d::identity();
    m2.translateM(3.5, 2.4);

    Vec2f v1;
    v1[0] = 12;
    v1[1] = 13;
    Vec2f v2(v1);
    EXPECT_EQ(v1, v2);

    v1 = m1 * v1;
    v2 = m2 * v2;
    EXPECT_EQ(v1, v2);
}
TEST(test_matrix, transformation2)
{
    Matrix33d m1 = Matrix33d::rotate(38);
    Matrix33d m2 = Matrix33d::identity();
    m2.rotateM(38);

    Vec2f v1;
    v1[0] = 12;
    v1[1] = 13;
    Vec2f v2(v1);
    EXPECT_EQ(v1, v2);

    v1 = m1 * v1;
    v2 = m2 * v2;
    EXPECT_EQ(v1, v2);
}
TEST(test_matrix, transformation3)
{
    Matrix33d m1 = Matrix33d::scale(3.5, 2.4);
    Matrix33d m2 = Matrix33d::identity();
    m2.scaleM(3.5, 2.4);

    Vec2f v1;
    v1[0] = 12;
    v1[1] = 13;
    Vec2f v2(v1);
    EXPECT_EQ(v1, v2);

    v1 = m1 * v1;
    v2 = m2 * v2;
    EXPECT_EQ(v1, v2);
}
TEST(test_matrix, transformation4)
{
    Matrix33d m1 = Matrix33d::identity();
    m1 = Matrix33d::scale(3.5, 2.4) * m1;
    m1 = Matrix33d::rotate(12) * m1;
    m1 = Matrix33d::translate(4, 2) * m1;

    Matrix33d m2 = Matrix33d::identity();
    m2.scaleM(3.5, 2.4);
    m2.rotateM(12);
    m2.translateM(4, 2);

    Vec2f v1;
    v1[0] = 12;
    v1[1] = 13;
    Vec2f v2(v1);
    EXPECT_EQ(v1, v2);

    v1 = m1 * v1;
    v2 = m2 * v2;
    EXPECT_EQ(v1, v2);
}
TEST(test_matrix, transformation5)
{
    Matrix33d m1 = Matrix33d::translate(4, 2);

    Vec2f v1;
    v1[0] = 12;
    v1[1] = 13;
    double x = 12;
    double y = 13;

    v1 = m1 * v1;
    m1.applyTransformation(&x, &y);
    EXPECT_EQ(v1[0], x);
    EXPECT_EQ(v1[1], y);
}

/*
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
