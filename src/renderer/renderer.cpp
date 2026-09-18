#include "renderer.hpp"
#include "../math/rotation.hpp"
#include "../scene/object.hpp"
#include "../scene/geometry.hpp"

#include <array>

namespace CadBuilder
{
    void Renderer::initialize()
    {
        InitWindow(1280, 720, "Cad Builder 3D-Engine");
    }

    void Renderer::beginFrame()
    {
        BeginDrawing();
        ClearBackground(BLACK);
        BeginMode3D(camera);
    }

    void Renderer::endFrame()
    {
        EndMode3D();
        EndDrawing();
    }

    Vector3 transformPoint(Vector3 point, Vector3 position, Vector3 rotation) {
        Vector3 rotated = CadBuilder::rotateY(point, rotation.y);
        rotated = CadBuilder::rotateX(rotated, rotation.x);
        rotated = CadBuilder::rotateZ(rotated, rotation.z);

        Vector3 worldPos = {
            rotated.x + position.x,
            rotated.y + position.y,
            rotated.z + position.z
        };

        return worldPos;
    }

    void Renderer::draw(const Object& object) {
        Vector3 position = object.transform.position;
        Vector3 size = object.transform.size;
        Vector3 rotation = object.transform.rotation;

        std::array<Vector3, 8> points = CadBuilder::getObjectCorners(object);

        for (auto& point : points) {
            point = transformPoint(point, position, rotation);

            DrawSphere(point, 0.1f, RED);
        }
        
        std::array<std::pair<int, int>, 12> edges = {
            std::pair{0, 1},
            std::pair{0, 2},
            std::pair{0, 4},

            std::pair{1, 3},
            std::pair{1, 5},

            std::pair{2, 3},
            std::pair{2, 6},

            std::pair{3, 7},
            
            std::pair{4, 5},
            std::pair{4, 6},

            std::pair{5, 7},
            
            std::pair{6, 7},
        };

        for (auto [a, b] : edges) {
            DrawLine3D(points[a], points[b], RED);
        }

    }

    const Camera3D Renderer::getCamera() const {
        return camera;
    }

    Renderer::Renderer(const Camera3D& cam)
        : camera(cam)
    {
    }
}