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

using PermSet = uint8_t;

enum class Permission : PermSet
{
    Read = 1u << 0,  // 0 0 0 0 0 0 0 1
    Write = 1u << 1, // 0 0 0 0 0 0 1 0
    Exec = 1u << 2   // 0 0 0 0 0 1 0 0
};

[[nodiscard]] constexpr Permission operator|(Permission a, Permission b) noexcept
{
    using T = std::underlying_type_t<Permission>;
    return static_cast<Permission>(static_cast<T>(a) | static_cast<T>(b));
}

constexpr Permission &operator|=(Permission &a, Permission b) noexcept
{
    using T = std::underlying_type_t<Permission>;
    a = static_cast<Permission>(static_cast<T>(a) | static_cast<T>(b));
    return a;
}

[[nodiscard]] PermSet setPermissionToPermSet(PermSet permset, Permission permission) noexcept;

[[nodiscard]] bool hasPermsetPermission(PermSet permset, Permission permission) noexcept;
