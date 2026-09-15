#include "raylib.h"
#include "renderer/renderer.hpp"
#include "scene/beam.hpp"
#include "input/objectController.hpp"

int main()
{
    Camera3D camera{};
    camera.position = {10.0f, 10.0f, 10.0f};
    camera.target = {0.0f, 0.0f, 0.0f};
    camera.up = {0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    CadBuilder::Beam beam;

    beam.transform.position = {0.0f, 0.0f, 0.0f};
    beam.transform.size = {5.0f, 5.0f, 5.0f};
    beam.transform.rotation = {0.0f, 0.0f, 0.0f};

    CadBuilder::Renderer renderer(camera);
    CadBuilder::objectController controller;

    renderer.initialize();

    while (!WindowShouldClose())
    {
        renderer.beginFrame();
        
        controller.update(beam);
        
        renderer.draw(beam);

        //DrawText("Cad Builder", 0, 0, 30, GRAY);

        renderer.endFrame();
    }

    CloseWindow();
}