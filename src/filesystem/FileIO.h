//
// Created by jwvan on 2019-03-25.
//

#ifndef ROGUEGAME_FILEIO_H
#define ROGUEGAME_FILEIO_H

#include <filesystem>
#include <string>

namespace File {

    std::string GetWorkingDir()
    {
        return std::filesystem::current_path().string();
    }
}

#endif //ROGUEGAME_FILEIO_H
