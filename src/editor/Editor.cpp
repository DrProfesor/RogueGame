//
// Created by jwvan on 2019-04-06.
//

#include "Editor.h"

namespace Editor {
    EditorManager::EditorManager()
    {
        sceneWindow = SceneWindow();
        logger = Logger();
    }

    void EditorManager::Update()
    {
        if (Input::GetKeyDown(Input::KeyCode::F1))
            IsEditMode = !IsEditMode;

        if (!IsEditMode)
            return;
        {
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
}