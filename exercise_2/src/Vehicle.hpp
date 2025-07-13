#include <iostream>
#include <stdexcept>
#include <string>
#pragma once

class Vehicle
{
public:
    Vehicle(std::string brand, std::string model, int year) : brand(brand), model(model), year(year) {}
    std::string brand;
    std::string model;
    int year;
    virtual void printInfo() = 0;
    std::string &getBrand() { return brand; }
    std::string &getModel() { return model; }
    int &getYear() { return year; }
    virtual ~Vehicle() {};
};