#include "Shape.hpp"

std::vector<std::unique_ptr<Shape>> shapes;

Shape::~Shape() = default;

std::string Shape::name() const { return "Shape"; }

Rectangle::Rectangle(double width, double height) : width(width), height(height) {}

std::string Rectangle::name() const
{
    return "Rectangle";
}

Circle::Circle(double radius) : radius(radius) {}

std::string Circle::name() const
{
    return "Circle";
}

double Rectangle::area() const
{
    return width * height;
}

double Circle::area() const
{
    return radius * radius * 3.14;
}

std::unique_ptr<Shape> makeShape(double width, double height)
{
    std::unique_ptr<Rectangle> rectangle = std::make_unique<Rectangle>(width, height);
    return rectangle;
}

std::unique_ptr<Shape> makeShape(double radius)
{
    std::unique_ptr<Circle> circle = std::make_unique<Circle>(radius);
    return circle;
}

// std::unique_ptr<Shape> makeShape()
// {
//     std::unique_ptr<Square> square = std::make_unique<Square>();
//     return square;
// }