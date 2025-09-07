#include <gtest/gtest.h>
#include "Graph.hpp"

TEST(week_2_day_2, basic_scenario)
{
    Node a{123};
    Node b{456};
    a.addNeighbor(std::make_shared<Node>(b));
    b.addNeighbor(std::make_shared<Node>(a));
}