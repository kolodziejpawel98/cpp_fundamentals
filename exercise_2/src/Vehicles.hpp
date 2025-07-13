#include <iostream>
#include <stdexcept>
#include <string>
#include "Vehicle.hpp"
#pragma once

class Car : public Vehicle
{
public:
    Car(std::string brand, std::string model, int year, int numberOfDoors) : Vehicle(brand, model, year), numberOfDoors(numberOfDoors) {};
    int numberOfDoors;
    int &getNumberOfDoors() { return numberOfDoors; }
    void printInfo()
    {
        std::cout << "placeholder" << std::endl;
    }
};

class Motocycle : public Vehicle
{
public:
    Motocycle(std::string brand, std::string model, int year, bool hasSidecar) : Vehicle(brand, model, year), hasSidecar(hasSidecar) {};
    bool hasSidecar;
    bool &getHasSideCar() { return hasSidecar; }
    void printInfo()
    {
        std::cout << "placeholder" << std::endl;
    }
};

class Truck : public Vehicle
{
public:
    Truck(std::string brand, std::string model, int year, double maxLoadTons) : Vehicle(brand, model, year), maxLoadTons(maxLoadTons) {};
    double maxLoadTons;
    double &getMaxLoadTons() { return maxLoadTons; }
    void printInfo()
    {
    }
};