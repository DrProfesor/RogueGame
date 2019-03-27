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

using namespace std;
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
    map<string, TextureHandle> Textures = {};
    map<string, ProgramHandle> Shaders = {};
    map<string, ModelHandle> Models = {};

    void LoadTexture(const string textureId, const string texturePath)
    {
        auto tex = Utils::LoadTexture(texturePath.c_str());
        Textures[textureId] = tex;
    }

    void LoadShader(const string programId)
    {
        Shaders[programId] = Utils::LoadShader(programId);
    }

    std::vector<string> LoadModel(const string modelId, const char* modelPath)
    {
        bgfx::VertexDecl ms_decl;
        ms_decl
                .begin()
                .add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
                .add(bgfx::Attrib::TexCoord0, 2, bgfx::AttribType::Float)
                .add(bgfx::Attrib::Normal, 3, bgfx::AttribType::Float)
                .add(bgfx::Attrib::Color0, 4, bgfx::AttribType::Float)
                .add(bgfx::Attrib::Color1, 4, bgfx::AttribType::Float)
                .end();
        Assimp::Importer importer;
        std::cout << modelPath << std::endl;
        const aiScene *scene = importer.ReadFile(modelPath, aiProcess_CalcTangentSpace | aiProcess_Triangulate | aiProcess_JoinIdenticalVertices | aiProcess_SortByPType | aiProcess_FlipWindingOrder);
        if (!scene) {
            printf("Unable to laod mesh: %s\n", importer.GetErrorString());
        }

        std::vector<string> meshIds;

        for (int i = 0; i < scene->mNumMeshes; ++i)
        {
            aiMesh *mesh = scene->mMeshes[i];

            std::vector<Vertex> vertices(mesh->mNumVertices);

            for (size_t i = 0; i < mesh->mNumVertices; i++)
            {
                auto vert = mesh->mVertices[i];
                vertices[i].pos = glm::vec3(vert.x, vert.y, vert.z);

                auto norm = mesh->mNormals[i];
                vertices[i].nor = glm::vec3(norm.x, norm.y, norm.z);

                //auto col = mesh->mColors[0][i];
                vertices[i].col1 = glm::vec4(0.5, 0, 0.5, 1);
                vertices[i].col2 = glm::vec4(0.5, 0, 0.5, 1);

                if (mesh->mTextureCoords[0])
                {
                    auto tex = mesh->mTextureCoords[0][i];
                    vertices[i].tex = glm::vec2(tex.x , tex.y);
                }
            }

            auto vbo = createVertexBuffer(bgfx::copy(&vertices[0], mesh->mNumVertices * sizeof(Vertex)), ms_decl);

            std::vector<unsigned int> indices;
            for (size_t i = 0; i < mesh->mNumFaces; i++)
            {
                for (size_t j = 0; j < mesh->mFaces[i].mNumIndices; j++)
                {
                    indices.push_back(mesh->mFaces[i].mIndices[j]);
                }
            }

            auto ibo = bgfx::createIndexBuffer(bgfx::copy(indices.data(), indices.size() * sizeof(unsigned int)), BGFX_BUFFER_INDEX32);

            auto modelHandle = ModelHandle{vbo, ibo};
            string id = modelId + std::to_string(i);

            Models[id] = modelHandle;
            meshIds.push_back(id);
        };

        return meshIds;
    }
};


#endif //ROGUEGAME_MODEL_H
