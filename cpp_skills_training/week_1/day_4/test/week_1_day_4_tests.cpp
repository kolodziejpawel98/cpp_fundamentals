#include <gtest/gtest.h>
#include "BitOperations.hpp"

TEST(week_1_day_4, orOperator)
{
    using T = std::underlying_type_t<Permission>;
    EXPECT_EQ(static_cast<T>(Permission::Read), 0b00000001);
    EXPECT_EQ(static_cast<T>(Permission::Write), 0b00000010);

    auto readOrWrite = Permission::Read | Permission::Write;
    EXPECT_EQ(static_cast<T>(readOrWrite), 0b00000011);
}

TEST(week_1_day_4, orOperatorWithAssignment)
{
    using T = std::underlying_type_t<Permission>;

    auto readOrWrite = Permission::Read;
    readOrWrite |= Permission::Write;
    EXPECT_EQ(static_cast<T>(readOrWrite), 0b00000011);
}

TEST(week_1_day_4, setMethod)
{
    PermSet permSet_1 = set(0b00000000, Permission::Read);
    EXPECT_EQ(static_cast<PermSet>(permSet_1), 0b00000001);

    PermSet permSet_2 = set(0b00000011, Permission::Read);
    EXPECT_EQ(static_cast<PermSet>(permSet_2), 0b00000011);
}