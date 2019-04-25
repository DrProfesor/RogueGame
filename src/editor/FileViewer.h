//
// Created by jwvan on 2019-04-24.
//

#ifndef ROGUEGAME_FILEVIEWER_H
#define ROGUEGAME_FILEVIEWER_H

#include <imgui.h>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

namespace Editor {
    struct FileViewer {
        FileViewer();

        void Update();
    };
}


#endif //ROGUEGAME_FILEVIEWER_H
