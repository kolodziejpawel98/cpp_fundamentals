#include <gtest/gtest.h>
#include "intVector.hpp"

TEST(ptr_ref_const, checkVectorSize)
{
    IntVector vec;
    vec.push_back(13);
    EXPECT_EQ(vec.size(), 1);
    vec.push_back(14);
    EXPECT_EQ(vec.size(), 2);
}

TEST(ptr_ref_const, checkReturnedElement)
{
    IntVector vec;
    vec.push_back(13);
    vec.push_back(14);
    EXPECT_EQ(vec.get(0), 13);
    EXPECT_EQ(vec.get(1), 14);
}

TEST(ptr_ref_const, checkMultiplePushBack)
{
    IntVector vec;
    for (int i = 0; i < 100; ++i)
    {
        vec.push_back(i);
        EXPECT_EQ(vec.size(), i + 1);
        EXPECT_EQ(vec.get(i), i);
    }
}

TEST(ptr_ref_const, getThrowsOnNegativeIndex)
{
    IntVector vec;
    vec.push_back(10);
    EXPECT_THROW(vec.get(-1), std::out_of_range);
}

TEST(ptr_ref_const, getThrowsOnTooLargeIndex)
{
    IntVector vec;
    vec.push_back(10);
    EXPECT_THROW(vec.get(1), std::out_of_range);
}

TEST(ptr_ref_const, getFromEmptyVectorThrows)
{
    IntVector vec;
    EXPECT_THROW(vec.get(0), std::out_of_range);
}

TEST(ptr_ref_const, pushBackSameValue)
{
    IntVector vec;
    for (int i = 0; i < 5; ++i)
    {
        vec.push_back(42);
    }
    EXPECT_EQ(vec.size(), 5);
    for (int i = 0; i < 5; ++i)
    {
        EXPECT_EQ(vec.get(i), 42);
    }
}

// ##############################

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}