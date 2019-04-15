//
// Created by Jake on 3/17/19.
//

#ifndef ROGUEGAME_ENTITYMANAGER_H
#define ROGUEGAME_ENTITYMANAGER_H

#include <unordered_set>
#include <unordered_map>
#include <bgfx/bgfx.h>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../assets/Assets.h"

using namespace bgfx;
using namespace glm;

namespace Entities {
    struct Component;
}

struct Entity {
    unsigned int Id;
    std::vector<Entities::Component*> Components;
};

namespace Entities {

    struct MeshRenderer;
    struct Transform;
    struct Material;

    struct EntityManager {
        static std::unordered_map<unsigned int, Entity> AllEntities;
        static unsigned int NextEntity;

        static Entity Instantiate();
        static bool IsAlive(Entity e);
        static void Destroy(Entity entity);
        static void UpdateEntities();

        // generated functions
        template<typename T>
        static T* GetComponent(Entity e);

        template<typename T>
        static T* AddComponent(Entity e);

        template<typename T>
        static void AddComponent(Entity e, T & comp);

        template<typename T>
        static T* GetComponent(unsigned int e);

        template<typename T>
        static std::map<unsigned int, T*> GetComponents();

        template<typename T>
        static T* AddComponent(unsigned int e);

        static void ImGuiEditableComponent(Component* comp);
        static void ImGuiAddComponentMenuItems(Entity e);
        static Entity CreateEntityFromSerialized(std::string input);
        static std::string SerializeEntity(Entity e);
        // end generated


        static void Update_Material(unsigned int e, Material* mesh);

        static void Update_MeshRender(unsigned int e, MeshRenderer* mesh);

        static void Update_Transform(unsigned int e, Entities::Transform* transform);
    };


    struct Component {
        Entity Entity;
        virtual ~Component() = default;
        virtual const char* Name(){ return "Component"; }
    };

    //@component
    struct Transform : Component {
        const char* Name() override { return "Transform"; }

        vec3 Position;
        quat Rotation;
        vec3 Scale;

        Transform() {
            Position = vec3(0.0f, 0.0f, 0.0f);
            Rotation = quat();
            Scale = vec3(1.0f, 1.0f, 1.0f);
        }

        vec3 Forward() { return Rotation * vec3{0,0,1}; }
        vec3 Right() { return Rotation * vec3{1,0,0}; }
        vec3 Up() { return Rotation * vec3{0,1,0}; }

        glm::mat4 GetMatrix()
        {
            glm::mat4 mtx(1.0f);

            mtx = glm::translate(mtx, Position);
            mtx = mtx * glm::toMat4(Rotation);
            mtx = glm::scale(mtx, Scale);

            return mtx;
        }

    };

    enum CameraMode
    {
        PERSPECTIVE,
        ORTHOGRAPHIC
    };

    //@component
    struct Camera : Component {
        const char* Name() override { return "Camera"; }

        ViewId View;
        int Width = 1920;
        int Height = 1080;

        FrameBufferHandle FrameBuffer;
        TextureHandle TextureHandle;

        CameraMode Mode = PERSPECTIVE;
        // persp
        float FieldOfView = 60.0f;
        float Near = 0.1f;
        float Far = 1000.0f;

        void SetViewTransform()
        {
            auto cameraTransform = EntityManager::GetComponent<Entities::Transform>(Entity);

            auto fwd = cameraTransform->Forward() + cameraTransform->Position;
            auto up = cameraTransform->Up();

            float view[16];
            bx::mtxLookAt(view, &cameraTransform->Position.x, &fwd.x, &up.x);

            float proj[16];
            switch (Mode)
            {
                case PERSPECTIVE:
                    bx::mtxProj(proj, FieldOfView, float(Width)/float(Height), Near, Far, bgfx::getCaps()->homogeneousDepth);
                    break;
                case ORTHOGRAPHIC:
                    //TODO ortho
                    bx::mtxOrtho(proj, 0,0,0,0,0,0,0,false);
                    break;
            }

            bgfx::setViewTransform(View, view, proj);
        }

        void SetViewRect()
        {
            bgfx::setViewRect(View, 0, 0, uint16_t(Width), uint16_t(Height) );
        }
    };

    //@component
    struct MeshRenderer : Component {
        const char* Name() override { return "MeshRenderer"; }

        std::string ModelPath;
        ModelHandle Model;
    };

    //@component
    struct Material : Component {
        const char* Name() override { return "Material"; }

        vec4 Colour;

        std::string ShaderId;
        bgfx::ProgramHandle Shader;

        std::string TextureId;
        bgfx::TextureHandle Texture;

        bgfx::UniformHandle BaseColour;
    };
};


#endif //ROGUEGAME_ENTITYMANAGER_H
