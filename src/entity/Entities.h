//
// Created by Jake on 3/17/19.
//

#ifndef ROGUEGAME_ENTITYMANAGER_H
#define ROGUEGAME_ENTITYMANAGER_H

#include <vector>
#include <map>
#include <glm/glm.hpp>

using namespace glm;

struct Entity {
    unsigned int Id;
    const char * Name;
};

// Core components
struct Transform {
    vec3 Position;
    vec3 Scale;
};

template <typename T>
struct Manager {
    std::map<unsigned int, T*> Transforms;

    T* Connect(Entity * e)
    {
        auto t = new T();
        Transforms[e->Id] = t;
        return t;
    }

    T* Get(Entity* e)
    {
        return Transforms[e->Id];
    }
};


struct Entities {

    static std::map<uint, Entity*> AllEntities;
    static uint NextEntity;

    static Manager<Transform> TransformManager;

    static void Init()
    {
        TransformManager = Manager<Transform>();
    }

    static Entity* Instantiate(const char * name, Entity * parent = nullptr)
    {
        auto ne = new Entity{ NextEntity, name };

        TransformManager.Connect(ne);

        AllEntities[NextEntity] = ne;
        NextEntity++;

        return ne;
    }

    static void Update(float dt)
    {
        // Update components
    }
};




#endif //ROGUEGAME_ENTITYMANAGER_H
