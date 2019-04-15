//
// Created by jwvan on 2019-04-07.
//

#ifndef ROGUEGAME_IMGUIUTILS_H
#define ROGUEGAME_IMGUIUTILS_H

#include <imgui.h>
#include <glm/vec3.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <bgfx/bgfx.h>
#include "../entity/Entities.h"

using namespace glm;
using namespace bgfx;
using namespace Entities;

namespace Utils {
    struct ImGuiUtils {

        static void ImGui_Image(TextureHandle handle, vec2 size)
        {
            union { ImTextureID ptr; struct { uint16_t flags; bgfx::TextureHandle handle; } s; } texture;
            texture.s.handle = handle;
            texture.s.flags  = 0x01;

            ImGui::Image(texture.ptr, ImVec2(size.x, size.y), ImVec2(1, 0), ImVec2(0, 1));
        }

        static void InputField_float(const char* name, float * val, Entity e)
        {
            ImGui::InputFloat(name, val);
        }

        static void InputField_vec4(const char* name, vec4 * val, Entity e)
        {
            ImGui::PushItemWidth(200);
            ImGui::ColorPicker4(name, &val->x);
            ImGui::PopItemWidth();
        }

        static void InputField_vec3(const char* name, vec3 * val, Entity e)
        {
            ImGui::InputFloat3(name, &val->x);
        }

        static void InputField_quat(const char* name, quat * val, Entity e)
        {
            ImGui::InputFloat4(name, &val->x);
        }

        static void InputField_int(const char* name, int * val, Entity e)
        {
            ImGui::InputInt(name, val);
        }

        static void InputField_ViewId(const char* name, ViewId * val, Entity e)
        {
            ImGui::InputInt(name, (int*)val);
        }

        static void InputField_string(const char* name, std::string * val, Entity e)
        {
            char* v = (char*) val->c_str();
            ImGui::InputText(name, v, val->size() + 20);
            *val = std::string(v);
        }

        static void InputField_FrameBufferHandle(const char* name, FrameBufferHandle * val, Entity e)
        {
            // TODO view image
        }

        static void InputField_TextureHandle(const char* name, TextureHandle * val, Entity e)
        {
            ImGui::NewLine();
            ImGui_Image(*val, vec2(100,100));

            if (ImGui::Button("Change Texture"))
            {
                auto mat = EntityManager::GetComponent<Material>(e);
                mat->Texture = Assets::GetTexture(mat->TextureId);
            }
        }

        static void InputField_CameraMode(const char* name, Entities::CameraMode * val, Entity e)
        {

        }

        static void InputField_ModelHandle(const char* name, ModelHandle * val, Entity e)
        {
        }

        static void InputField_ProgramHandle(const char* name, ProgramHandle * val, Entity e)
        {
            if (ImGui::Button("Change Shader"))
            {
                auto mat = EntityManager::GetComponent<Material>(e);
                mat->Shader = Assets::GetShader(mat->ShaderId);
            }
        }

        static void InputField_UniformHandle(const char* name, UniformHandle * val, Entity e)
        {

        }
    };
}

#endif //ROGUEGAME_IMGUIUTILS_H
