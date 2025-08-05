#include <gtest/gtest.h>
#include <sstream>
#include <memory>
#include <typeinfo>
#include "FileWrapper.hpp"

TEST(fileWrapperTest, objectMoving)
{
    FileWrapper fileWrapper_1("sample_file.txt");
    FileWrapper fileWrapper_2 = std::move(fileWrapper_1);
    EXPECT_EQ(fileWrapper_1, nullptr);
}