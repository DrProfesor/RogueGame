//
// Created by jwvan on 2019-03-17.
//


#include <iostream>

#include "app/Application.hpp"
#include "entity/Entities.h"
#include "utils/Utils.h"
#include "entity/MeshRenderer.h"

#include <assimp/scene.h>
#include <assimp/mesh.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>

struct Vertex
{
    glm::vec3 pos;
    glm::vec2 tex;
    glm::vec3 nor;
};

int main(int argc, char** argv)
{
    using namespace app;

    Application app;
    app.Init(argc, argv);

    bgfx::VertexDecl ms_decl;
    ms_decl
            .begin()
            .add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
            .add(bgfx::Attrib::TexCoord0, 2, bgfx::AttribType::Float)
            .add(bgfx::Attrib::Normal, 3, bgfx::AttribType::Float)
            .end();

    Assimp::Importer importer;
    const aiScene *scene = importer.ReadFile("assets/models/Knight2/maria_prop_j_j_ong.fbx", aiProcess_CalcTangentSpace |
                                                       aiProcess_Triangulate |
                                                       aiProcess_JoinIdenticalVertices |
                                                       aiProcess_SortByPType | aiProcess_FlipWindingOrder);

    if (!scene) {
        printf("Unable to laod mesh: %s\n", importer.GetErrorString());
    }

    std::vector<Entity> Meshes;

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

        auto e = Entities::Instantiate();
        MeshRendererManager::Connect(e, vbo, ibo);

        Meshes.push_back(e);
    }


    float lastTime = 0;
    float dt;
    float time;
    while (true)
    {
        time = ( float )glfwGetTime();
        dt = time - lastTime;
        lastTime = time;

        if (!app.Update(dt)) break;

        ImGui::ShowDemoWindow();

        for (auto e : Meshes)
        {
            auto mr = MeshRendererManager::Get(e);
            bgfx::setVertexBuffer(0, mr->VBO);
            bgfx::setIndexBuffer(mr->IBO);

            bgfx::submit(0, );
        }

        // Post update contains the bgfx frame call,
        // so should happen after everything has been submitted
        app.PostUpdate();
    }

    return 0;
}
