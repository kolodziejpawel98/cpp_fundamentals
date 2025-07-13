#include <iostream>
#include <stdexcept>
#include <string>
#include "Vehicle.hpp"
#pragma once

class Car : public Vehicle
{
public:
    Car(std::string brand, std::string model, int year, int numberOfDoors) : Vehicle(brand, model, year), numberOfDoors(numberOfDoors)
    {
        if (numberOfDoors <= 0)
        {
            throw std::invalid_argument("Invalid 'numberOfDoors' argument.");
        }
    };
    int getNumberOfDoors() const { return numberOfDoors; }
    std::string printInfo() const override
    {
        return "placeholder Car\n";
    }

private:
    int numberOfDoors;
};

class Motorcycle : public Vehicle
{
public:
    Motorcycle(std::string brand, std::string model, int year, bool hasSidecar) : Vehicle(brand, model, year), hasSidecar(hasSidecar) {};
    bool getHasSideCar() const { return hasSidecar; }
    std::string printInfo() const override
    {
        return "placeholder Motorcycle\n";
    }

private:
    bool hasSidecar;
};

class Truck : public Vehicle
{
public:
    Truck(std::string brand, std::string model, int year, double maxLoadTons) : Vehicle(brand, model, year), maxLoadTons(maxLoadTons)
    {
        if (maxLoadTons < 0)
        {
            throw std::invalid_argument("Invalid 'maxLoadTons' argument.");
        }
    };
    double getMaxLoadTons() const { return maxLoadTons; }
    std::string printInfo() const override
    {
        return "placeholder Truck\n";
    }

private:
    double maxLoadTons;
};