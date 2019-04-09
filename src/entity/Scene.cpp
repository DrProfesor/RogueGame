//
// Created by jwvan on 2019-04-06.
//

#include "Scene.h"
#include "../utils/Json.h"

namespace fs = std::filesystem;

namespace Entities {

    std::map<std::string, Scene> LoadedScenes = {};

    SceneManager::SceneManager() {}

    bool SceneManager::LoadScene(std::string sceneName)
    {
        fs::path path = std::filesystem::current_path();
        path += "/assets/scene/";
        path += sceneName.c_str();

        if (!fs::exists(path))
        {
            std::cout << "Unable to find scene dir " << sceneName << std::endl;
            return false;
        }

        Scene scene;
        scene.SceneName = sceneName;

        fs::directory_iterator dir(path);
        for (auto entry : dir)
        {
            auto fPath = entry.path();

            std::cout << fPath.extension() << std::endl;

            if (fPath.extension().string().compare(".e") == 0)
            {
                std::ifstream in(fPath.string());
                std::string str((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());

                std::cout << "Loaded " << fPath.string() << std::endl;
                std::cout << str << std::endl;

                EntityManager::CreateEntityFromSerialized(str);
            }
        }

        LoadedScenes[sceneName] = scene;
        return true;
    }

    void SceneManager::SaveScene(std::string sceneName)
    {
        fs::path path = std::filesystem::current_path();
        path += "/assets/scene/";
        path += sceneName.c_str();

        for (auto kp : EntityManager::AllEntities) {
            auto str = EntityManager::SerializeEntity(kp.second);

            auto np = path;
            np += "/";
            np += (std::to_string(kp.first) + std::string(".e")).c_str();

            std::cout << "Writing to " << np.string() << std::endl;

            std::ofstream out;
            out.open(np.string(), std::ios::trunc);
            out << str;
            out.close();
        }
    }

    void SceneManager::UnloadScene(std::string sceneName)
    {

    }
}