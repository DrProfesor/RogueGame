//
// Created by jwvan on 2019-03-17.
//


#include <iostream>
#include <vector>

#include "app/Application.hpp"
#include "assets/AssetUtils.h"
#include <bx/math.h>

#include "entity/Entities.h"
#include "entity/Scene.h"
#include "dev/Logger.h"
#include "assets/Assets.h"
#include "input/Input.h"
#include "editor/Editor.h"
#include "physics/Physics.h"

using namespace Entities;
using namespace Editor;
using namespace Physics;

int main(int argc, char** argv)
{
    using namespace app;

    Application app;
    app.Init(argc, argv);

    Logger log;
    EditorManager editor;
    SceneManager sceneManager;
    PhysicsManager physics;

    // Load model
    {
        // /Users/jake/Documents/Dev/RogueGame/assets/models/Knight2/maria_prop_j_j_ong.fbx
        // D:\Dev\RogueGame\assets\models\Knight2\maria_prop_j_j_ong.fbx
        auto ids = Assets::LoadModel("knight", R"(/Users/jake/Documents/Dev/RogueGame/assets/models/Knight2/maria_prop_j_j_ong.fbx)");
        auto e = EntityManager::Instantiate();
        auto mr = EntityManager::AddComponent<MeshRenderer>(e);
        mr->Model = Assets::GetModel(ids[0]);

        auto material = EntityManager::AddComponent<Material>(e);
        material->Shader = Utils::LoadShader("cubes");

        EntityManager::AddComponent<Entities::Transform>(e);
    }

    while (true)
    {
        if (!app.Update()) break;
        editor.Update();
        physics.Update();

        bgfx::setViewFrameBuffer(1, EntityManager::GetComponent<Camera>(app.MainCamera)->FrameBuffer);
        EntityManager::UpdateEntities();

        // Post update contains the bgfx frame call,
        // so should happen after everything has been submitted
        log.Draw();
        app.PostUpdate();
    }

    return 0;
}
//        bool open = true;
//        static bool opt_fullscreen_persistant = true;
//        static ImGuiDockNodeFlags opt_flags = ImGuiDockNodeFlags_None;
//        bool opt_fullscreen = opt_fullscreen_persistant;
//
//        // We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
//        // because it would be confusing to have two docking targets within each others.
//        ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
//        if (opt_fullscreen)
//        {
//            ImGuiViewport* viewport = ImGui::GetMainViewport();
//            ImGui::SetNextWindowPos(viewport->Pos);
//            ImGui::SetNextWindowSize(viewport->Size);
//            ImGui::SetNextWindowViewport(viewport->ID);
//            //ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
//            //ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
//            window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
//            window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
//        }
//
//        // When using ImGuiDockNodeFlags_PassthruDockspace, DockSpace() will render our background and handle the pass-thru hole, so we ask Begin() to not render a background.
//        if (opt_flags & ImGuiDockNodeFlags_PassthruDockspace)
//            window_flags |= ImGuiWindowFlags_NoBackground;
//
//        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
//        ImGui::Begin("DockSpace Demo", &open, window_flags);
//        ImGui::PopStyleVar();
//        ImGuiID dockspace_id = ImGui::GetID("MyDockspace");
//        ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), opt_flags);
//        ImGui::End();
