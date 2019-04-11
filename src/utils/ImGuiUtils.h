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

namespace Utils {
    struct ImGuiUtils {

        static void InputField_float(const char* name, float * val)
        {
            ImGui::InputFloat(name, val);
        }

        static void InputField_vec3(const char* name, vec3 * val)
        {
            ImGui::InputFloat3(name, &val->x);
        }

        static void InputField_quat(const char* name, quat * val)
        {
            ImGui::InputFloat4(name, &val->x);
        }

        static void InputField_int(const char* name, int * val)
        {
            ImGui::InputInt(name, val);
        }

        static void InputField_ViewId(const char* name, ViewId * val)
        {
            ImGui::InputInt(name, (int*)val);
        }

        static void InputField_string(const char* name, std::string * val)
        {
            char* v = (char*) val->c_str();
            ImGui::InputText(name, v, val->size());
            *val = v;
        }

        static void InputField_FrameBufferHandle(const char* name, FrameBufferHandle * val)
        {

        }

        static void InputField_TextureHandle(const char* name, TextureHandle * val)
        {

        }

        static void InputField_CameraMode(const char* name, Entities::CameraMode * val)
        {

        }

        static void InputField_ModelHandle(const char* name, ModelHandle * val)
        {

        }

        static void InputField_ProgramHandle(const char* name, ProgramHandle * val)
        {

        }

        static void InputField_UniformHandle(const char* name, UniformHandle * val)
        {

        }
    };
}

#endif //ROGUEGAME_IMGUIUTILS_H
