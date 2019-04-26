//
// Created by jwvan on 2019-04-06.
//

#ifndef ROGUEGAME_SCENE_H
#define ROGUEGAME_SCENE_H

#include <string>
#include <filesystem>
#include <vector>
#include "Entities.h"
#include "../utils/Json.h"

namespace Entities {

    // runtime scene
    struct AssetEntry {
        std::string AssetId;
        std::string RelativePath;
        AssetType Type;
    };

    struct Manifest {
        std::vector<AssetEntry> AssetList;
    };

    struct Scene {
        std::string SceneName;

        std::vector<Entity> Entities;
        bool Dirty;

        Manifest SceneManifest;
    };

    struct SceneManager {
        static bool LoadScene(std::string sceneName);
        static void SaveScene(std::string sceneName);
        static void UnloadScene(std::string sceneName);
        static void Update();
        static void SetDirty(std::string sceneName, bool state = true);
    };

}


#endif //ROGUEGAME_SCENE_H
