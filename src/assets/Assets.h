//
// Created by Jake on 3/21/19.
//

#ifndef ROGUEGAME_MODEL_H
#define ROGUEGAME_MODEL_H

#include <map>
#include <string>
#include <vector>

#include <bgfx/bgfx.h>
#include <glm/glm.hpp>

#include "AssetUtils.h"

#include <assimp/scene.h>
#include <assimp/mesh.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <iostream>

using namespace bgfx;

struct ModelHandle {
    VertexBufferHandle VBO;
    IndexBufferHandle IBO;
};

struct Vertex
{
    glm::vec3 pos;
    glm::vec2 tex;
    glm::vec3 nor;
    glm::vec4 col1;
    glm::vec4 col2;
};

namespace Assets {
    void LoadTexture(const std::string textureId, const std::string texturePath);
    TextureHandle GetTexture(std::string textureId);

    void LoadShader(const std::string programId);

    std::vector<std::string> LoadModel(const std::string modelId, const char* modelPath);

    ModelHandle GetModel(std::string id);
};


#endif //ROGUEGAME_MODEL_H
