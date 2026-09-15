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

        private:

        Camera3D camera{};
    };
}