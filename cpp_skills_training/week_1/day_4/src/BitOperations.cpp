#include "BitOperations.hpp"

[[nodiscard]] PermSet setPermissionToPermSet(PermSet permset, Permission permission) noexcept
{
    PermSet permissionAsPermSet = static_cast<PermSet>(permission);
    return permset | permissionAsPermSet;
}

[[nodiscard]] bool hasPermsetPermission(PermSet permset, Permission permission) noexcept
{
    PermSet permissionAsPermSet = static_cast<PermSet>(permission);
    PermSet extractingPermissionFromPermset = permset & permissionAsPermSet;
    return extractingPermissionFromPermset == permissionAsPermSet;
}