#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <optional>
#include <vector>
#include <algorithm>

#pragma once



inline void print()
{
    std::cout << "I am empty function and "
            "I am called at last.\n";
}


template <typename T, typename... Types>
void print(T var1, Types... var2)
{
    std::cout << var1 << std::endl;

    print(var2...);
}

template <typename... Types>
void foo(Types... var2)
{
  ((std::cout << var2 << std::endl), ...);
}

