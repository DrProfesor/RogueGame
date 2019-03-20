//
// Created by Jake on 3/19/19.
//

#ifndef ROGUEGAME_TRANSFORM_H
#define ROGUEGAME_TRANSFORM_H

#include <glm/vec3.hpp>
#include <map>
#include "Entities.h"

using namespace glm;

struct Transform {
    vec3 Position;
    vec3 Scale;
};

namespace TransformManager
{
    std::map<unsigned int, Transform*> Transforms;

    Transform* Connect(Entity e)
    {
        auto t = new Transform();

        Transforms[e.Id] = t;

        return t;
    }

    Transform* Get(Entity e)
    {
        return Transforms[e.Id];
    }

    void Destroy(Entity e)
    {
        auto t = Transforms[e.Id];
        if (t == nullptr) return;

        Transforms.erase(e.Id);

        delete t;
    }
}

#endif //ROGUEGAME_TRANSFORM_H
