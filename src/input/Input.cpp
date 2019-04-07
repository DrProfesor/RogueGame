//
// Created by jwvan on 2019-03-27.
//

#include "Input.h"
#include "../editor/Logger.h"
#include <unordered_set>
#include <iostream>

using namespace Input;

std::unordered_set<int> keysDown = {};
std::unordered_set<int> keys = {};
std::unordered_set<int> keysUp = {};

std::unordered_set<int> buttonsDown = {};
std::unordered_set<int> buttons = {};
std::unordered_set<int> buttonsUp = {};

GLFWwindow * window;
static int ConvertKeyCode(KeyCode kc);
static int ConvertButtonCode(Button kc);

void Input::Init(GLFWwindow * _window)
{
    window = _window;
}

void Input::Update()
{
    keysDown.clear();
    keysUp.clear();

    buttonsDown.clear();
    buttonsUp.clear();

//    Logger::Instance->Info("Keys:");
//    for (auto k : keys)
//    {
//        Logger::Instance->Info("       : %d", k);
//    }
}

bool Input::GetKeyDown(KeyCode key)
{
    return keysDown.count(ConvertKeyCode(key)) > 0;
}

bool Input::GetKey(KeyCode key)
{
    return keys.count(ConvertKeyCode(key)) > 0;
}

bool Input::GetKeyUp(KeyCode key)
{
    return keysUp.count(ConvertKeyCode(key)) > 0;
}

bool Input::GetButtonDown(Button key)
{
    return buttonsDown.count(ConvertButtonCode(key)) > 0;
}

bool Input::GetButton(Button key)
{
    return buttons.count(ConvertButtonCode(key)) > 0;
}

bool Input::GetButtonUp(Button key)
{

    return buttonsUp.count(ConvertButtonCode(key)) > 0;
}

glm::vec2 Input::GetMousePosition()
{
    double x,y;
    glfwGetCursorPos(window, &x, &y);
    return {x,y};
}

void Input::GetMousePosition(double * x, double * y)
{
    glfwGetCursorPos(window, x, y);
}

// GLFW Events
void Input::keyCallback( GLFWwindow* window, int key, int scancode, int action, int mods )
{
    if (action == GLFW_PRESS)
    {
        keysDown.insert(key);
        keys.insert(key);
    }
    else if(action == GLFW_RELEASE)
    {
        keysUp.insert(key);
        keys.erase(key);
    }
}

void Input::charCallback( GLFWwindow* window, unsigned int codepoint )
{

}

void Input::charModsCallback( GLFWwindow* window, unsigned int codepoint, int mods )
{

}

void Input::mouseButtonCallback( GLFWwindow* window, int button, int action, int mods )
{
    if (action == GLFW_PRESS)
    {
        buttonsDown.insert(button);
        buttons.insert(button);
    }
    else if(action == GLFW_RELEASE)
    {
        buttonsUp.insert(button);
        buttons.erase(button);
    }
}

void Input::cursorPosCallback( GLFWwindow* window, double xpos, double ypos )
{

}

void Input::cursorEnterCallback( GLFWwindow* window, int entered )
{

}

void Input::scrollCallback( GLFWwindow* window, double xoffset, double yoffset )
{

}

void Input::dropCallback( GLFWwindow* window, int count, const char** paths )
{

}

static int ConvertKeyCode(KeyCode kc)
{
    switch (kc)
    {
        case A:           return GLFW_KEY_A;
        case B:           return GLFW_KEY_B;
        case C:           return GLFW_KEY_C;
        case D:           return GLFW_KEY_D;
        case E:           return GLFW_KEY_E;
        case F:           return GLFW_KEY_F;
        case G:           return GLFW_KEY_G;
        case H:           return GLFW_KEY_H;
        case I:           return GLFW_KEY_I;
        case J:           return GLFW_KEY_J;
        case K:           return GLFW_KEY_K;
        case L:           return GLFW_KEY_L;
        case M:           return GLFW_KEY_M;
        case N:           return GLFW_KEY_N;
        case O:           return GLFW_KEY_O;
        case P:           return GLFW_KEY_P;
        case Q:           return GLFW_KEY_Q;
        case R:           return GLFW_KEY_R;
        case S:           return GLFW_KEY_S;
        case T:           return GLFW_KEY_T;
        case U:	          return GLFW_KEY_U;
        case V:	          return GLFW_KEY_V;
        case W:	          return GLFW_KEY_W;
        case X:	          return GLFW_KEY_X;
        case Y:	          return GLFW_KEY_Y;
        case Z:           return GLFW_KEY_Z;
        case LEFT_SHIFT:  return GLFW_KEY_LEFT_SHIFT;
        case RIGHT_SHIFT: return GLFW_KEY_RIGHT_SHIFT;
        case LEFT_CTRL:   return GLFW_KEY_LEFT_CONTROL;
        case RIGHT_CTRL:  return GLFW_KEY_RIGHT_CONTROL;
        case TAB:         return GLFW_KEY_TAB;
        case ESC:         return GLFW_KEY_ESCAPE;
        case ENTER:       return GLFW_KEY_ENTER;
        case UP_ARROW:    return GLFW_KEY_UP;
        case DOWN_ARROW:  return GLFW_KEY_DOWN;
        case RIGHT_ARROW: return GLFW_KEY_RIGHT;
        case LEFT_ARROW:  return GLFW_KEY_LEFT;
        case F1: return GLFW_KEY_F1;
        case F2: return GLFW_KEY_F2;
        case F3: return GLFW_KEY_F3;
        case F4: return GLFW_KEY_F4;
        case F5: return GLFW_KEY_F5;
        case F6: return GLFW_KEY_F6;
        case F7: return GLFW_KEY_F7;
        case F8: return GLFW_KEY_F8;
        case F9: return GLFW_KEY_F9;
        case F10: return GLFW_KEY_F10;
        case F11: return GLFW_KEY_F11;
        case F12: return GLFW_KEY_F12;
    }
    return 0;
}

int ConvertButtonCode(Button kc)
{
    switch (kc)
    {
        case LEFT_MOUSE:   return GLFW_MOUSE_BUTTON_LEFT;
        case RIGHT_MOUSE:  return GLFW_MOUSE_BUTTON_RIGHT;
        case MIDDLE_MOUSE: return GLFW_MOUSE_BUTTON_MIDDLE;
    }
    return 0;
}
