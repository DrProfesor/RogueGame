//
// Created by jwvan on 2019-04-06.
//

#ifndef ROGUEGAME_EDITOR_H
#define ROGUEGAME_EDITOR_H

#include "SceneWindow.h"
#include "Logger.h"

namespace Editor {
    struct EditorManager {
        static void Init();
        static void Update();

        static bool IsEditMode;
        static SceneWindow sceneWindow;
        static Logger logger;
    };
}


#endif //ROGUEGAME_EDITOR_H
