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
    virtual std::string name() const override;

private:
    double width, height;
};

struct Circle : Shape
{
    virtual std::string name() const override;

private:
    double radius;
};

struct Square final : Rectangle
{
};

extern std::vector<std::unique_ptr<Shape>> shapes;
