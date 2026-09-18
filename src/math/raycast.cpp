#include "raylib.h"
#include "raycast.hpp"

#include "../scene/object.hpp"
#include "../scene/geometry.hpp"
#include "../renderer/renderer.hpp"

#include <limits>
#include <algorithm>
#include <vector>
#include <optional>

namespace CadBuilder {
    std::optional<float> CadBuilder::intersectAABB(
        const Ray& ray,
        const Vector3& min,
        const Vector3& max
    ) {
        float tMin = -std::numeric_limits<float>::infinity();
        float tMax = std::numeric_limits<float>::infinity();

        const float originArr[3] = {ray.position.x, ray.position.y, ray.position.z};
        const float dirArr[3] = {ray.direction.x, ray.direction.y, ray.direction.z};
        const float minArr[3] = {min.x, min.y, min.z};
        const float maxArr[3] = {max.x, max.y, max.z};

        for (int axis = 0; axis < 3; ++axis) {
            float origin = originArr[axis];
            float direction = dirArr[axis];
            float boxMin = minArr[axis];
            float boxMax = maxArr[axis];

            if (std::abs(direction) < 1e-8f) {
                if (origin < boxMin || origin > boxMax) {
                    return std::nullopt;
                } 
                
                continue;
            }

            float inv = 1.0f / direction;
            
            float t1 = (boxMin - origin) * inv;
            float t2 = (boxMax - origin) * inv;

            if (t1 > t2) {
                std::swap(t1, t2);
            }

            tMin = std::max(tMin, t1);
            tMax = std::min(tMax, t2);

            if (tMin > tMax) {
                return std::nullopt;
            }
        }

        if (tMax < 0.0f) {
            return std::nullopt;
        }

        return tMax >= 0.0f ? tMin : tMax;
    }

    rayResult CadBuilder::createRay(const Camera3D& camera, Vector2 mousePos, std::vector<Object*>& objects) {
        Ray ray = GetMouseRay(mousePos, camera);

        for (Object* object : objects) {
            auto points = CadBuilder::getObjectCorners(*object);

            for (auto& point : points) {
                point = CadBuilder::transformPoint(point, object->transform.position, object->transform.rotation);
            }

            auto box = computeBoundingBox(std::vector<Vector3>(points.begin(), points.end()));

            auto t = intersectAABB(ray, box.min, box.max);

            if(t.has_value()) {
                float tValue = t.value();

                Vector3 hitPoint = {
                    ray.position.x + ray.direction.x * tValue,
                    ray.position.y + ray.direction.y * tValue,
                    ray.position.z + ray.direction.z * tValue
                };

                return {object, hitPoint};
            }
        }

        return {nullptr, {}};  
    }
}
