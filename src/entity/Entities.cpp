//
// Created by jwvan on 2019-04-04.
//

#include "Entities.h"

namespace Entities {

    std::unordered_map<unsigned int, Entity> EntityManager::AllEntities = {};
    unsigned int EntityManager::NextEntity = 0;

    Entity EntityManager::Instantiate() {
        auto ne = Entity{NextEntity};

        AllEntities[NextEntity] = ne;
        NextEntity++;

        return ne;
    }

    bool EntityManager::IsAlive(Entity e) {
        return AllEntities.find(e.Id) != AllEntities.end();
    }

    void EntityManager::Update_MeshRender(unsigned int e, MeshRenderer* mesh) {

    }
}