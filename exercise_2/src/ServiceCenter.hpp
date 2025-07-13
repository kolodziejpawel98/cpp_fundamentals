#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Vehicles.hpp"
#pragma once

class ServiceCenter
{
public:
    ServiceCenter() = default;
    void addVehicle(Vehicle *vehicle) // smart pointers needed, I know
    {
        vehicles.push_back(vehicle);
    }

    std::string printAll()
    {
        std::string output = "";
        for (auto &vehicle : vehicles)
        {
            output += vehicle->printInfo();
        }
        return output;
    }

    ~ServiceCenter()
    {
        for (auto &vehicle : vehicles)
        {
            delete vehicle;
            vehicle = nullptr;
        }
    };

private:
    std::vector<Vehicle *> vehicles;
};