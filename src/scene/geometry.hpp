#pragma once

#include "../scene/object.hpp"

#include "raylib.h"
#include <vector>
#include <array>

namespace CadBuilder
{
    struct boudingBox
    {
        Vector3 min;
        Vector3 max;
    };
    
    boudingBox computeBoundingBox(const std::vector<Vector3>& points);

    boudingBox mergeBoudingBoxes(const boudingBox& b1, const boudingBox& b2);

    Vector3 getCenter(const boudingBox& box);
    Vector3 getExtents(const boudingBox& box);
    Vector3 getSize(const boudingBox& box);

    std::array<Vector3, 8> getObjectCorners(const Object& object);
} 
