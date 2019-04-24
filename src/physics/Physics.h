//
// Created by jwvan on 2019-04-06.
//

#ifndef ROGUEGAME_PHYSICS_H
#define ROGUEGAME_PHYSICS_H

#include <glm/glm.hpp>
#include <glm/vec3.hpp>

#include "Time.h"
#include "../entity/Entities.h"

using namespace Entities;

namespace Physics {
    struct PhysicsManager {
        static void Init();
        static void Update();

        static Time time;
    };

    enum CollisionType {
        INVALID,
        BOX,
    };

    struct Box_Geometry {
        vec3 Size;
    };

    //@component
    struct Collider : Component {
        const char* Name() override { return "Collider"; }

//        vec3 PositionOffset;
//        CollisionType Type;
//
//        union {
//            Box_Geometry Box;
//        };
    };
}


#endif //ROGUEGAME_PHYSICS_H
