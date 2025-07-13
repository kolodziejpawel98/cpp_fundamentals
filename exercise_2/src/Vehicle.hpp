#include <iostream>
#include <stdexcept>
#include <string>
#include <format>
#include <chrono>
#pragma once

class Vehicle
{
public:
    Vehicle(std::string brand, std::string model, int year) : brand(brand), model(model), year(year)
    {
        if (year < 0 || year > 2025)
        {
            throw std::invalid_argument("Invalid 'year' argument");
        }
    }
    virtual std::string printInfo() const = 0;
    std::string getBrand() const { return brand; }
    std::string getModel() const { return model; }
    int getYear() const { return year; }
    virtual ~Vehicle() = default;

private:
    std::string brand;
    std::string model;
    int year;
};