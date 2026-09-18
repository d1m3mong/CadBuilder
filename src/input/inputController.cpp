#include "inputController.hpp"
#include "../math/raycast.hpp"

#include "../scene/object.hpp"
#include <vector>
#include <iostream>

#include "raylib.h"

//auto result = CadBuilder::createRay(camera, GetMousePosition(), objects);

namespace CadBuilder {
    void MouseInput::initializeMouse(const Camera3D& camera,std::vector<Object*>& objects) {
        this->camera = &camera;
        this->objects = &objects;
    }

    void MouseInput::startInput() {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 mousePos = GetMousePosition();

            rayResult result = CadBuilder::createRay(*camera, mousePos, *objects);
            if (result.hit == nullptr) return;

            selected = result.hit;

            std::cout << "selected: " << selected->name << " at position: [" << 
                result.position.x << " " << result.position.y << " " << result.position.z << 
            "]" << std::endl;
        }
    }

    void MouseInput::endInput() {
        
    }
}

