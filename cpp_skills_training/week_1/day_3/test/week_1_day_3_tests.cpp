#include <gtest/gtest.h>
#include "Shape.hpp"

TEST(week_1_day_3, names)
{
    Rectangle rectangle{2, 3};
    Circle circle{5};
    Square square{3};

    EXPECT_EQ(rectangle.name(), "Rectangle");
    EXPECT_EQ(circle.name(), "Circle");
    EXPECT_EQ(square.name(), "Square");
}

TEST(week_1_day_3, areas)
{
    Rectangle rectangle{2, 3};
    Circle circle{5};
    Square square{3};

    EXPECT_EQ(rectangle.area(), 6);
    EXPECT_EQ(circle.area(), 25 * std::numbers::pi);
    EXPECT_EQ(square.area(), 9);

    EXPECT_THROW((Rectangle{0, 0}), std::invalid_argument);
    EXPECT_THROW((Circle{-2}), std::invalid_argument);
    EXPECT_THROW((Square{-2}), std::invalid_argument);
}

TEST(week_1_day_3, shapePointer)
{
    std::unique_ptr<Shape> shape = std::make_unique<Rectangle>(4, 5);
    EXPECT_EQ(shape->name(), "Rectangle");

    shape = std::make_unique<Circle>(4);
    EXPECT_EQ(shape->name(), "Circle");

    shape = std::make_unique<Square>(4);
    EXPECT_EQ(shape->name(), "Square");
}

TEST(week_1_day_3, makeShape)
{
    shapes.push_back(makeShape(ShapeType::Rectangle, {2, 3}));
    shapes.push_back(makeShape(ShapeType::Circle, {2}));
    shapes.push_back(makeShape(ShapeType::Square, {3}));

    EXPECT_EQ(shapes.at(0)->name(), "Rectangle");
    EXPECT_EQ(shapes.at(0)->area(), 6);
    EXPECT_EQ(shapes.at(1)->name(), "Circle");
    EXPECT_EQ(shapes.at(1)->area(), 4 * std::numbers::pi);
    EXPECT_EQ(shapes.at(2)->name(), "Square");
    EXPECT_EQ(shapes.at(2)->area(), 9);
    shapes.clear();
}

// TODO:
// write test for wrong number of arguments for makeShape()
// change makeShape if-else -> switch