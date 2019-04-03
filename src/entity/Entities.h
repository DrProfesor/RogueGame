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
#include "../assets/Assets.h"

using namespace bgfx;
using namespace glm;

struct Entity {
    unsigned int Id;
};

namespace Entities {

    template<typename T>
    T* GetComponent(Entity e);

    template<typename T>
    T* AddComponent(Entity e);

    template<typename T>
    T* GetComponent(unsigned int e);

    template<typename T>
    T* AddComponent(unsigned int e);

    struct Component {
        Entity Entity;
    };

    //@component
    struct TransformComponent : Component {
        vec3 Position;
        quat Rotation;
        vec3 Scale;

        TransformComponent() {
            Position = vec3(0.0f, 0.0f, 0.0f);
            Rotation = quat();
            Scale = vec3(1.0f, 1.0f, 1.0f);
        }

        vec3 Forward()
        {
            auto x = Rotation.x;
            auto y = Rotation.y;
            auto z = Rotation.z;
            auto w = Rotation.w;
            vec3 ret;
            ret.x = 2 * (x * z + w * y);
            ret.y = 2 * (y * z - w * x);
            ret.z = 1 - 2 * (x * x + y * y);

            ret = glm::normalize(ret);

            return ret;
        }

        vec3 Left()
        {
            auto x = Rotation.x;
            auto y = Rotation.y;
            auto z = Rotation.z;
            auto w = Rotation.w;
            vec3 ret;
            ret.x = 1 - 2 * (y * y + z * z);
            ret.y = 2 * (x * y + w * z);
            ret.z = 2 * (x * z - w * y);

            ret = glm::normalize(ret);

            return ret;
        }

        vec3 Up()
        {
            auto x = Rotation.x;
            auto y = Rotation.y;
            auto z = Rotation.z;
            auto w = Rotation.w;
            vec3 ret;
            ret.x = 2 * (x * y - w * z);
            ret.y = 1 - 2 * (x * x + z * z);
            ret.z = 2 * (y * z + w * x);

            ret = glm::normalize(ret);

            return ret;
        }
    };

    enum CameraMode
    {
        PERSPECTIVE,
        ORTHOGRAPHIC
    };

    //@component
    struct Camera : Component {
        ViewId View;
        int Width = 1920;
        int Height = 1080;

        CameraMode Mode = PERSPECTIVE;
        // persp
        float FieldOfView = 60.0f;
        float Near = 0.1f;
        float Far = 100.0f;

        void SetViewTransform()
        {
            auto cameraTransform = Entities::GetComponent<Entities::TransformComponent>(Entity);
            //const vec3 at  = { cameraTransform->Transform.Position.x, cameraTransform->Transform.Position.y, cameraTransform->Transform.Position.z };
            //const vec3 eye = cameraTransform->Transform.Position + cameraTransform->Forward();

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
        ModelHandle Model;
    };

    //@component
    struct Material : Component {
        bgfx::ProgramHandle Shader;
        bgfx::TextureHandle Texture;
        bgfx::UniformHandle Uniforms;
    };

    std::unordered_map<unsigned int, Entity> AllEntities;
    unsigned int NextEntity;

    Entity Instantiate()
    {
        auto ne = Entity{ NextEntity };

        AllEntities[NextEntity] = ne;
        NextEntity++;

        return ne;
    }

    bool IsAlive(Entity e)
    {
        return AllEntities.find(e.Id) != AllEntities.end();
    }

    void Destroy(Entity entity)
    {
        AllEntities.erase(entity.Id);
    }

    //@component_update(RENDER, MeshRenderer)
    void Update_MeshRender(unsigned int e, Entities::MeshRenderer* mesh)
    {
        auto material = Entities::GetComponent<Entities::Material>(e);
        Entities::GetComponent<Entities::TransformComponent>(e);

        // set transform

        float mtx[16];
        bx::mtxIdentity(&mtx[0]);
        bgfx::setTransform(mtx);

        bgfx::setVertexBuffer(0, mesh->Model.VBO);
        bgfx::setIndexBuffer(mesh->Model.IBO);

        //bgfx::setTexture(0, material->Uniforms, material->Texture);
        bgfx::setState(0
                       | BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_A
                       | BGFX_STATE_WRITE_Z | BGFX_STATE_DEPTH_TEST_LESS
                       | BGFX_STATE_MSAA);

        bgfx::submit(1, material->Shader);
    }

    //@component_update(UPDATE, TransformComponent)
    void Update_Transform(unsigned int e, Entities::TransformComponent* transform)
    {

    }
};




#endif //ROGUEGAME_ENTITYMANAGER_H
