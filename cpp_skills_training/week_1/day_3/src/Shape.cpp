#include "Shape.hpp"

std::vector<std::unique_ptr<Shape>> shapes;

Shape::~Shape() = default;

std::string Shape::name() const { return "Shape"; }

std::string Rectangle::name() const
{
    return "Rectangle";
}

std::string Circle::name() const
{
    return "Circle";
}