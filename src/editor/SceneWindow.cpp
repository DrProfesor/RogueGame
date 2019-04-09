//
// Created by jwvan on 2019-04-04.
//

#include "SceneWindow.h"
#include "ImGuizmo.h"
#include "../physics/Time.h"

using namespace Entities;
using namespace Physics;
using namespace app;

namespace Editor {

    SceneWindow::SceneWindow()
    {
        last_cursor_pos = vec2{};
    }

    void SceneWindow::Update()
    {
        auto camera = EntityManager::GetComponent<Entities::Camera>(Application::Instance->MainCamera);
        auto cameraTransform = EntityManager::GetComponent<Entities::Transform>(Application::Instance->MainCamera);
        float dt = Time::deltaTime;
        if (Input::GetKey(Input::KeyCode::W))
        {
            cameraTransform->Position += cameraTransform->Forward() * dt * 10.0f;
        }
        if (Input::GetKey(Input::KeyCode::S))
        {
            cameraTransform->Position -= cameraTransform->Forward() * dt * 10.0f;
        }
        if (Input::GetKey(Input::KeyCode::A))
        {
            cameraTransform->Position += cameraTransform->Right() * dt * 10.0f;
        }
        if (Input::GetKey(Input::KeyCode::D))
        {
            cameraTransform->Position -= cameraTransform->Right() * dt * 10.0f;
        }
        if (Input::GetKey(Input::KeyCode::E))
        {
            cameraTransform->Position += cameraTransform->Up() * dt * 10.0f;
        }
        if (Input::GetKey(Input::KeyCode::Q))
        {
            cameraTransform->Position -= cameraTransform->Up() * dt * 10.0f;
        }

        if (Input::GetButton(Input::Button::RIGHT_MOUSE))
        {
            auto current = Input::GetMousePosition() - vec2{Application::Instance->GetWidth(), Application::Instance->GetHeight()};
            auto delta = vec2{current.x - last_cursor_pos.x, current.y - last_cursor_pos.y} * dt;

            auto qx = glm::angleAxis(-delta.x, vec3{0,1,0});
            auto qy = glm::angleAxis(delta.y, cameraTransform->Right());
            cameraTransform->Rotation = qy * qx * cameraTransform->Rotation;

        }
        last_cursor_pos = Input::GetMousePosition() - vec2{Application::Instance->GetWidth(), Application::Instance->GetHeight()};

        camera->SetViewTransform();
        camera->SetViewRect();

        if (ImGui::Begin("Scene Hierarchy"))
        {
            for (auto kp : EntityManager::AllEntities)
            {
                auto key = kp.first;
                Entity entity = kp.second;

                if (ImGui::TreeNode(std::to_string(key).c_str()))
                {
                    for (auto comp : entity.Components)
                    {
                        if (ImGui::TreeNode(typeid(*comp).name()))
                        {
                            EntityManager::ImGuiEditableComponent(comp);


                            ImGui::TreePop();
                        }
                    }

                    ImGui::TreePop();
                }
            }
        }
        ImGui::End();

        if (ImGui::Begin("Scene"))
        {
            auto size = ImGui::GetContentRegionAvail();

            ImGui::CaptureMouseFromApp(false);

            union { ImTextureID ptr; struct { uint16_t flags; bgfx::TextureHandle handle; } s; } texture;
            texture.s.handle = camera->TextureHandle;
            texture.s.flags  = 0x01;

            ImGui::Image(texture.ptr, size, ImVec2(1, 0), ImVec2(0, 1));
        }

        ImGui::End();
    }

}