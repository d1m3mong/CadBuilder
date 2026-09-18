#pragma once

#include "raylib.h"
#include "../scene/object.hpp"
#include <vector>
#include <optional>

namespace CadBuilder {
    struct rayResult
    {
        Object* hit = nullptr;
        Vector3 position{};
    };
    
    
    std::optional<float> intersectAABB(
        const Ray& ray,
        const Vector3& min,
        const Vector3& max
    );

    rayResult createRay(const Camera3D& camera, Vector2 mousePos, std::vector<Object*>& objects);
}