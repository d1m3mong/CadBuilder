#pragma once

#include "../scene/object.hpp"
#include <vector>

namespace CadBuilder {
    class MouseInput {
        public:

        void initializeMouse(const Camera3D& camera, std::vector<Object*>& objects);
        void startInput();
        void endInput();

        private:

        Object* selected = nullptr;
        const Camera3D* camera = nullptr;
        std::vector<Object*>* objects = nullptr;
    };
}