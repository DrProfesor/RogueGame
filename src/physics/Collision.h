#ifndef ROGUEGAME_COLLISION_H
#define ROGUEGAME_COLLISION_H

#include "../entity/Entities.h"

using namespace Entities;

namespace Physics {
    
    struct RaycastHit {
        unsigned int EntityId;
        
        vec3 p0;
        vec3 p1;
    };
    
    struct Collision {
        static void Init();
        static void Update();
        
        static std::vector<RaycastHit> Raycast(vec3 origin, vec3 direction);
        static bool LineBoxCast(vec3 line_origin, vec3 line_direction, vec3 box_pos, vec3 box_size, RaycastHit *hit_info);
        
    };
    
    enum ColliderType {
        INVALID,
        BOX,
    };
    
    struct Box_Geometry {
        vec3 Size;
    };
}

namespace Entities {
    
    using namespace Physics;
    
    //@component
    struct Collider : Component {
        const char* Name() override { return "Collider"; }
        
        Collider(){}
        
        vec3 PositionOffset; // Local collider offset, collider will use entity transform as well
        ColliderType Type;
        
        union {
            Box_Geometry Box;
        };
    };
}

#endif //ROGUEGAME_COLLISION_H