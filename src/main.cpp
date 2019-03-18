//
// Created by jwvan on 2019-03-17.
//


#include <iostream>

#include "app/Application.hpp"
#include "entity/Entities.h"

int main(int argc, char** argv)
{
    using namespace app;

    Application app;
    app.Init(argc, argv);

    Entities::Init();

    float lastTime = 0;
    float dt;
    float time;
    while (true)
    {
        time = ( float )glfwGetTime();
        dt = time - lastTime;
        lastTime = time;

        if (!app.Update(dt)) break;

        Entities::Update(dt);

        ImGui::ShowDemoWindow();

        // Post update contains the bgfx frame call,
        // so should happen after everything has been submitted
        app.PostUpdate();
    }

    return 0;
}
