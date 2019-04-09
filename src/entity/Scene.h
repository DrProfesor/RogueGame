//
// Created by jwvan on 2019-04-06.
//

#ifndef ROGUEGAME_SCENE_H
#define ROGUEGAME_SCENE_H

#include <string>
#include <filesystem>
#include <vector>
#include "Entities.h"

namespace Entities {

    // runtime scene
    struct Scene {
        std::string SceneName;

        std::vector<Entity> Entities;
    };

    struct SceneManager {
        SceneManager();
        bool LoadScene(std::string sceneName);
        void SaveScene(std::string sceneName);
        void UnloadScene(std::string sceneName);
    };
}


#endif //ROGUEGAME_SCENE_H
