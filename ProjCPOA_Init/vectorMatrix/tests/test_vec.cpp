#include <iostream>

#include "vector.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(test_vector, eq1)
{
    Vector<int, 3> v1;
    Vector<int, 3> v2;

    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
    v2[0] = 1;
    v2[1] = 2;
    v2[2] = 3;

    EXPECT_TRUE(v1 == v2);
    EXPECT_TRUE(v2 == v1);
}
TEST(test_vector, add1)
{
    Vector<int, 3> v1;
    EXPECT_EQ(v1[1], 0);
    v1[0] = 2;
    v1[1] = 3;
    v1[2] = 4;
    EXPECT_EQ(v1[0], 2);
    Vector<int, 3> v2;
    v2[0] = 1;
    v2[1] = 2;
    v2[2] = 1;
    Vector<int, 3> v3;
    v3[0] = 3;
    v3[1] = 5;
    v3[2] = 5;
    Vector<int, 3> v4;
    v4 = v1 + v2;
    EXPECT_TRUE(v3 == v4);
}
TEST(test_vector, add2)
{
    Vector<int, 3> v1;
    EXPECT_EQ(v1[1], 0);
    v1[0] = 2;
    v1[1] = 3;
    v1[2] = 4;
    EXPECT_EQ(v1[0], 2);
    Vector<int, 3> v2;
    v2[0] = 1;
    v2[1] = 2;
    v2[2] = 1;
    Vector<int, 3> v3;
    v3[0] = 3;
    v3[1] = 5;
    v3[2] = 5;
    v1 += v2;
    EXPECT_TRUE(v1 == v3);
}
TEST(test_vector, sub1)
{
    Vector<int, 3> v1;
    EXPECT_EQ(v1[1], 0);
    v1[0] = 2;
    v1[1] = 3;
    v1[2] = 4;
    EXPECT_EQ(v1[0], 2);
    Vector<int, 3> v2;
    v2[0] = 1;
    v2[1] = 2;
    v2[2] = 1;
    Vector<int, 3> v3;
    v3[0] = 1;
    v3[1] = 1;
    v3[2] = 3;
    Vector<int, 3> v4;
    v4 = v1 - v2;
    EXPECT_TRUE(v3 == v4);
}
TEST(test_vector, mul1)
{
    Vector<int, 2> v1;
    v1[0] = 2;
    v1[1] = 3;
    v1 *= 2;
    Vector<int, 2> v2;
    v2[0] = 4;
    v2[1] = 6;
    EXPECT_TRUE(v1 == v2);
}
TEST(test_vector, mul2)
{
    Vector<int, 2> v1;
    v1[0] = 2;
    v1[1] = 3;
    Vector<int, 2> v3 = v1 * 2;
    Vector<int, 2> v2;
    v2[0] = 4;
    v2[1] = 6;
    EXPECT_TRUE(v3 == v2);
}
TEST(test_vector, mul3)
{
    Vector<float, 2> v1;
    v1[0] = 2.;
    v1[1] = 3.;
    v1 = 0.5f * v1;
    EXPECT_TRUE(v1[0] == 1.0);
    EXPECT_TRUE(v1[1] == 1.5);
}
TEST(test_vector, div1)
{
    Vector<int, 2> v1;
    v1[0] = 2;
    v1[1] = 3;
    Vector<int, 2> v2;
    v2[0] = 4;
    v2[1] = 6;
    v2 /= 2;
    EXPECT_TRUE(v1 == v2);
}
TEST(test_vector, div2)
{
    Vector<int, 2> v1;
    v1[0] = 2;
    v1[1] = 3;
    Vector<int, 2> v2;
    v2[0] = 4;
    v2[1] = 6;
    Vector<int, 2> v3 = v2 / 2;
    EXPECT_TRUE(v3 == v1);
}
TEST(test_vector, dot)
{
    Vector<int, 2> v1;
    v1[0] = 2;
    v1[1] = 3;
    Vector<int, 2> v2;
    v2[0] = 4;
    v2[1] = 6;
    int dot = v1 * v2;
    EXPECT_EQ(dot, 26);
}
TEST(test_vector, cross)
{
    Vector<int, 3> v1;
    v1[0] = 2;
    v1[1] = 3;
    v1[2] = 4;
    Vector<int, 3> v2;
    v2[0] = 4;
    v2[1] = 6;
    v2[2] = 4;
    Vector<int, 3> v3;
    v3 = v1 ^ v2;
    Vector<int, 3> v4;
    v4[0] = -12;
    v4[1] = 8;
    v4[2] = 0;

    EXPECT_EQ(v3, v4);
}
TEST(test_vector, vec3i)
{
    Vec3i v1;
    v1[0] = 2;
    v1[1] = 3;
    v1[2] = 4;
    Vec3i v2;
    v2[0] = 4;
    v2[1] = 6;
    v2[2] = 4;
    Vec3i v3;
    v3 = v1 ^ v2;
    Vec3i v4;
    v4[0] = -12;
    v4[1] = 8;
    v4[2] = 0;

    EXPECT_EQ(v3, v4);
}
TEST(test_vector, vec3f)
{
    Vec3f v1;
    v1[0] = 2.3;
    v1[1] = 3.5;
    v1[2] = 4.4;
    Vec3f v2;
    v2[0] = 4.2;
    v2[1] = 6.4;
    v2[2] = 4.9;
    Vec3f v3;
    v3 = v1 ^ v2;
    Vec3f v4;
    v4[0] = -11.01;
    v4[1] = 7.21;
    v4[2] = 0.02;

    std::cout << v4[0] << " " << v4[1] << " " << v4[2] << std::endl;
    std::cout << v3[0] << " " << v3[1] << " " << v3[2] << std::endl;

    EXPECT_NEAR(v3[0], v4[0], 0.00001);
    EXPECT_NEAR(v3[1], v4[1], 0.00001);
    EXPECT_NEAR(v3[2], v4[2], 0.00001);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    setlocale(LC_CTYPE, "");
    return RUN_ALL_TESTS();
}
