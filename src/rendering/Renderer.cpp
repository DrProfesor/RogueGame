//
// Created by jwvan on 2019-04-13.
//

#include "Renderer.h"
#include "../entity/Entities.h"
#include "../editor/Logger.h"
#include "../editor/Editor.h"

using namespace Entities;

namespace Render {
    void Renderer::Init()
    {

    }

    void Renderer::Update()
    {
        auto cameras = EntityManager::GetComponents<Camera>();
        auto meshes = EntityManager::GetComponents<ModelRenderer>();
        auto materials = EntityManager::GetComponents<Material>();

        for (auto ckp : cameras) {
            auto camera = ckp.second;

            bgfx::touch(camera->View);

            bgfx::setViewFrameBuffer(camera->View, camera->FrameBuffer);
            bgfx::setViewClear( camera->View, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x6dbae0ff, 1.0f, 0 );

            {// Update materials
                for (auto mkp : materials) {
                    // update materials uniforms
                    bgfx::setUniform(mkp.second->BaseColour, &mkp.second->Colour.x);
                }
            }

            {// Render meshes
                for (auto mkp : meshes) {
                    auto mesh = mkp.second;

                    auto material = EntityManager::GetComponent<Material>(mkp.first);
                    auto transform = EntityManager::GetComponent<Entities::Transform>(mkp.first);

                    if (material == nullptr)
                        continue;
                    if (!material->IsValid())
                        continue;
                    if (!mesh->IsValid())
                        continue;

                    bgfx::setTransform(&transform->GetMatrix()[0]);

                    bgfx::setVertexBuffer(0, mesh->Model.VBO);
                    bgfx::setIndexBuffer(mesh->Model.IBO);

                    bgfx::setTexture(0, material->Sampler, material->Texture);
                    bgfx::setState(0
                                   | BGFX_STATE_WRITE_RGB
                                   | BGFX_STATE_WRITE_A
                                   | BGFX_STATE_WRITE_Z
                                   | BGFX_STATE_DEPTH_TEST_LESS
                                   | BGFX_STATE_CULL_CW
                                   | BGFX_STATE_MSAA);

                    bgfx::submit(camera->View, material->Shader);
                }
            }
        }
    }
}