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

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    setlocale(LC_CTYPE, "");
    return RUN_ALL_TESTS();
}
