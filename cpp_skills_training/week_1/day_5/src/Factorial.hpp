#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <type_traits>
#include <cassert>
#include <limits>

#pragma once

constexpr unsigned long long factorialIterative(unsigned n)
{
    // unsigned long long max = std::numeric_limits<unsigned long long>::max();

    if (n == 0)
        return 1;

    unsigned long long returnValue = 1;
    for (unsigned i = 1; i <= n; ++i)
    {
        returnValue *= i;
        // if (returnValue > max)
        // {
        //     throw std::overflow_error("unsigned long long overflow!");
        // }
    }

    return returnValue;
}
