#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>

#pragma once

struct Shape
{
    virtual std::string name() const;
    virtual double area() const = 0;
    virtual ~Shape();
};

struct Rectangle : Shape
{
    Rectangle(double, double);
    virtual std::string name() const override;
    virtual double area() const override;

private:
    double width, height;
};

struct Circle : Shape
{
    Circle(double);
    virtual std::string name() const override;
    virtual double area() const override;

private:
    double radius;
};

// struct Square final : Rectangle
// {
//     Square() {};
// };

extern std::vector<std::unique_ptr<Shape>>
    shapes;

std::unique_ptr<Shape> makeShape(double, double);
std::unique_ptr<Shape> makeShape(double);
// std::unique_ptr<Shape> makeShape();