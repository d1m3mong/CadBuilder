#include "rotation.hpp"
#include "raylib.h"

#include <cmath>

namespace CadBuilder
{
    Vector3 rotateX(Vector3 point, float angle) {
        return {};
    }
    Vector3 rotateY(Vector3 point, float angle) {
        float rad = angle * (PI / 180);

        return {
            point.x * cosf(rad) + point.z * sinf(rad),
            point.y,
            -point.x * sinf(rad) + point.z * cosf(rad)
        };
    }
    Vector3 rotateZ(Vector3 point, float angle) {
        return {};
    }
}