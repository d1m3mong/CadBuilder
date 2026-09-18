#include "geometry.hpp"
#include "../scene/object.hpp"

#include "raylib.h"
#include <vector>
#include <algorithm>

namespace CadBuilder
{
    boudingBox CadBuilder::computeBoundingBox(const std::vector<Vector3>& points) {
        boudingBox box;
        box.min = points[0];
        box.max = points[0];

        for (const Vector3& p : points) {
            box.min.x = std::min(box.min.x, p.x);
            box.min.y = std::min(box.min.y, p.y);
            box.min.z = std::min(box.min.z, p.z);

            box.max.x = std::max(box.max.x, p.x);
            box.max.y = std::max(box.max.y, p.y);
            box.max.z = std::max(box.max.z, p.z);
        }

        return box;
    }

    boudingBox CadBuilder::mergeBoudingBoxes(const boudingBox& b1, const boudingBox& b2);

    Vector3 CadBuilder::getCenter(const boudingBox& box);
    Vector3 CadBuilder::getExtents(const boudingBox& box);
    Vector3 CadBuilder::getSize(const boudingBox& box);

    std::array<Vector3, 8> getObjectCorners(const Object& object) {
        Vector3 size = object.transform.size;

        float x = size.x / 2.0f;
        float y = size.y / 2.0f;
        float z = size.z / 2.0f;

        std::array<Vector3, 8> points = {
            Vector3{ -x, -y, -z },
            Vector3{  x, -y, -z },
            Vector3{ -x,  y, -z },
            Vector3{  x,  y, -z },
            Vector3{ -x, -y,  z },
            Vector3{  x, -y,  z },
            Vector3{ -x,  y,  z },
            Vector3{  x,  y,  z }
        };

        return points;
    }
} 
