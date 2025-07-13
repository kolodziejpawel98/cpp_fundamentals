#include <gtest/gtest.h>
#include "Vehicles.hpp"
#include "ServiceCenter.hpp"
#include <sstream>
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
    serviceCenter.addVehicle(new Car("Toyota", "Corolla", 2015, 4));
    serviceCenter.addVehicle(new Motorcycle("Suzuki", "xyz", 2011, true));
    serviceCenter.addVehicle(new Truck("Volvo", "xyz", 2011, 0.1));
    std::string output = "placeholder Car\nplaceholder Motorcycle\nplaceholder Truck\n";
    EXPECT_EQ(serviceCenter.printAll(), output);
}