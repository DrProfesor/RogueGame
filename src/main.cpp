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

        bool open = true;
        static bool opt_fullscreen_persistant = true;
        static ImGuiDockNodeFlags opt_flags = ImGuiDockNodeFlags_None;
        bool opt_fullscreen = opt_fullscreen_persistant;

        // We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
        // because it would be confusing to have two docking targets within each others.
        ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
        if (opt_fullscreen)
        {
            ImGuiViewport* viewport = ImGui::GetMainViewport();
            ImGui::SetNextWindowPos(viewport->Pos);
            ImGui::SetNextWindowSize(viewport->Size);
            ImGui::SetNextWindowViewport(viewport->ID);
            //ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
            //ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
            window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
            window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
        }

        // When using ImGuiDockNodeFlags_PassthruDockspace, DockSpace() will render our background and handle the pass-thru hole, so we ask Begin() to not render a background.
        if (opt_flags & ImGuiDockNodeFlags_PassthruDockspace)
            window_flags |= ImGuiWindowFlags_NoBackground;

        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
        ImGui::Begin("DockSpace Demo", &open, window_flags);
        ImGui::PopStyleVar();
        ImGuiID dockspace_id = ImGui::GetID("MyDockspace");
        ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), opt_flags);
        ImGui::End();

        bgfx::setViewFrameBuffer(0, app.frame_buffer_handle);
        Entities::UpdateEntities();

        if (ImGui::Begin("Scene"))
        {
            auto size = ImGui::GetContentRegionAvail();
            //ImGui::Image(&app.frame_buffer_texture, size, ImVec2(0, 1), ImVec2(1, 0));

            ImGui::End();
        }

        // Post update contains the bgfx frame call,
        // so should happen after everything has been submitted
        Logger::GetLogObj().Draw("Log");
        app.PostUpdate();
    }

    return 0;
}
