//
// Created by jwvan on 2019-04-06.
//

#include "Scene.h"

namespace fs = std::filesystem;

namespace Entities {

    std::map<std::string, Scene> LoadedScenes = {};

    using nlohmann::json;
    void to_json(json &j, const AssetEntry &val)
    {
        j = json {
                {"AssetId", val.AssetId},
                {"RelativePath", val.RelativePath},
                {"Type", val.Type},
        };
    }

    void from_json(const json &j, AssetEntry &val)
    {
        val.AssetId = j.at("AssetId").get<std::string>();
        val.RelativePath = j.at("RelativePath").get<std::string>();
        val.Type = j.at("Type").get<AssetType>();
    }

    void to_json(json &j, const Manifest &val)
    {
        j = json {
                {"asset-list", val.AssetList}
        };
    }

    void from_json(const json &j, Manifest &val)
    {
        val.AssetList = j.at("asset-list").get<std::vector<AssetEntry>>();
    }

    bool SceneManager::LoadScene(std::string sceneName)
    {
        fs::path path = std::filesystem::current_path();
        path += "/../assets/scene/";
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
            auto ext = fPath.extension().string();

            std::ifstream in(fPath.string());
            std::string str((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());

            std::cout << "Loaded " << fPath.string() << std::endl;

            if (ext.compare(".e") == 0)
            {auto e = EntityManager::CreateEntityFromSerialized(str);
                scene.Entities.push_back(e);
            }

            if (ext.compare(".manifest") == 0)
            {
                auto json = nlohmann::json::parse(str);
                scene.SceneManifest = json.get<Manifest>();
            }
        }

        LoadedScenes[sceneName] = scene;
        return true;
    }

    void SceneManager::SaveScene(std::string sceneName)
    {
        auto scene = LoadedScenes[sceneName];

        fs::path path = std::filesystem::current_path();
        path += "/../assets/scene/";
        path += sceneName.c_str();

        fs::directory_iterator dir(path);
        for (auto entry : dir) fs::remove(entry);

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

        { // write out manifest
            auto manifestPath = path;
            manifestPath += "/";
            manifestPath += sceneName.c_str();
            manifestPath += ".manifest";

            nlohmann::json json = scene.SceneManifest;

            std::ofstream out;
            out.open(manifestPath.string(), std::ios::trunc);
            out << json.dump();
            out.close();
        }

        SetDirty(sceneName, false);
    }

    void SceneManager::UnloadScene(std::string sceneName)
    {

    }

    void SceneManager::Update()
    {
        for (auto kp : LoadedScenes) {
            auto sceneId = kp.first;
            auto scene = kp.second;
            if (scene.Dirty)
            {
                SaveScene(sceneId);
            }
        }
    }

    void SceneManager::SetDirty(std::string sceneName, bool state)
    {
        auto scene = LoadedScenes[sceneName];
        scene.Dirty = state;
        LoadedScenes[sceneName] = scene;
    }
}