#include <iostream>

#include "objectController.hpp"

#include "../scene/object.hpp"

namespace CadBuilder {
    void objectController::update(Object& object) {
        if (IsKeyDown(KEY_W))
        {
            if (rotationState == true) {
                object.transform.rotation.y += 0.1f;
            } else {
                object.transform.position.y += 0.0001f;
            }
        }

        if (IsKeyDown(KEY_S))
        {
            if (rotationState) {
                object.transform.rotation.y += -0.1f;
            } else {
                object.transform.position.y += -0.0001f;
            }
        }

        if (IsKeyDown(KEY_D))
        {
            if (rotationState) {
                object.transform.rotation.z += 0.1f;
            } else {
                object.transform.position.x += 0.0001f;
            }
        }

        if (IsKeyDown(KEY_A))
        {
            if (rotationState) {
                object.transform.rotation.z += -0.1f;
            } else {
                object.transform.position.x += -0.0001f;
            }
        }

        if(IsKeyPressed(KEY_R)) {
            rotationState = !rotationState;
        }
    }
}