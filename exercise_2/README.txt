🧠 Task: Vehicle Hierarchy and Service Center
🎯 Goal:

Create a class hierarchy representing different types of vehicles, apply inheritance, polymorphism, and use virtual destructors.
📋 Task Description:

Design a class hierarchy representing various vehicles that can be registered in a service center.
1. Base Class: Vehicle

Contains:

    std::string brand — vehicle brand

    std::string model

    int year

Also includes:

    A virtual method void printInfo() const — prints vehicle details

    A virtual destructor (!)

2. Derived Classes: Car, Motorcycle, Truck

Each inherits from Vehicle, adds its own field, and overrides printInfo():

    Car

        int numberOfDoors

    Motorcycle

        bool hasSidecar

    Truck

        double maxLoadTons

3. Class ServiceCenter

Stores vehicles using a vector of pointers: std::vector<Vehicle*>

    Method addVehicle(Vehicle*) — adds a vehicle to the system

    Method printAll() — prints all vehicles (via polymorphism!)

    Destructor — deletes all pointers (simulates memory management)

✅ Technical Requirements:

    Use polymorphism in the printInfo() method

    Ensure destructors are virtual to avoid memory leaks

    Finally, test everything in the main() function:

        Create 2–3 objects of different classes

        Add them to ServiceCenter

        Call printAll()

🔁 Optional Extensions:

    Replace raw pointers with std::unique_ptr<Vehicle>

    Add a function to remove a vehicle by ID

    Use typeid or dynamic_cast to check a vehicle's actual type