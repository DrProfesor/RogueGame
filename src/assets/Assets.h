//
// Created by Jake on 3/21/19.
//

#ifndef ROGUEGAME_MODEL_H
#define ROGUEGAME_MODEL_H

#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <filesystem>
#include <sstream>

#include <bgfx/bgfx.h>
#include <brtshaderc.h>
#include <glm/glm.hpp>

#include "AssetUtils.h"
#include "../editor/Logger.h"

#include <assimp/scene.h>
#include <assimp/mesh.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>

#define ASSET_DIR "../assets/"
#define MODEL_DIR "../assets/models/"
#define SHADER_DIR "../assets/shaders/"
#define TEXTURE_DIR "../assets/textures/"

namespace fs = std::filesystem;
//using namespace bgfx;

struct ModelHandle {
    bgfx::VertexBufferHandle VBO;
    bgfx::IndexBufferHandle IBO;
};

enum AssetType {
    INVALID,
    SHADER,
    TEXTURE,
    MODEL,
};

struct AssetPayload {
    std::string AssetPath;
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
    bgfx::TextureHandle GetTexture(std::string textureId);
    
    void LoadShader(const std::string programId);
    bgfx::ProgramHandle GetShader(std::string programId);
    
    void LoadModel(const std::string modelId, const char* modelPath);
    ModelHandle GetModel(std::string id);
    
    inline fs::path GetAssetPath()
    {
        fs::path assetpath = std::filesystem::current_path();
        assetpath += "/";
        assetpath += ASSET_DIR;
        
        return assetpath;
    }
};

#endif //ROGUEGAME_MODEL_H
