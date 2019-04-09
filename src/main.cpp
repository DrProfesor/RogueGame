//
// Created by jwvan on 2019-03-17.
//


#include <iostream>
#include <vector>
#include <bx/math.h>

#include "app/Application.hpp"

#include "entity/Entities.h"
#include "entity/Scene.h"

#include "assets/AssetUtils.h"
#include "assets/Assets.h"

#include "input/Input.h"

#include "physics/Physics.h"

#include "editor/Editor.h"
#include "editor/Logger.h"

using namespace Entities;
using namespace Editor;
using namespace Physics;

int main(int argc, char** argv)
{
    using namespace app;

    Application app;
    app.Init(argc, argv);

    EditorManager editor;
    SceneManager sceneManager;
    PhysicsManager physics;

    sceneManager.LoadScene("main");

    // Load model
//    {
//        // /Users/jake/Documents/Dev/RogueGame/assets/models/Knight2/maria_prop_j_j_ong.fbx
//        // D:\Dev\RogueGame\assets\models\Knight2\maria_prop_j_j_ong.fbx
//        auto ids = Assets::LoadModel("knight", R"(D:\Dev\RogueGame\assets\models\Knight2\maria_prop_j_j_ong.fbx)");
//        auto e = EntityManager::Instantiate();
//        auto mr = EntityManager::AddComponent<MeshRenderer>(e);
//        mr->Model = Assets::GetModel(ids[0]);
//        mr->ModelPath = R"(D:\Dev\RogueGame\assets\models\Knight2\maria_prop_j_j_ong.fbx)";
//
//        auto material = EntityManager::AddComponent<Material>(e);
//        material->Shader = Utils::LoadShader("cubes");
//        material->ShaderId = "cubes";
//
//        EntityManager::AddComponent<Entities::Transform>(e);
//    }

    app.MainCamera = EntityManager::AllEntities[0];

    sceneManager.SaveScene("main");

    while (true)
    {
        if (!app.Update()) break;
        editor.Update();
        physics.Update();

        bgfx::setViewFrameBuffer(1, EntityManager::GetComponent<Camera>(app.MainCamera)->FrameBuffer);
        EntityManager::UpdateEntities();

        // Post update contains the bgfx frame call,
        // so should happen after everything has been submitted
        app.PostUpdate();
    }

    return 0;
}
