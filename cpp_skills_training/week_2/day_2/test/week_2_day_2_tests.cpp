#include <gtest/gtest.h>
#include "Graph.hpp"

TEST(week_2_day_2, basic_scenario)
{
    std::shared_ptr<Node> a(new Node(123));
    EXPECT_EQ(a.use_count(), 1);
    std::shared_ptr<Node> b(new Node(456));
    EXPECT_EQ(b.use_count(), 1);
    a->addNeighbor(b); //???????????
    b->addNeighbor(a); //???????????
}