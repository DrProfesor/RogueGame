//
// Created by jwvan on 2019-04-06.
//

#include "Editor.h"
#include "../app/Application.hpp"
#include "../entity/Scene.h"

namespace Editor {

    bool EditorManager::IsEditMode = true;
    SceneWindow EditorManager::SceneWindow;
    Logger EditorManager::logger;
    FileViewer EditorManager::FileViewer;

    bgfx::VertexDecl PosTexCoord0Vertex::ms_decl;

    void EditorManager::Init()
    {
        SceneWindow = Editor::SceneWindow();
        logger = Logger();
        FileViewer = Editor::FileViewer();
        PosTexCoord0Vertex::init();
    }

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

        SceneWindow.Update();
        FileViewer.Update();
        logger.Draw();
    }


}