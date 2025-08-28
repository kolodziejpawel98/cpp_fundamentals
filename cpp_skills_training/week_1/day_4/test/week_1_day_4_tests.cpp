#include <gtest/gtest.h>
#include "BitOperations.hpp"

TEST(week_1_day_4, or_operator)
{
    using T = std::underlying_type_t<Permission>;
    EXPECT_EQ(static_cast<T>(Permission::Read), 0b00000001);
    EXPECT_EQ(static_cast<T>(Permission::Write), 0b00000010);

    auto readOrWrite = Permission::Read | Permission::Write;
    EXPECT_EQ(static_cast<T>(readOrWrite), 0b00000011);
}

TEST(week_1_day_4, or_operator_with_assignment)
{
    using T = std::underlying_type_t<Permission>;

    auto readOrWrite = Permission::Read;
    readOrWrite |= Permission::Write;
    EXPECT_EQ(static_cast<T>(readOrWrite), 0b00000011);
}

TEST(week_1_day_4, set_method)
{
    PermSet permSet_1 = setPermissionToPermSet(0b00000000, Permission::Read);
    EXPECT_EQ(static_cast<PermSet>(permSet_1), 0b00000001);

    PermSet permSet_2 = setPermissionToPermSet(0b00000011, Permission::Read);
    EXPECT_EQ(static_cast<PermSet>(permSet_2), 0b00000011);
}

TEST(week_1_day_4, get_method)
{
    EXPECT_TRUE(hasPermsetPermission(0b00000111, Permission::Read));
    EXPECT_FALSE(hasPermsetPermission(0b00000110, Permission::Read));
}

TEST(week_1_day_4, has_empty_set_returns_false)
{
    EXPECT_FALSE(hasPermsetPermission(0b00000000, Permission::Read));
    EXPECT_FALSE(hasPermsetPermission(0b00000000, Permission::Write));
    EXPECT_FALSE(hasPermsetPermission(0b00000000, Permission::Exec));
}

TEST(week_1_day_4, has_single_bit_masks)
{
    EXPECT_TRUE(hasPermsetPermission(0b00000001, Permission::Read));
    EXPECT_FALSE(hasPermsetPermission(0b00000001, Permission::Write));
    EXPECT_FALSE(hasPermsetPermission(0b00000001, Permission::Exec));

    EXPECT_FALSE(hasPermsetPermission(0b00000010, Permission::Read));
    EXPECT_TRUE(hasPermsetPermission(0b00000010, Permission::Write));
    EXPECT_FALSE(hasPermsetPermission(0b00000010, Permission::Exec));

    EXPECT_FALSE(hasPermsetPermission(0b00000100, Permission::Read));
    EXPECT_FALSE(hasPermsetPermission(0b00000100, Permission::Write));
    EXPECT_TRUE(hasPermsetPermission(0b00000100, Permission::Exec));
}

TEST(week_1_day_4, has_combined_masks)
{
    EXPECT_TRUE(hasPermsetPermission(0b00000011, Permission::Read));
    EXPECT_TRUE(hasPermsetPermission(0b00000011, Permission::Write));
    EXPECT_FALSE(hasPermsetPermission(0b00000011, Permission::Exec));

    EXPECT_TRUE(hasPermsetPermission(0b00000110, Permission::Write));
    EXPECT_TRUE(hasPermsetPermission(0b00000110, Permission::Exec));
    EXPECT_FALSE(hasPermsetPermission(0b00000110, Permission::Read));
}

TEST(week_1_day_4, has_all_bits_set)
{
    EXPECT_TRUE(hasPermsetPermission(0b00000111, Permission::Read));
    EXPECT_TRUE(hasPermsetPermission(0b00000111, Permission::Write));
    EXPECT_TRUE(hasPermsetPermission(0b00000111, Permission::Exec));
}

TEST(week_1_day_4, has_unrelated_high_bits_do_not_matter)
{
    EXPECT_FALSE(hasPermsetPermission(0b10000000, Permission::Read));
    EXPECT_FALSE(hasPermsetPermission(0b10000000, Permission::Write));
    EXPECT_FALSE(hasPermsetPermission(0b10000000, Permission::Exec));
}

TEST(week_1_day_4, has_idempotence_with_set_usage_example)
{
    PermSet ps = 0;
    ps = setPermissionToPermSet(ps, Permission::Read);
    EXPECT_TRUE(hasPermsetPermission(ps, Permission::Read));
    EXPECT_FALSE(hasPermsetPermission(ps, Permission::Write));
    ps = setPermissionToPermSet(ps, Permission::Write);
    EXPECT_TRUE(hasPermsetPermission(ps, Permission::Read));
    EXPECT_TRUE(hasPermsetPermission(ps, Permission::Write));
}

TEST(week_1_day_4, permission_to_string)
{
    EXPECT_EQ(permissionNameToString(Permission::Read), "Read");
    EXPECT_EQ(permissionNameToString(Permission::Write), "Write");
    EXPECT_EQ(permissionNameToString(Permission::Exec), "Exec");
}