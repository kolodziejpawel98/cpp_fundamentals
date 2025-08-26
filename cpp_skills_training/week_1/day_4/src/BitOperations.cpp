#include "BitOperations.hpp"

PermSet set(PermSet permset, Permission permission)
{
    PermSet permissionAsPermSet = static_cast<PermSet>(permission);
    return permset | permissionAsPermSet;
}
