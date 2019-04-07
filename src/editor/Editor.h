//
// Created by jwvan on 2019-04-06.
//

#ifndef ROGUEGAME_EDITOR_H
#define ROGUEGAME_EDITOR_H

#include "SceneWindow.h"

namespace Editor {
    struct EditorManager {
        EditorManager();
        void Update();

        bool IsEditMode;
        SceneWindow sceneWindow;
    };
}


#endif //ROGUEGAME_EDITOR_H
