#include <iostream>
#include <vector>

#include "raylib.h"
#include "renderer/renderer.hpp"
#include "scene/beam.hpp"
#include "input/objectController.hpp"
#include "input/inputController.hpp"
#include "scene/object.hpp"

int main()
{
    std::vector<CadBuilder::Object*> objects;

    Camera3D camera{};
    camera.position = {0.0f, 10.0f, 10.0f};
    camera.target = {0.0f, 0.0f, 0.0f};
    camera.up = {0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    CadBuilder::Beam beam;

    beam.transform.position = {0.0f, 0.0f, 0.0f};
    beam.transform.size = {5.0f, 5.0f, 5.0f};
    beam.transform.rotation = {0.0f, 0.0f, 0.0f};

    beam.name = "Block";
    
    objects.push_back(&beam);

    CadBuilder::Renderer renderer(camera);
    CadBuilder::objectController controller;
    CadBuilder::MouseInput mouseInput;

    renderer.initialize();
    mouseInput.initializeMouse(camera, objects);

    while (!WindowShouldClose())
    {
        renderer.beginFrame();
        mouseInput.startInput();
        
        controller.update(beam);
        
        renderer.draw(beam);

        //DrawText("Cad Builder", 0, 0, 30, GRAY);

        renderer.endFrame();
        mouseInput.endInput();
    }

    CloseWindow();
}