#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <optional>
#include <vector>
#include <algorithm>

#pragma once

template <typename T>
class MyClass
{
public:
    MyClass(Args &&...args) : value(std::forward<Args>(args)...) {}

    // dzieki temu to zadziala
    //     struct Point {
    //     int x, y;
    //     Point(int a, int b) : x(a), y(b) {}
    // };

    // int main() {
    //     MyClass<Point> p1(1, 2);
    //     MyClass<Point> p2;
    // }

    // void print()
    // {
    //     std::cout << "a = " << a << std::endl;
    // }

private:
    T value;
};

// template <typename T>
// inline MyClass myOwnMakeUnique(T a)
// {
//     MyClass myClassObject{a};
//     return myClassObject;
// }

// template <typename... Args>
// inline void myOwnMakeUnique(const Args &...args)
// {
//     (std::cout << ... << args) << '\n';
// }

template <typename... Args>
inline void myOwnMakeUnique(Args &&...args)
{
    MyClass myClassObject{std::forward<Args>(args)...};
    // return myClassObject;
}