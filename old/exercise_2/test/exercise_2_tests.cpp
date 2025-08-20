#include <gtest/gtest.h>
#include "Vehicles.hpp"
#include "ServiceCenter.hpp"
#include <sstream>
#include <memory>
#include <typeinfo>

TEST(VehicleTest, getterMethods)
{
    Car car("Toyota", "Corolla", 2015, 4);
    EXPECT_EQ(car.getBrand(), "Toyota");
    EXPECT_EQ(car.getModel(), "Corolla");
    EXPECT_EQ(car.getYear(), 2015);
    EXPECT_EQ(car.getNumberOfDoors(), 4);

    Motorcycle motorcycle("Suzuki", "xyz", 2011, true);
    EXPECT_EQ(motorcycle.getBrand(), "Suzuki");
    EXPECT_EQ(motorcycle.getModel(), "xyz");
    EXPECT_EQ(motorcycle.getYear(), 2011);
    EXPECT_EQ(motorcycle.getHasSideCar(), true);

    Truck truck("Volvo", "xyz", 2011, 0.1);
    EXPECT_EQ(truck.getBrand(), "Volvo");
    EXPECT_EQ(truck.getModel(), "xyz");
    EXPECT_EQ(truck.getYear(), 2011);
    EXPECT_EQ(truck.getMaxLoadTons(), 0.1);
}

TEST(VehicleTest, negativeYear)
{
    EXPECT_THROW(
        {
            Car car("Toyota", "Corolla", -123, 4);
        },
        std::invalid_argument);
}

TEST(VehicleTest, serviceCenter)
{
    ServiceCenter serviceCenter{};
    serviceCenter.addVehicle(std::make_unique<Car>("Toyota", "Corolla", 2015, 4));
    serviceCenter.addVehicle(std::make_unique<Motorcycle>("Suzuki", "xyz", 2011, true));
    serviceCenter.addVehicle(std::make_unique<Truck>("Volvo", "xyz", 2011, 0.1));
    std::string output = "placeholder Car\nplaceholder Motorcycle\nplaceholder Truck\n";
    EXPECT_EQ(serviceCenter.printAll(), output);
}

TEST(VehicleTest, checkAddingPointerTwoTimes)
{
    ServiceCenter serviceCenter{};
    std::unique_ptr<Vehicle> car = std::make_unique<Car>("Toyota", "Corolla", 2015, 4);
    serviceCenter.addVehicle(std::move(car));
    EXPECT_TRUE(car == nullptr);
    EXPECT_EQ(serviceCenter.getVehiclesSize(), 1);
    EXPECT_THROW(
        {
            serviceCenter.addVehicle(std::move(car));
        },
        std::invalid_argument);
}

TEST(VehicleTest, checkingDynamicCast)
{
    std::unique_ptr<Vehicle> car = std::make_unique<Car>("Toyota", "Corolla", 2015, 4);
    std::unique_ptr<Vehicle> motorcycle = std::make_unique<Motorcycle>("Suzuki", "xyz", 2011, true);
    std::unique_ptr<Vehicle> truck = std::make_unique<Truck>("Volvo", "xyz", 2011, 0.1);
    Vehicle *carPtr = car.get();
    Vehicle *motorcyclePtr = motorcycle.get();
    Vehicle *truckPtr = truck.get();
    ASSERT_NE(dynamic_cast<Car *>(carPtr), nullptr);
    ASSERT_EQ(dynamic_cast<Motorcycle *>(carPtr), nullptr);
    ASSERT_EQ(dynamic_cast<Truck *>(carPtr), nullptr);
}