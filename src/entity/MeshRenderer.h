//
// Created by Jake on 3/19/19.
//

#ifndef ROGUEGAME_MESHRENDERER_H
#define ROGUEGAME_MESHRENDERER_H

#include <map>
#include <bgfx/bgfx.h>
#include <bx/bx.h>
#include <fstream>
#include <bx/math.h>

#include "Entities.h"
#include "Generated.h"
#include "../dev/Logger.h"

#include "../assets/Assets.h"

using namespace bgfx;

// Depends on transform, and material
namespace MeshRendererManager
{
    //@component_update(RENDER, MeshRender)
    void RenderAll(int currentView)
    {
        for (auto kp : Entities::MeshRenderers)
        {
            auto mesh = kp.second;
            auto material = Entities::GetComponent<Entities::Material>(kp.first);
            Entities::GetComponent<Entities::Transform>(kp.first);

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

            bgfx::submit(currentView, material->Shader);

        }
    }
}

#endif //ROGUEGAME_MESHRENDERER_H
