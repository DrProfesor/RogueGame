//
// Created by jwvan on 2019-03-27.
//

#ifndef ROGUEGAME_INPUT_H
#define ROGUEGAME_INPUT_H

#include <glm/vec2.hpp>
#include <GLFW/glfw3.h>

namespace Input {
    enum KeyState {
        KEY_UP, KEY_DOWN, HELD,
    };

    enum KeyCode {
        A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
        LEFT_SHIFT, RIGHT_SHIFT, LEFT_CTRL, RIGHT_CTRL, TAB, ESC, ENTER, UP_ARROW, DOWN_ARROW, LEFT_ARROW, RIGHT_ARROW
    };

    enum Button {
        LEFT_MOUSE, RIGHT_MOUSE, MIDDLE_MOUSE,
    };

    void Init(GLFWwindow * _window);
    void Update();

    bool GetKeyDown(KeyCode kc);
    bool GetKey(KeyCode kc);
    bool GetKeyUp(KeyCode kc);

    bool GetButtonDown(Button button);
    bool GetButton(Button button);
    bool GetButtonUp(Button button);

    glm::vec2 GetMousePosition();
    void GetMousePosition(double * x, double * y);

    // should only be called from application
    void keyCallback( GLFWwindow* window, int key, int scancode, int action, int mods );
    void charCallback( GLFWwindow* window, unsigned int codepoint );
    void charModsCallback( GLFWwindow* window, unsigned int codepoint, int mods );
    void mouseButtonCallback( GLFWwindow* window, int button, int action, int mods );
    void cursorPosCallback( GLFWwindow* window, double xpos, double ypos );
    void cursorEnterCallback( GLFWwindow* window, int entered );
    void scrollCallback( GLFWwindow* window, double xoffset, double yoffset );
    void dropCallback( GLFWwindow* window, int count, const char** paths );
}

#endif //ROGUEGAME_INPUT_H
