//
// Created by jwvan on 2019-04-06.
//

#ifndef ROGUEGAME_TIME_H
#define ROGUEGAME_TIME_H

namespace Physics {
    struct Time {
        void Update();

        float lastTime = 0;

        static float deltaTime;
        static float time;
    };
}

#endif //ROGUEGAME_TIME_H
