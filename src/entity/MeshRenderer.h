//
// Created by Jake on 3/19/19.
//

#ifndef ROGUEGAME_MESHRENDERER_H
#define ROGUEGAME_MESHRENDERER_H

#include <map>
#include <bgfx/bgfx.h>
#include <fstream>
#include "Entities.h"

using namespace bgfx;

struct MeshRenderer {
    VertexBufferHandle VBO;
    IndexBufferHandle IBO;
};

namespace MeshRendererManager
{
    std::map<unsigned int, MeshRenderer*> Meshes;

    MeshRenderer* Connect(Entity e, VertexBufferHandle vbo, IndexBufferHandle ibo)
    {
        auto mr = new MeshRenderer{vbo, ibo};

        Meshes[e.Id] = mr;

        return mr;
    }

    MeshRenderer* Get(Entity e)
    {
        return Meshes[e.Id];
    }

    void Destroy(Entity e)
    {
        auto t = Meshes[e.Id];
        if (t == nullptr) return;

        Meshes.erase(e.Id);

        delete t;
    }
}

#endif //ROGUEGAME_MESHRENDERER_H
