//
// Created by jwvan on 2019-04-06.
//

#ifndef ROGUEGAME_PHYSICS_H
#define ROGUEGAME_PHYSICS_H

#include <glm/glm.hpp>
#include <glm/vec3.hpp>

#include "Time.h"
#include "Collision.h"
#include "../entity/Entities.h"

using namespace Entities;

namespace Physics {
    struct PhysicsManager {
        static void Init();
        static void Update();
        
        static Time time;
    };
}


#endif //ROGUEGAME_PHYSICS_H
