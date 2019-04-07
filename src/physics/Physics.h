//
// Created by jwvan on 2019-04-06.
//

#ifndef ROGUEGAME_PHYSICS_H
#define ROGUEGAME_PHYSICS_H

#include "Time.h"

namespace Physics {
    struct PhysicsManager {
        PhysicsManager();
        void Update();

        Time time;
    };
}


#endif //ROGUEGAME_PHYSICS_H
