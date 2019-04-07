//
// Created by jwvan on 2019-04-04.
//

#ifndef ROGUEGAME_SCENEWINDOW_H
#define ROGUEGAME_SCENEWINDOW_H

#include <imgui.h>
#include "../input/Input.h"
#include "../entity/Entities.h"
#include "../app/Application.hpp"

namespace Editor {
    struct SceneWindow {

        SceneWindow();
        void Update();

        vec2 last_cursor_pos;

    };
}


#endif //ROGUEGAME_SCENEWINDOW_H
