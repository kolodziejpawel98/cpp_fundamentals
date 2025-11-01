#include <gtest/gtest.h>
#include "OwnMakeUnique.hpp"

TEST(week_2_day_3, basic_scenario)
{
    print(1, 2, 3.14,
          "Pass me any "
          "number of arguments",
          "I will print\n");

    foo("a", "b", "c");
}
