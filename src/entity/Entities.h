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
};




#endif //ROGUEGAME_ENTITYMANAGER_H
