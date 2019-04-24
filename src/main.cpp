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
#include "rendering/Renderer.h"

#include "editor/Editor.h"
#include "editor/Logger.h"

using namespace Entities;
using namespace Editor;
using namespace Physics;
using namespace Render;
using namespace app;

int main(int argc, char** argv)
{

    Application app;
    app.Init(argc, argv, bgfx::RendererType::Direct3D12);

    PhysicsManager::Init();
    EditorManager::Init();
    Utils::Init();
    Renderer::Init();

    {// TODO move to scene manifest?
        Assets::LoadTexture("grass", "Plane_Grass_01.png");
        Assets::LoadShader("bump");
        Assets::LoadShader("cubes");
        Assets::LoadModel("knight", "D:\\Dev\\RogueGame\\cmake-build-debug\\assets\\models\\Knight2\\maria_prop_j_j_ong.fbx");
        Assets::LoadModel("grass", R"(D:\Dev\RogueGame\assets\models\Terrain\PBOX22_Grass_01.FBX)");
    }

    SceneManager::LoadScene("main");

//    {
//        std::cout << "Load model" << std::endl;
//        auto ids = Assets::LoadModel("knight", R"(D:\Dev\RogueGame\assets\models\Terrain\PBOX22_Grass_01.FBX)");
//        std::cout << "Load texture" << std::endl;
//
//        auto e = EntityManager::Instantiate();
//        EntityManager::AddComponent<Entities::Transform>(e);
//        auto mr = EntityManager::AddComponent<MeshRenderer>(e);
//        mr->Model = Assets::GetModel(ids[0]);
//        mr->ModelPath = R"(D:\Dev\RogueGame\assets\models\Terrain\PBOX22_Grass_01.FBX)";
//
//        auto material = EntityManager::AddComponent<Material>(e);
//        material->Shader = Utils::LoadShader("cubes");
//        material->ShaderId = "cubes";
//        material->Texture = Assets::GetTexture("grass");
//        material->TextureId = "grass";
//    }

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

    while (true)
    {

        if (!app.Update()) break;

        EditorManager::Update();

        PhysicsManager::Update();
        SceneManager::Update();
        EntityManager::UpdateEntities();

        //ImGui::ShowMetricsWindow();

        Renderer::Update();
        // Post update contains the bgfx frame call,
        // so should happen after everything has been submitted
        app.PostUpdate();
    }

    return 0;
}
