#include <iostream>
#include <stdexcept>
#include <string>
#include <memory>
#include <vector>
#include "Vehicles.hpp"
#pragma once

class ServiceCenter
{
public:
    ServiceCenter() = default;
    void addVehicle(std::unique_ptr<Vehicle> vehicle)
    {
        if (vehicle)
        {
            vehicles.push_back(std::move(vehicle));
        }
        else
        {
            throw std::invalid_argument("Vehicle is nullptr");
        }
    }

    std::string printAll() const

    {
        std::string output = "";
        for (auto &vehicle : vehicles)
        {
            output += vehicle->printInfo();
        }
        return output;
    }

    int getVehiclesSize() const
    {
        return vehicles.size();
    }
    ~ServiceCenter() = default;

private:
    std::vector<std::unique_ptr<Vehicle>> vehicles;
};