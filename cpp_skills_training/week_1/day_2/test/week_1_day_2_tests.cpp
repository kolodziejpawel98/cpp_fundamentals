#include <gtest/gtest.h>
#include "Buffer.hpp"

TEST(week_1_day_1, copyConstructorAndCopyOperator)
{
    Buffer buffer_1{1, 3};
    Buffer buffer_2{2, 5};
    Buffer buffer_3 = buffer_1;
    Buffer emptyBuffer{};

    EXPECT_EQ(buffer_3.getArraySize(), 1);
    buffer_3 = buffer_2;
    EXPECT_EQ(buffer_3.getArraySize(), 2);
    buffer_3 = buffer_3;
    EXPECT_EQ(buffer_3.getArraySize(), 2);
    buffer_3 = emptyBuffer;
    EXPECT_EQ(buffer_3.getArraySize(), 0);
}

TEST(week_1_day_1, moveOperator)
{
    Buffer buffer_1{2, 5};
    Buffer buffer_2 = std::move(buffer_1);
    EXPECT_EQ(buffer_2.getArraySize(), 2);
}

// TEST(week_1_day_1, moveOperator)
// {
//     Buffer buffer_1{};
//     Buffer buffer_2{2, 5};
//     EXPECT_EQ(buffer_1.getArraySize(), 0);
//     buffer_1 = std::move(buffer_2);
//     EXPECT_EQ(buffer_1.getArraySize(), 2);
// }
