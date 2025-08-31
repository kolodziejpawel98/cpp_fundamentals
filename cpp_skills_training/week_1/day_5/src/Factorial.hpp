#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <type_traits>
#include <cassert>
#include <limits>

#pragma once

template <unsigned n>
constexpr unsigned long long factorialIterative()
{
    static_assert(n <= 20, "Argument produces too large factorial result for unsigned long long! (or you passed nagative number).");

    if (n == 0)
        return 1;

    unsigned long long result = 1;

    for (unsigned i = 1; i <= n; ++i)
    {
        result *= i;
    }

    return result;
}

inline unsigned long long factorialRecursive(unsigned n)
{
    if (n > 20)
        throw std::overflow_error("Argument produces too large factorial result for unsigned long long! (or you passed nagative number).");

    unsigned long long result = 1;
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        result = factorialRecursive(n - 1);
    }
    result *= n;
    return result;
}
