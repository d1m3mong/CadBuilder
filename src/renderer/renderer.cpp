#include "renderer.hpp"
#include "../math/rotation.hpp"
#include "../scene/object.hpp"

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

        float x = size.x / 2.0f;
        float y = size.y / 2.0f;
        float z = size.z / 2.0f;

        std::array<Vector3, 8> points = {
            Vector3{ -x, -y, -z },
            Vector3{  x, -y, -z },
            Vector3{ -x,  y, -z },
            Vector3{  x,  y, -z },
            Vector3{ -x, -y,  z },
            Vector3{  x, -y,  z },
            Vector3{ -x,  y,  z },
            Vector3{  x,  y,  z }
        };

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

    Renderer::Renderer(const Camera3D& cam)
        : camera(cam)
    {
    }
}