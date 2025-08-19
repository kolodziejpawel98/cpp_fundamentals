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

TEST(week_1_day_1, moveConstructor)
{
    Buffer buffer_1{2, 5};
    Buffer buffer_2 = std::move(buffer_1);
    EXPECT_EQ(buffer_1.getArraySize(), 0);
    EXPECT_EQ(buffer_2.getArraySize(), 2);
}

TEST(week_1_day_1, moveOperator)
{
    Buffer buffer_1{};
    Buffer buffer_2{2, 5};
    EXPECT_EQ(buffer_1.getArraySize(), 0);
    buffer_1 = std::move(buffer_2);
    EXPECT_EQ(buffer_1.getArraySize(), 2);
}

TEST(week_1_day_1, moveEmptyToEmpty)
{
    Buffer buffer_1{};
    Buffer buffer_2{2, 5};
    buffer_2 = std::move(buffer_1);
    EXPECT_EQ(buffer_2.getArraySize(), 0);
    EXPECT_EQ(buffer_1.getArraySize(), 0);
}

TEST(week_1_day_1, getData)
{
    Buffer buffer_1{2, 5};
    const int *data_1 = buffer_1.getData();
    EXPECT_EQ(*data_1, 5);

    Buffer buffer_2{};
    const int *data_2 = buffer_2.getData();
    EXPECT_EQ(data_2, nullptr);
}

TEST(week_1_day_1, getElement)
{
    Buffer buffer_1{2, 5};
    EXPECT_EQ(buffer_1[0], 5);
    EXPECT_EQ(buffer_1.at(0), 5);
    EXPECT_THROW(buffer_1.at(10), std::out_of_range);
}

TEST(week_1_day_1, pushBack)
{
    Buffer buffer_1{2, 5};
    EXPECT_EQ(buffer_1.getArraySize(), 2);
    EXPECT_EQ(buffer_1.at(buffer_1.getArraySize() - 1), 5);
    buffer_1.push_back(3);
    EXPECT_EQ(buffer_1.getArraySize(), 3);
    EXPECT_EQ(buffer_1.at(buffer_1.getArraySize() - 1), 3);

    Buffer buffer_2{};
    EXPECT_EQ(buffer_2.getArraySize(), 0);
    EXPECT_THROW(buffer_2.at(buffer_2.getArraySize() - 1), std::out_of_range);
    buffer_2.push_back(3);
    EXPECT_EQ(buffer_2.getArraySize(), 1);
    EXPECT_EQ(buffer_2.at(buffer_2.getArraySize() - 1), 3);
}