//
// Created by jwvan on 2019-04-07.
//

#ifndef ROGUEGAME_IMGUIUTILS_H
#define ROGUEGAME_IMGUIUTILS_H

#include <string>
#include <algorithm>
#include <imgui.h>
#include <glm/vec3.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <bgfx/bgfx.h>
#include "../entity/Entities.h"
#include "../editor/Editor.h"
#include "../physics/Physics.h"

using namespace glm;
using namespace bgfx;
using namespace Entities;
using namespace Physics;

namespace Utils {
    struct ImGuiUtils {
        
        template<typename T>
            static void ImGui_Component(T* component, Entity e)
        {
            EntityManager::ImGuiEditableComponent((Component*)component);
        }
        
        template<>
            static void ImGui_Component<Entities::Transform>(Entities::Transform * component, Entity e)
        {
            ImGuiUtils::InputField_vec3("Position", &component->Position, e);
            ImGuiUtils::InputField_quat("Rotation", &component->Rotation, e);
            ImGuiUtils::InputField_vec3("Scale", &component->Scale, e);
        }
        
        template<>
            static void ImGui_Component<Camera>(Camera * component, Entity e)
        {
            ImGuiUtils::InputField_ViewId("View", &component->View, e);
            ImGuiUtils::InputField_int("Width", &component->Width, e);
            ImGuiUtils::InputField_int("Height", &component->Height, e);
            ImGuiUtils::InputField_FrameBufferHandle("FrameBuffer", &component->FrameBuffer, e);
            ImGuiUtils::InputField_TextureHandle("TextureHandle", &component->TextureHandle, e);
            ImGuiUtils::InputField_CameraMode("Mode", &component->Mode, e);
            ImGuiUtils::InputField_float("FieldOfView", &component->FieldOfView, e);
            ImGuiUtils::InputField_float("Near", &component->Near, e);
            ImGuiUtils::InputField_float("Far", &component->Far, e);
        }
        
        template<> 
            static void ImGui_Component<ModelRenderer>(ModelRenderer * component, Entity e)
        {
            
            ImGuiUtils::InputField_string("ModelId", &component->ModelId, e);
            if (ImGui::BeginDragDropTarget())
            {
                if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload("Asset")) {
                    
                    // Get from static payload. ImGui screws with my data?? :'(
                    auto id = Editor::EditorManager::CurrentPayload.AssetPath;
                    auto path = Editor::EditorManager::CurrentPayload.AssetPath;
                    
                    Assets::LoadModel(id, path);
                    component->Model = Assets::GetModel(id);
                    component->ModelId = id;
                }
                
                ImGui::EndDragDropTarget();
            }
            
            ImGui::Checkbox("Render", &component->Render);
            
            if (ImGui::Button("Set Model"))
            {
                component->Model = Assets::GetModel(component->ModelId);
            }
        }
        
        template<>
            static void ImGui_Component<Material>(Material * component, Entity e)
        {
            ImGuiUtils::InputField_vec4("Colour", &component->Colour, e);
            ImGuiUtils::InputField_string("ShaderId", &component->ShaderId, e);
            ImGuiUtils::InputField_ProgramHandle("Shader", &component->Shader, e);
            ImGuiUtils::InputField_string("TextureId", &component->TextureId, e);
            ImGuiUtils::InputField_TextureHandle("Texture", &component->Texture, e);
            ImGuiUtils::InputField_UniformHandle("Sampler", &component->Sampler, e);
            ImGuiUtils::InputField_UniformHandle("BaseColour", &component->BaseColour, e);
        }
        
        template<>
            static void ImGui_Component<Collider>(Collider * component, Entity e)
        {
            
        }
        
        static void ImGui_Image(TextureHandle handle, vec2 size)
        {
            union { ImTextureID ptr; struct { uint16_t flags; bgfx::TextureHandle handle; } s; } texture;
            texture.s.handle = handle;
            texture.s.flags  = 0x01;
            
            ImGui::Image(texture.ptr, ImVec2(size.x, size.y));
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
        
        static void InputField_bool(const char* name, bool * val, Entity e)
        {
            
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
                // TODO validation
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
                // TODO validation
                mat->Shader = Assets::GetShader(mat->ShaderId);
            }
        }
        
        static void InputField_UniformHandle(const char* name, UniformHandle * val, Entity e)
        {
            
        }
    };
}

#endif //ROGUEGAME_IMGUIUTILS_H
