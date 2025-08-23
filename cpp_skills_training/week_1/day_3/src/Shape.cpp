#include "Shape.hpp"

std::vector<std::unique_ptr<Shape>> shapes;

Shape::~Shape() = default;

std::string Shape::name() const { return "Shape"; }

Rectangle::Rectangle(double width, double height) : width(width), height(height)
{
    if (width <= 0.0 || height <= 0.0)
    {
        throw std::invalid_argument("Wrong arguments!");
    }
}

Circle::Circle(double radius) : radius(radius)
{
    if (radius <= 0.0)
    {
        throw std::invalid_argument("Wrong arguments!");
    }
}

Square::Square(double width) : Rectangle(width, width) {};

std::string Rectangle::name() const
{
    return "Rectangle";
}

std::string Circle::name() const
{
    return "Circle";
}

std::string Square::name() const
{
    return "Square";
}

double Rectangle::area() const
{
    return width * height;
}

double Circle::area() const
{
    return radius * radius * PI;
}

std::unique_ptr<Shape> makeShape(ShapeType shapeType, std::initializer_list<double> parameters)
{
    if (shapeType == ShapeType::Rectangle && parameters.size() == 2)
    {
        auto iterator = parameters.begin();
        return std::make_unique<Rectangle>(*iterator, *(iterator + 1));
    }
    else if (shapeType == ShapeType::Circle && parameters.size() == 1)
    {
        return std::make_unique<Circle>(*parameters.begin());
    }
    else if (shapeType == ShapeType::Square && parameters.size() == 1)
    {
        return std::make_unique<Square>(*parameters.begin());
    }
    else
    {
        throw std::invalid_argument("Wrong number of arguments!");
    }
}
