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

// ######## v2

TEST(week_1_day_1_v2, openFile)
{
    FileWrapperV2 fileWrapper("../cpp_skills_training/week_1/day_1/test/file.txt");
    EXPECT_TRUE(fileWrapper.getLine());
}

TEST(week_1_day_1_v2, movingObject)
{
    FileWrapperV2 fileWrapper1("../cpp_skills_training/week_1/day_1/test/file.txt");
    FileWrapperV2 fileWrapper2 = std::move(fileWrapper1);
}

TEST(week_1_day_1_v2, callGetLineOnEmptyObject)
{
    FileWrapperV2 fileWrapper1("../cpp_skills_training/week_1/day_1/test/file.txt");
    FileWrapperV2 fileWrapper2 = std::move(fileWrapper1);
    // EXPECT_FALSE(fileWrapper1.getLine()); // passing null ptr TODO
    EXPECT_TRUE(fileWrapper2.getLine());
}