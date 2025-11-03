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
    template <typename... Args>
    MyClass(Args &&...args) : value(std::forward<Args>(args)...) {}

private:
    T value;
};

template <typename T, typename... Args>
inline MyClass<T> myOwnMakeUnique(Args &&...args)
{
    MyClass<T> myClassObject{std::forward<Args>(args)...};
    return myClassObject;
}