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
    FileWrapper f1("sample_file.txt");
    FileWrapper f2 = f1;
}