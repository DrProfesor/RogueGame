//
// Created by jwvan on 2019-04-06.
//

#include <GLFW/glfw3.h>
#include "Time.h"

namespace Physics {

    float Time::deltaTime = 0;
    float Time::time = 0;

    void Time::Update()
    {
        time = ( float )glfwGetTime();
        deltaTime = time - lastTime;
        lastTime = time;
    }
}