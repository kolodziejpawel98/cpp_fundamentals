#include <gtest/gtest.h>
#include <sstream>
#include <memory>
#include <typeinfo>
#include "FileWrapper.hpp"

TEST(fileWrapperTest, objectMoving)
{
    FileWrapper fileWrapper_1("sample_file.txt");
    EXPECT_TRUE(fileWrapper_1.isOpen());
    FileWrapper fileWrapper_2 = std::move(fileWrapper_1);
    EXPECT_FALSE(fileWrapper_1.isOpen());
}

TEST(fileWrapperTest, checkIfCOpyingIsBanned)
{
    EXPECT_TRUE(std::is_move_constructible_v<FileWrapper>);
    EXPECT_TRUE(std::is_move_assignable_v<FileWrapper>);
    EXPECT_FALSE(std::is_copy_constructible_v<FileWrapper>);
    EXPECT_FALSE(std::is_copy_assignable_v<FileWrapper>);
}

TEST(fileWrapperTest, writingToFile)
{
    FileWrapper fileWrapper_1("sample_file.txt");
    fileWrapper_1.write("hello world!");
}