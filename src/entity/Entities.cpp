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
        auto material = EntityManager::GetComponent<Material>(e);
        auto transform = EntityManager::GetComponent<Transform>(e);

        bgfx::setTransform(&transform->GetMatrix()[0]);

        bgfx::setVertexBuffer(0, mesh->Model.VBO);
        bgfx::setIndexBuffer(mesh->Model.IBO);

        bgfx::setTexture(0, material->Uniforms, material->Texture);
        bgfx::setState(0 | BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_A
                       | BGFX_STATE_WRITE_Z | BGFX_STATE_DEPTH_TEST_LESS
                       | BGFX_STATE_MSAA);

        bgfx::submit(1, material->Shader);
    }

    void EntityManager::Update_Transform(unsigned int e, Entities::Transform* transform) { }
}