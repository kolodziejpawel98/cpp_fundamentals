#include <gtest/gtest.h>
#include "OwnMakeUnique.hpp"

struct Point
{
    int x, y;
    Point(int a, int b) : x(a), y(b) {}

    Point(const Point &point) : x(point.x), y(point.y) { std::cout << "copy constructor!\n"; }
    Point(const Point &&point) : x(std::move(point.x)), y(std::move(point.y)) { std::cout << "move constructor!\n"; }
};

TEST(week_2_day_3, basic_scenario)
{
    [[maybe_unused]] MyClass<Point> p1(1, 2);

    [[maybe_unused]] MyClass<Point> p2 = myOwnMakeUnique<Point>(1, 2);
}

TEST(week_2_day_3, passing_lvalue_as_argument)
{
    Point p1{1, 2};
    [[maybe_unused]] MyClass<Point> p2 = myOwnMakeUnique<Point>(p1);
}

TEST(week_2_day_3, passing_rvalue_as_argument)
{
    [[maybe_unused]] MyClass<Point> p2 = myOwnMakeUnique<Point>(Point{1, 2});
}