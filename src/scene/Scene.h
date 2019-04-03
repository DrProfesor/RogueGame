//
// Created by Jake on 3/21/19.
//

#ifndef ROGUEGAME_SCENE_H
#define ROGUEGAME_SCENE_H

#include <string>
#include <map>
#include <fstream>
#include <streambuf>
#include "../assets/json.h"
#include "../dev/Logger.h"

using namespace std;
using json = nlohmann::json;

struct Scene {

};

#define SCENE_DIR "/RogueGame/assets/scene/"

namespace SceneManager {

    void LoadScene(string sceneName)
    {
//        std::ifstream t(File::GetWorkingDir() + SCENE_DIR + sceneName);
//        std::string str((std::istreambuf_iterator<char>(t)),
//                        std::istreambuf_iterator<char>());
//        Logger::Log(str.c_str());
//        json j = json::parse(str);
    }

    void UnloadScene(string sceneName)
    {

    }

}


#endif //ROGUEGAME_SCENE_H
