//
// Created by Jake on 3/17/19.
//

#ifndef ROGUEGAME_ENTITYMANAGER_H
#define ROGUEGAME_ENTITYMANAGER_H

#include <unordered_set>
#include <unordered_map>
#include <bgfx/bgfx.h>
#include <glm/vec3.hpp>
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

    //@component
    struct Camera {
        int View;
    };

    //@component
    struct Transform {
        vec3 Position;
        vec3 Scale;
    };

    //@component
    struct MeshRenderer {
        ModelHandle Model;
    };

    //@component
    struct Material {
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
        Entities::GetComponent<Entities::Transform>(e);

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

        bgfx::submit(0, material->Shader);
    }
};




#endif //ROGUEGAME_ENTITYMANAGER_H
