#include <gtest/gtest.h>
#include "Vehicles.hpp"
#include <sstream>
#include <typeinfo>

TEST(VehicleTest, getterMethods)
{
    Car car("Toyota", "Corolla", 2015, 4);
    EXPECT_EQ(car.getBrand(), "Toyota");
    EXPECT_EQ(car.getModel(), "Corolla");
    EXPECT_EQ(car.getYear(), 2015);
    EXPECT_EQ(car.getNumberOfDoors(), 4);

    Motocycle motocycle("Suzuki", "xyz", 2011, true);
    EXPECT_EQ(motocycle.getBrand(), "Suzuki");
    EXPECT_EQ(motocycle.getModel(), "xyz");
    EXPECT_EQ(motocycle.getYear(), 2011);
    EXPECT_EQ(motocycle.getHasSideCar(), true);

    Truck truck("Volvo", "xyz", 2011, 0.1);
    EXPECT_EQ(truck.getBrand(), "Volvo");
    EXPECT_EQ(truck.getModel(), "xyz");
    EXPECT_EQ(truck.getYear(), 2011);
    EXPECT_EQ(truck.getMaxLoadTons(), 0.1);
}