#include "rotation.hpp"
#include "raylib.h"

#include <cmath>

namespace CadBuilder
{
   Vector3 rotateX(Vector3 point, float angle)
    {
        float rad = angle * (PI / 180);

        float cosA = std::cosf(rad);
        float sinA = std::sinf(rad);

        return {
            point.x,
            point.y * cosA - point.z * sinA,
            point.y * sinA + point.z * cosA
        };
    }
    Vector3 rotateY(Vector3 point, float angle)
    {
        float rad = angle * (PI / 180);

        float cosA = std::cosf(rad);
        float sinA = std::sinf(rad);

        return {
            point.x * cosA + point.z * sinA,
            point.y,
            -point.x * sinA + point.z * cosA
        };
    }
    Vector3 rotateZ(Vector3 point, float angle) {
        float rad = angle * (PI / 180);

        float cosA = std::cosf(rad);
        float sinA = std::sinf(rad);

        return {
            point.x * cosA - point.y * sinA, 
            point.x * sinA + point.y * cosA,
            point.z
        };
    }
}