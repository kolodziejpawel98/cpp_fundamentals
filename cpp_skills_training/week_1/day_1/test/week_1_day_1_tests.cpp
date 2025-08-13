#include <gtest/gtest.h>
#include "FileWrapper.hpp"

TEST(week_1_day_1, getLIne)
{
    FileWrapper fileWrapper("../cpp_skills_training/week_1/day_1/test/file.txt");
    EXPECT_TRUE(fileWrapper.getLine().has_value());
}

TEST(week_1_day_1, movingObject)
{
    FileWrapper fileWrapper1("../cpp_skills_training/week_1/day_1/test/file.txt");
    FileWrapper fileWrapper2 = std::move(fileWrapper1);
}

TEST(week_1_day_1, callGetLineOnEmptyObject)
{
    FileWrapper fileWrapper1("../cpp_skills_training/week_1/day_1/test/file.txt");
    FileWrapper fileWrapper2 = std::move(fileWrapper1);
    EXPECT_EQ(fileWrapper1.getLine(), std::nullopt);
    EXPECT_TRUE(fileWrapper2.getLine().has_value());
}