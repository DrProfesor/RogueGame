//
// Created by jwvan on 2019-04-06.
//

#include "Physics.h"

namespace Physics{
    Time PhysicsManager::time;

    void PhysicsManager::Init()
    {

    }

    void PhysicsManager::Update()
    {
        time.Update();
    }
}