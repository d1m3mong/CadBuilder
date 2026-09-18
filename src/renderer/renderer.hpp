#pragma once 

#include "raylib.h"
#include "../math/rotation.hpp"
#include "../scene/object.hpp"

namespace CadBuilder {
    class Renderer {
        public:

        void initialize();
        void beginFrame();
        void endFrame();

        Renderer(const Camera3D& cam);

        void draw(const Object& object);
        const Camera3D getCamera() const;

        private:

        Camera3D camera{};
    };

    Vector3 transformPoint(Vector3 point, Vector3 position, Vector3 rotation);
}