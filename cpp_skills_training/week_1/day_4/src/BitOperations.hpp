#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>

#pragma once
enum class Status : uint8_t
{
    Ok,
    Warn,
    Error
};
enum class Permission : uint8_t
{
    Read = 1u << 0,  // 0 0 0 0 0 0 0 1
    Write = 1u << 1, // 0 0 0 0 0 0 1 0
    Exec = 1u << 2   // 0 0 0 0 0 1 0 0
};

// auto p = Permission::Read | Permission::Write;

constexpr Permission operator|(Permission a, Permission b) noexcept
{
    uint8_t first = static_cast<uint8_t>(a);
    uint8_t second = static_cast<uint8_t>(b);
    uint8_t third = first | second;
    // return a;
}

// constexpr Permission operator|=(Permission a, Permission b) noexcept
// {
// }