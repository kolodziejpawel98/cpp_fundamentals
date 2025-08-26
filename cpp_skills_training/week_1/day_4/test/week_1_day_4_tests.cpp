#include <gtest/gtest.h>
#include "BitOperations.hpp"

TEST(week_1_day_3, orOperator)
{
    using T = std::underlying_type_t<Permission>;
    EXPECT_EQ(static_cast<T>(Permission::Read), 0b00000001);
    EXPECT_EQ(static_cast<T>(Permission::Write), 0b00000010);

    auto readOrWrite = Permission::Read | Permission::Write;
    EXPECT_EQ(static_cast<T>(readOrWrite), 0b00000011);
}
