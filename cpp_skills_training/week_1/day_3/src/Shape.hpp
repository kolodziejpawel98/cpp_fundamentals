#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>

#pragma once

struct Shape
{
    Shape() = default;
    virtual std::string name() const;
    virtual double area() const = 0;
    virtual ~Shape();
};

struct Rectangle : Shape
{
    Rectangle(double, double);
    std::string name() const override;
    double area() const override;

private:
    double width, height;
};

struct Circle : Shape
{
    explicit Circle(double);
    std::string name() const override;
    double area() const override;

private:
    double radius;
};

struct Square final : Rectangle
{
    explicit Square(double);
    std::string name() const override;
};

enum class ShapeType
{
    Rectangle,
    Circle,
    Square
};

extern std::vector<std::unique_ptr<Shape>> shapes;

std::unique_ptr<Shape> makeShape(ShapeType, std::initializer_list<double>);