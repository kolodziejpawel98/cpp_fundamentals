#include <gtest/gtest.h>
#include "Factorial.hpp"

TEST(week_1_day_5, iterative_factorial)
{
    EXPECT_EQ(factorialIterative(0), 1);
    EXPECT_EQ(factorialIterative(1), 1);
    EXPECT_EQ(factorialIterative(2), 2);
    EXPECT_EQ(factorialIterative(3), 6);
    EXPECT_EQ(factorialIterative(4), 24);
    EXPECT_EQ(factorialIterative(5), 120);
}

// TEST(week_1_day_5, unsigned_overflow)
// {
//     EXPECT_THROW(factorialIterative(30), std::overflow_error);
// }