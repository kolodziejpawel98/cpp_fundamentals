#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <type_traits>

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
    using T = std::underlying_type_t<Permission>;
    return static_cast<Permission>(static_cast<T>(a) | static_cast<T>(b));
}

// constexpr Permission operator|=(Permission a, Permission b) noexcept
// {
// }