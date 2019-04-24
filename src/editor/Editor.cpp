//
// Created by jwvan on 2019-04-06.
//

#include "Editor.h"
#include "../app/Application.hpp"
#include "../entity/Scene.h"

namespace Editor {

    bool EditorManager::IsEditMode = true;
    SceneWindow EditorManager::sceneWindow;
    Logger EditorManager::logger;

    struct PosTexCoord0Vertex
    {
        float m_x;
        float m_y;
        float m_z;
        float m_u;
        float m_v;

        static void init()
        {
            ms_decl
                    .begin()
                    .add(bgfx::Attrib::Position,  3, bgfx::AttribType::Float)
                    .add(bgfx::Attrib::TexCoord0, 2, bgfx::AttribType::Float)
                    .end();
        }

        static bgfx::VertexDecl ms_decl;
    };

    bgfx::VertexDecl PosTexCoord0Vertex::ms_decl;

    void EditorManager::Init()
    {
        sceneWindow = SceneWindow();
        logger = Logger();
        PosTexCoord0Vertex::init();
    }

    void screenSpaceQuad(float _textureWidth, float _textureHeight, float _width = 1.0f, float _height = 1.0f);

    void EditorManager::Update()
    {
        if (Input::GetKeyDown(Input::KeyCode::F1))
            IsEditMode = !IsEditMode;

        if (!IsEditMode)
        { // TODO move this out of the editor. This is actually rendering the main camera to the full screen
            bgfx::touch(100);
            auto appl = app::Application::Instance;
            auto camera = Entities::EntityManager::GetComponent<Entities::Camera>(appl->MainCamera);
            auto s_tex = bgfx::createUniform("s_texColor", bgfx::UniformType::Int1);

            bgfx::setViewClear( 100, BGFX_CLEAR_COLOR, 0x303030ff, 1.0f, 0 );
            bgfx::setViewRect( 100, 0, 0, appl->mWidth, appl->mHeight );

            float proj[16];
            bx::mtxOrtho(proj, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 100.0f, 0.0f, bgfx::getCaps()->homogeneousDepth);

            bgfx::setViewTransform(100, NULL, proj);

            bgfx::setState(BGFX_STATE_WRITE_RGB|BGFX_STATE_WRITE_A);
            bgfx::setTexture(0, s_tex, camera->TextureHandle, BGFX_TEXTURE_U_CLAMP | BGFX_TEXTURE_V_CLAMP);
            screenSpaceQuad((float)appl->mWidth, (float)appl->mHeight);
            bgfx::submit(100, Assets::GetShader("bump"));
            return;
        }

        {
            if (ImGui::BeginMainMenuBar())
            {
                if (ImGui::BeginMenu("File"))
                {
                    if (ImGui::MenuItem("Save", "CTRL+S"))
                    {
                        Entities::SceneManager::SetDirty("main");
                    }
                    ImGui::EndMenu();
                }
                if (ImGui::BeginMenu("Edit"))
                {
                    ImGui::EndMenu();
                }
                ImGui::EndMainMenuBar();
            }


            bool open = true;
            static bool opt_fullscreen_persistant = true;
            static ImGuiDockNodeFlags opt_flags = ImGuiDockNodeFlags_None;
            bool opt_fullscreen = opt_fullscreen_persistant;

            // We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
            // because it would be confusing to have two docking targets within each others.
            ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
            if (opt_fullscreen) {
                ImGuiViewport *viewport = ImGui::GetMainViewport();
                ImGui::SetNextWindowPos(viewport->Pos);
                ImGui::SetNextWindowSize(viewport->Size);
                ImGui::SetNextWindowViewport(viewport->ID);
                //ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
                //ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
                window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize |
                                ImGuiWindowFlags_NoMove;
                window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
            }

            // When using ImGuiDockNodeFlags_PassthruDockspace, DockSpace() will render our background and handle the pass-thru hole, so we ask Begin() to not render a background.
            if (opt_flags & ImGuiDockNodeFlags_PassthruDockspace)
                window_flags |= ImGuiWindowFlags_NoBackground;

            ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
            ImGui::Begin("DockSpace Demo", &open, window_flags);
            ImGui::PopStyleVar();
            ImGuiID dockspace_id = ImGui::GetID("MyDockspace");
            ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), opt_flags);
            ImGui::End();
        }

        sceneWindow.Update();
        logger.Draw();
    }

    void screenSpaceQuad(float _textureWidth, float _textureHeight, float _width, float _height)
    {
        if (3 == bgfx::getAvailTransientVertexBuffer(3, PosTexCoord0Vertex::ms_decl) )
        {
            bgfx::TransientVertexBuffer vb;
            bgfx::allocTransientVertexBuffer(&vb, 3, PosTexCoord0Vertex::ms_decl);
            PosTexCoord0Vertex* vertex = (PosTexCoord0Vertex*)vb.data;

            const float minx = -_width;
            const float maxx =  _width;
            const float miny = 0.0f;
            const float maxy = _height*2.0f;

            auto texelHalf = 0.0f;
            const float texelHalfW = texelHalf/_textureWidth;
            const float texelHalfH = texelHalf/_textureHeight;
            const float minu = -1.0f + texelHalfW;
            const float maxu =  1.0f + texelHalfH;

            const float zz = 0.0f;

            float minv = texelHalfH;
            float maxv = 2.0f + texelHalfH;

            if (bgfx::getCaps()->originBottomLeft)
            {
                float temp = minv;
                minv = maxv;
                maxv = temp;

                minv -= 1.0f;
                maxv -= 1.0f;
            }

            vertex[0].m_x = minx;
            vertex[0].m_y = miny;
            vertex[0].m_z = zz;
            vertex[0].m_u = minu;
            vertex[0].m_v = minv;

            vertex[1].m_x = maxx;
            vertex[1].m_y = miny;
            vertex[1].m_z = zz;
            vertex[1].m_u = maxu;
            vertex[1].m_v = minv;

            vertex[2].m_x = maxx;
            vertex[2].m_y = maxy;
            vertex[2].m_z = zz;
            vertex[2].m_u = maxu;
            vertex[2].m_v = maxv;

            bgfx::setVertexBuffer(0, &vb);
        }
    }
}