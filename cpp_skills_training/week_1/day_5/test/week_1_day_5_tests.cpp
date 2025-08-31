#include <gtest/gtest.h>
#include "Factorial.hpp"

TEST(week_1_day_5, iterative_factorial)
{
    EXPECT_EQ(factorialIterative<0>(), 1);
    EXPECT_EQ(factorialIterative<1>(), 1);
    EXPECT_EQ(factorialIterative<2>(), 2);
    EXPECT_EQ(factorialIterative<3>(), 6);
    EXPECT_EQ(factorialIterative<4>(), 24);
    EXPECT_EQ(factorialIterative<5>(), 120);
}

// unit test for compile time exception
// TEST(week_1_day_5, unsigned_overflow)
// {
//     factorialIterative<21>();
// }

TEST(week_1_day_5, checking_compile_time_corrrectness)
{
    constexpr unsigned long long size = factorialIterative<3>();
    int array[size];
    EXPECT_EQ((sizeof(array) / sizeof(int)), 6);
}

TEST(week_1_day_5, checking_compile_time_corrrectness_with_array)
{
    std::array<int, factorialIterative<3>()> array;
    EXPECT_EQ(array.size(), 6);
}

TEST(week_1_day_5, recursive_factorial)
{
    EXPECT_EQ(factorialRecursive(1), 1);
    EXPECT_EQ(factorialRecursive(1), 1);
    EXPECT_EQ(factorialRecursive(2), 2);
    EXPECT_EQ(factorialRecursive(3), 6);
    EXPECT_EQ(factorialRecursive(4), 24);
    EXPECT_EQ(factorialRecursive(5), 120);
}

TEST(week_1_day_5, unsigned_overflow)
{
    EXPECT_THROW(factorialRecursive(21), std::overflow_error);
    EXPECT_THROW(factorialRecursive(-1), std::overflow_error);
}
