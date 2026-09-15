#include "beam.hpp"
#include "raylib.h"

namespace CadBuilder {
    void Beam::move(const Vector3& moveOffset) {
        transform.position.x += moveOffset.x;
        transform.position.y += moveOffset.y;
        transform.position.z += moveOffset.z;
    }

    void Beam::rotate(const Vector3& rotationAmount) {
        transform.rotation.x += rotationAmount.x;
        transform.rotation.y += rotationAmount.y;
        transform.rotation.z += rotationAmount.z;
    }
}