//
// Created by jwvan on 2019-03-17.
//


#include <iostream>
#include <vector>

#include "app/Application.hpp"
#include "assets/AssetUtils.h"
#include <bx/math.h>

#include "entity/Generated.h"
#include "entity/Entities.h"
#include "dev/Logger.h"
#include "assets/Assets.h"
#include "scene/Scene.h"

using namespace Entities;

int main(int argc, char** argv)
{
    using namespace app;

    Application app;
    app.Init(argc, argv);

    Logger::Init();

    SceneManager::LoadScene("main.scene");

    auto ids = Assets::LoadModel("knight", "/Users/jake/Documents/Dev/RogueGame/assets/models/Knight2/maria_prop_j_j_ong.fbx");

    auto e = Entities::Instantiate();
    auto mr = Entities::AddComponent<MeshRenderer>(e);
    mr->Model = Assets::Models[ids[0]];

    auto material = Entities::AddComponent<Material>(e);
    material->Shader = Utils::LoadShader("cubes");

    auto transform = Entities::AddComponent<Entities::Transform>(e);

    auto camera = Entities::Instantiate();
    auto c = Entities::AddComponent<Camera>(camera);
    c->View = 0;
    Entities::AddComponent<Entities::Transform>(camera);

    const vec3 at  = { 0.0f, 0.0f,   0.0f };
    const vec3 eye = { 0.0f, 0.0f, -35.0f };

    { //TODO camera stuff here
        float view[16];
        bx::mtxLookAt(view, &eye[0], &at[0]);

        float proj[16];
        bx::mtxProj(proj, 60.0f, float(app.mWidth)/float(app.mHeight), 0.1f, 100.0f, bgfx::getCaps()->homogeneousDepth);
        bgfx::setViewTransform(0, view, proj);

        // Set view 0 default viewport.
        bgfx::setViewRect(0, 0, 0, uint16_t(app.mWidth), uint16_t(app.mHeight) );
    }

    float lastTime = 0;
    float dt;
    float time;
    while (true)
    {
        time = ( float )glfwGetTime();
        dt = time - lastTime;
        lastTime = time;

        if (!app.Update(dt)) break;

        Entities::UpdateEntities();

        // Post update contains the bgfx frame call,
        // so should happen after everything has been submitted
        Logger::GetLogObj().Draw();
        app.PostUpdate();
    }

    return 0;
}
