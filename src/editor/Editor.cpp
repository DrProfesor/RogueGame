//
// Created by jwvan on 2019-04-06.
//

#include "Editor.h"

namespace Editor {
    EditorManager::EditorManager()
    {
        sceneWindow = SceneWindow();
    }

    void EditorManager::Update()
    {
        if (Input::GetKeyDown(Input::KeyCode::F1))
            IsEditMode = !IsEditMode;

        if (!IsEditMode)
            return;

        sceneWindow.Update();
    }
}