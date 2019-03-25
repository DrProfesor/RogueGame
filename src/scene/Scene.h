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

#define SCENE_DIR "/Users/jake/Documents/Dev/RogueGame/assets/scene/"

namespace SceneManager {

    void LoadScene(string sceneName)
    {
        std::ifstream t(SCENE_DIR + sceneName);
        std::string str;

        t.seekg(0, std::ios::end);
        str.reserve(t.tellg());
        t.seekg(0, std::ios::beg);

        str.assign((std::istreambuf_iterator<char>(t)),
                   std::istreambuf_iterator<char>());

        Logger::Log(str.c_str());

        json j = json::parse(str);

    }

    void UnloadScene(string sceneName)
    {

    }

}


#endif //ROGUEGAME_SCENE_H
