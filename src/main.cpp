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
#include "input/Input.h"

using namespace Entities;

int main(int argc, char** argv)
{
    using namespace app;

    Application app;
    app.Init(argc, argv);

    Logger log;

    SceneManager::LoadScene("main.scene");

    // Load model
    {
        // "/Users/jake/Documents/Dev/RogueGame/assets/models/Knight2/maria_prop_j_j_ong.fbx"
        auto ids = Assets::LoadModel("knight", R"(D:\Dev\RogueGame\assets\models\Knight2\maria_prop_j_j_ong.fbx)");
        auto e = Entities::Instantiate();
        auto mr = Entities::AddComponent<MeshRenderer>(e);
        mr->Model = Assets::Models[ids[0]];

        auto material = Entities::AddComponent<Material>(e);
        material->Shader = Utils::LoadShader("cubes");

        Entities::AddComponent<Entities::TransformComponent>(e);
    }

    // load camera
    auto camera = Entities::Instantiate();
    auto c = Entities::AddComponent<Camera>(camera);
    c->View = 1;
    Entities::AddComponent<Entities::TransformComponent>(camera);

    float speed = 2.0f;

    vec2 last_cursor_pos = vec2{};

    float lastTime = 0;
    float dt;
    float time;
    while (true)
    {
        time = ( float )glfwGetTime();
        dt = time - lastTime;
        lastTime = time;

        c->SetViewTransform();
        c->SetViewRect();

        auto cameraTransform = Entities::GetComponent<Entities::TransformComponent>(camera);
        if (Input::GetKey(Input::KeyCode::W))
        {
            cameraTransform->Position += cameraTransform->Forward() * dt * speed;
        }
        if (Input::GetKey(Input::KeyCode::S))
        {
            cameraTransform->Position -= cameraTransform->Forward() * dt * speed;
        }
        if (Input::GetKey(Input::KeyCode::A))
        {
            cameraTransform->Position += cameraTransform->Left() * dt * speed;
        }
        if (Input::GetKey(Input::KeyCode::D))
        {
            cameraTransform->Position -= cameraTransform->Left() * dt * speed;
        }
        if (Input::GetKey(Input::KeyCode::E))
        {
            cameraTransform->Position += cameraTransform->Up() * dt * speed;
        }
        if (Input::GetKey(Input::KeyCode::Q))
        {
            cameraTransform->Position -= cameraTransform->Up() * dt * speed;
        }

        if (!app.Update(dt)) break;

        if (ImGui::Begin("CameraDebug"))
        {
            ImGui::Text("Position: %f %f %f", cameraTransform->Position.x, cameraTransform->Position.y, cameraTransform->Position.z);
            ImGui::Text("Forward: %f %f %f", cameraTransform->Forward().x, cameraTransform->Forward().y, cameraTransform->Forward().z);
            ImGui::Text("Roatation: %f %f %f %f", cameraTransform->Rotation.x, cameraTransform->Rotation.y, cameraTransform->Rotation.z, cameraTransform->Rotation.w);
            ImGui::SliderFloat("Speed", &speed, 1, 10);
        }
        ImGui::End();

        bgfx::setViewFrameBuffer(1, app.frame_buffer_handle);
        Entities::UpdateEntities();

        if (ImGui::Begin("Scene"))
        {
            auto size = ImGui::GetContentRegionAvail();

            ImGui::CaptureMouseFromApp(false);

            union { ImTextureID ptr; struct { uint16_t flags; bgfx::TextureHandle handle; } s; } texture;
            texture.s.handle = app.frame_buffer_texture;
            texture.s.flags  = 0x01;

            ImGui::Image(texture.ptr, size, ImVec2(1, 0), ImVec2(0, 1));

            if (Input::GetButton(Input::Button::RIGHT_MOUSE))
            {
                auto current = Input::GetMousePosition() - vec2{app.GetWidth(), app.GetHeight()};//vec2{ImGui::GetCursorPos().x + ImGui::GetWindowSize().x/2, ImGui::GetCursorPos().y + ImGui::GetWindowSize().y/2};
                auto delta = vec2{current.x - last_cursor_pos.x, current.y - last_cursor_pos.y} * dt;
                //Logger::Instance->Info("Pos: {%f, %f}", delta.x, delta.y);

                auto qx = glm::angleAxis(delta.y, vec3(1,0,0));
                auto qy = glm::angleAxis(-delta.x, vec3(0,1,0));
                cameraTransform->Rotation = cameraTransform->Rotation * qx * qy;
//                cameraTransform->Rotation = glm::rotate(cameraTransform->Rotation, delta.x, vec3(0,1,0));
//                cameraTransform->Rotation = glm::rotate(cameraTransform->Rotation, delta.y, vec3(1,0,0));
//                cameraTransform->Rotation = glm::normalize(cameraTransform->Rotation);

            }
            last_cursor_pos = Input::GetMousePosition() - vec2{app.GetWidth(), app.GetHeight()};

            ImGui::End();
        }

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
