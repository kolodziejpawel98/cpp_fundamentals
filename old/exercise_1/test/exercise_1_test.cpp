#include <gtest/gtest.h>
#include "intVector.hpp"

TEST(exercise_1, checkVectorSize)
{
    IntVector vec;
    vec.push_back(13);
    EXPECT_EQ(vec.size(), 1);
    vec.push_back(14);
    EXPECT_EQ(vec.size(), 2);
}

TEST(exercise_1, checkReturnedElement)
{
    IntVector vec;
    vec.push_back(13);
    vec.push_back(14);
    EXPECT_EQ(vec.get(0), 13);
    EXPECT_EQ(vec.get(1), 14);
}

TEST(exercise_1, checkMultiplePushBack)
{
    IntVector vec;
    for (int i = 0; i < 100; ++i)
    {
        vec.push_back(i);
        EXPECT_EQ(vec.size(), i + 1);
        EXPECT_EQ(vec.get(i), i);
    }
}

TEST(exercise_1, getThrowsOnNegativeIndex)
{
    IntVector vec;
    vec.push_back(10);
    EXPECT_THROW(vec.get(-1), std::out_of_range);
}

TEST(exercise_1, getThrowsOnTooLargeIndex)
{
    IntVector vec;
    vec.push_back(10);
    EXPECT_THROW(vec.get(1), std::out_of_range);
}

TEST(exercise_1, getFromEmptyVectorThrows)
{
    IntVector vec;
    EXPECT_THROW(vec.get(0), std::out_of_range);
}

TEST(exercise_1, pushBackSameValue)
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

TEST(exercise_1, copyAssignmentOperator)
{
    IntVector vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);

    IntVector vec2;
    vec2.push_back(10);

    vec2 = vec1;

    EXPECT_EQ(vec2.size(), vec1.size());
    for (size_t i = 0; i < vec1.size(); ++i)
    {
        EXPECT_EQ(vec2.get(i), vec1.get(i));
    }

    vec2 = vec2;
    EXPECT_EQ(vec2.size(), vec1.size());
    for (size_t i = 0; i < vec2.size(); ++i)
    {
        EXPECT_EQ(vec2.get(i), vec1.get(i));
    }
}

TEST(exercise_1, copyConstructorCreatesDeepCopy)
{
    IntVector original;
    original.push_back(42);
    original.push_back(99);

    IntVector copy = original;

    EXPECT_EQ(copy.size(), original.size());
    EXPECT_EQ(copy.get(0), original.get(0));
    EXPECT_EQ(copy.get(1), original.get(1));

    original.push_back(123);
    EXPECT_EQ(original.size(), 3);
    EXPECT_EQ(copy.size(), 2);
}

// ##############################

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}