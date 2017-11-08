#include <iostream>

#include "vector.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(test_vector, eq1)
{
    Vector<int,3> v1;
    Vector<int,3> v2;

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
    Vector<int,3> v1;
    EXPECT_EQ(v1[1],0);
    v1[0] = 2;
    v1[1] = 3;
    v1[2] = 4;
    EXPECT_EQ(v1[0],2);
    Vector<int,3> v2;
    v2[0] = 1;
    v2[1] = 2;
    v2[2] = 1;
    Vector<int,3> v3;
    v3[0] = 3;
    v3[1] = 5;
    v3[2] = 5;
    Vector<int,3> v4;
    v4 = v1 + v2;
    EXPECT_TRUE(v3 == v4);
}
TEST(test_vector, add2)
{
    Vector<int,3> v1;
    EXPECT_EQ(v1[1],0);
    v1[0] = 2;
    v1[1] = 3;
    v1[2] = 4;
    EXPECT_EQ(v1[0],2);
    Vector<int,3> v2;
    v2[0] = 1;
    v2[1] = 2;
    v2[2] = 1;
    Vector<int,3> v3;
    v3[0] = 3;
    v3[1] = 5;
    v3[2] = 5;
    v1 += v2;
    EXPECT_TRUE(v1 == v3);
}
TEST(test_vector, sub1)
{
    Vector<int,3> v1;
    EXPECT_EQ(v1[1],0);
    v1[0] = 2;
    v1[1] = 3;
    v1[2] = 4;
    EXPECT_EQ(v1[0],2);
    Vector<int,3> v2;
    v2[0] = 1;
    v2[1] = 2;
    v2[2] = 1;
    Vector<int,3> v3;
    v3[0] = 1;
    v3[1] = 1;
    v3[2] = 3;
    Vector<int,3> v4;
    v4 = v1 - v2;
    EXPECT_TRUE(v3 == v4);
}
TEST(test_vector, mul1)
{
    Vector<int,2> v1;
    v1[0] = 2;
    v1[1] = 3;
    v1 *= 2;
    Vector<int,2> v2;
    v2[0] = 4;
    v2[1] = 6;
    EXPECT_TRUE(v1 == v2);
}
TEST(test_vector, mul2)
{
    Vector<int,2> v1;
    v1[0] = 2;
    v1[1] = 3;
    Vector<int,2> v3 = v1 * 2;
    Vector<int,2> v2;
    v2[0] = 4;
    v2[1] = 6;
    EXPECT_TRUE(v3 == v2);
}
TEST(test_vector, div1)
{
    Vector<int,2> v1;
    v1[0] = 2;
    v1[1] = 3;
    Vector<int,2> v2;
    v2[0] = 4;
    v2[1] = 6;
    v2 /= 2;
    EXPECT_TRUE(v1 == v2);
}
TEST(test_vector, div2)
{
    Vector<int,2> v1;
    v1[0] = 2;
    v1[1] = 3;
    Vector<int,2> v2;
    v2[0] = 4;
    v2[1] = 6;
    Vector<int,2> v3 = v2 / 2;
    EXPECT_TRUE(v3 == v1);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    setlocale(LC_CTYPE, "");
    return RUN_ALL_TESTS();
}
