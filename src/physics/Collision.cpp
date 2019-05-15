#include "Collision.h"

namespace Physics {
    std::vector<RaycastHit> Collision::Raycast(vec3 origin, vec3 direction)
    {
        std::vector<RaycastHit> hits;
        auto colliders = EntityManager::GetComponents<Collider>();
        //auto it = colliders.begin(); it != colliders.end(); it++
        for (auto [key, val] : colliders)
        {
            auto transform = EntityManager::GetComponent<Entities::Transform>(key);
            
            RaycastHit hit;
            
            switch(val->Type) 
            {
                case BOX:
                {
                    vec3 collider_position = val->PositionOffset + transform->Position;
                    vec3 collider_size = transform->Scale; // TODO collider size
                    LineBoxCast(origin, direction, collider_position, collider_size, &hit);
                    
                    break;
                }
            }
            
            hit.EntityId = key;
        }
        
        return hits;
    }
    
    bool Collision::LineBoxCast(vec3 line_origin, vec3 line_direction, vec3 box_pos, vec3 box_size, RaycastHit *hit_info)
    {
        vec3 inverse_dir = { 1/line_direction.x, 1/line_direction.y, 1/line_direction.z };
        
        vec3 lb = box_pos - box_size * 0.5f;
        vec3 rt = box_pos + box_size * 0.5f;
        
        float t1 = (lb.x - line_origin.x) * inverse_dir.x;
        float t2 = (rt.x - line_origin.x) * inverse_dir.x;
        float t3 = (lb.y - line_origin.y) * inverse_dir.y;
        float t4 = (rt.y - line_origin.y) * inverse_dir.y;
        float t5 = (lb.z - line_origin.z) * inverse_dir.z;
        float t6 = (rt.z - line_origin.z) * inverse_dir.z;
        
        using namespace glm;
        
        float c1 = min(t1,t2);
        float c2 = min(t3,t4);
        float c3 = min(t5,t6);
        
        float c4 = max(t1,t2);
        float c5 = max(t3,t4);
        float c6 = max(t5,t6);
        
        float cc1 = max(c1, c2);
        float cc2 = min(c4, c5);
        
        float tmin = max(cc1, c3);
        float tmax = min(cc2, c6);
        
        if (tmax < 0)
            return false;
        if (tmin > tmax)
            return false;
        
        *hit_info = {0, line_origin + (line_direction * tmin), line_origin + (line_direction * tmax)};
        return true;
    }
    
}