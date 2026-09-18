#include <iostream>
#include "raylib.h"

#include "objectController.hpp"

#include "../scene/object.hpp"

constexpr float speedMovement = 1.0f;
constexpr float speedRotation = 90.0f;

namespace CadBuilder {
    void objectController::update(Object& object) {
        if (IsKeyDown(KEY_W))
        {
            if (rotationState == true) {
                object.transform.rotation.x += -speedRotation * GetFrameTime();
            } else {
                object.transform.position.y += speedMovement * GetFrameTime();
            }
        }

        if (IsKeyDown(KEY_S))
        {
            if (rotationState) {
                object.transform.rotation.x += speedRotation * GetFrameTime();
            } else {
                object.transform.position.y += -speedMovement * GetFrameTime();
            }
        }

        if (IsKeyDown(KEY_D))
        {
            if (rotationState) {
                object.transform.rotation.y += speedRotation * GetFrameTime();
            } else {
                object.transform.position.x += speedMovement * GetFrameTime();
            }
        }

        if (IsKeyDown(KEY_A))
        {
            if (rotationState) {
                object.transform.rotation.y += -speedRotation * GetFrameTime();
            } else {
                object.transform.position.x += -speedMovement * GetFrameTime();
            }
        }

        if (IsKeyDown(KEY_Q))
        {
            object.transform.rotation.z += speedRotation * GetFrameTime();
        }

        if (IsKeyDown(KEY_E))
        {
            object.transform.rotation.z += -speedRotation * GetFrameTime();
        }

        if(IsKeyPressed(KEY_R)) {
            rotationState = !rotationState;
        }
    }
}