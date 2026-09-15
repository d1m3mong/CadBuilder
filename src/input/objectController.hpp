#pragma once

#include "raylib.h"
#include "../scene/object.hpp"

namespace CadBuilder {
    class objectController
    {
    private:
        bool rotationState = false;
    public:
        void update(Object& object);
    };
}