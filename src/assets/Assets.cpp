//
// Created by jwvan on 2019-04-04.
//

#include <filesystem>
#include "Assets.h"
#include "../editor/Logger.h"
#include <brtshaderc.h>
#include <sstream>

#define ASSET_DIR "assets/"
#define MODEL_DIR "assets/models/"
#define SHADER_DIR "assets/shaders/"
#define TEXTURE_DIR "assets/textures/"

namespace fs = std::filesystem;

std::map<std::string, TextureHandle> Textures = {};
std::map<std::string, ProgramHandle> Shaders = {};
std::map<std::string, ModelHandle> Models = {};

ModelHandle Assets::GetModel(std::string id)
{
    return Models[id];
}

void Assets::LoadTexture(const std::string textureId, const std::string texturePath)
{
    auto path = TEXTURE_DIR + texturePath;
    auto tex = Utils::LoadTexture(path.c_str());
    Textures[textureId] = tex;
}

TextureHandle Assets::GetTexture(std::string textureId)
{
    return Textures[textureId];
}

void Assets::LoadShader(const std::string programId)
{
    std::stringstream vertPathStream;
    vertPathStream << SHADER_DIR << "/" << programId << "/vs_" << programId << ".sc";

    std::stringstream varyingDefStream;
    varyingDefStream << SHADER_DIR << "/" << programId << "/varying.def.sc";

    std::stringstream fragPathStream;
    fragPathStream << SHADER_DIR << "/" << programId << "/fs_" << programId << ".sc";

    const bgfx::Memory* memVsh = shaderc::compileShader(shaderc::ST_VERTEX, vertPathStream.str().c_str(), nullptr, varyingDefStream.str().c_str(), "vs_5_0");
    if (!memVsh)
    {
        Logger::Instance->Info("Failed to load vertex shader for: %s", programId.c_str());
        return;
    }
    auto vertexHandle = bgfx::createShader(memVsh);

    const bgfx::Memory* memFsh = shaderc::compileShader(shaderc::ST_FRAGMENT, fragPathStream.str().c_str(), nullptr, varyingDefStream.str().c_str(), "ps_5_0");
    if (!memFsh)
    {
        Logger::Instance->Info("Failed to load fragment shader for: %s", programId.c_str());
        return;
    }
    auto fragmentHandle = bgfx::createShader(memFsh);

    Shaders[programId] = bgfx::createProgram(vertexHandle, fragmentHandle, true);
}

ProgramHandle Assets::GetShader(std::string programId)
{
    return Shaders[programId];
}

std::vector<std::string> Assets::LoadModel(const std::string modelId, const char* modelPath)
{
    bgfx::VertexDecl ms_decl;
    ms_decl.begin()
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

    std::vector<std::string> meshIds;

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

            vertices[i].col1 = glm::vec4(0.5f,0.5f,0.5f,1);
            vertices[i].col2 = glm::vec4(0.5f,0.5f,0.5f,1);

            if (mesh->mColors[0])
            {
                auto colour = mesh->mColors[0][i];
                vertices[i].col2 = glm::vec4(colour.r, colour.g, colour.b, colour.a);
            }

            if (mesh->mColors[1])
            {
                auto colour = mesh->mColors[1][i];
                vertices[i].col2 = glm::vec4(colour.r, colour.g, colour.b, colour.a);
            }

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
        std::string id = modelId + std::to_string(i);

        Models[id] = modelHandle;
        meshIds.push_back(id);
    };

    return meshIds;
}