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

Square::Square(double width) : Rectangle(width, width) {};

std::unique_ptr<Shape> makeShape(ShapeType shapeType, std::initializer_list<double> parameters)
{
    if (shapeType == ShapeType::Rectangle)
    {
        auto iterator = parameters.begin();
        std::unique_ptr<Rectangle> rectangle = std::make_unique<Rectangle>(*iterator, *(iterator + 1));
        return rectangle;
    }
    else if (shapeType == ShapeType::Circle)
    {
        std::unique_ptr<Circle> circle = std::make_unique<Circle>(*parameters.begin());
        return circle;
    }
    else
    {
        std::unique_ptr<Square> square = std::make_unique<Square>(*parameters.begin());
        return square;
    }
}
