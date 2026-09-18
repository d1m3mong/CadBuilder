#pragma once

#include "transform.hpp"
#include "string"

namespace CadBuilder {
    struct Object
    {
        Transform transform;
        std::string_view name;
    };
    
}