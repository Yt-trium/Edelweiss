#include <iostream>
#include <assert.h>

#include "array.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(test_array, eq1)
{
    Array<int, 10> a1;
    Array<int, 10> a2;
    EXPECT_TRUE(a1==a2);
    EXPECT_TRUE(a2==a1);
}

TEST(test_array, eq2)
{
    Array<int, 3> a1;
    a1[0] = 1;
    a1[1] = 2;
    a1[2] = 3;

    int tmp[3] = {1,2,3};
    Array<int, 3> a2(tmp);

    const int *tmp2 = a2.get_data();

    EXPECT_TRUE(a1==a2);
    EXPECT_EQ(tmp2[1],2);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    setlocale(LC_CTYPE, "");
    return RUN_ALL_TESTS();
}
