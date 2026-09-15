#pragma once

#include "raylib.h"
#include "transform.hpp"
#include "object.hpp"

namespace CadBuilder {
    struct Beam : Object
    {
        void rotate(const Vector3& rotationAmount);
        void move(const Vector3& moveOffset);
    };
}