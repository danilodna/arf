#include "../include/Window.h"
#include <iostream>

bool InputHandler::m_keys[KEYBOARD_KEYS_MAX]; 
bool InputHandler::m_mouse[MOUSE_BUTTONS_MAX];

std::pair<double, double> InputHandler::cursorPos;

void InputHandler::error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void InputHandler::framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.

    glViewport(0, 0, width, height);
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void InputHandler::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    switch(action)
    {
        case GLFW_PRESS:
            { m_keys[key] = true; }
        break;

        case GLFW_RELEASE:
            { m_keys[key] = false; }
        break;
    }

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        std::cout << "dafuq" << std::endl;
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }

    // if (key == GLFW_KEY_A && action == GLFW_PRESS)
    // {
    //     std::cout << "dafuq" << std::endl;
    //     // glfwSetWindowShouldClose(window, GLFW_TRUE);
    // }
}

void InputHandler::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    switch(action)
    {
        case GLFW_PRESS: { m_mouse[button] = true; } break;

        case GLFW_RELEASE: { m_mouse[button] = false; } break;
    }

    // if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
    //     popup_menu();
}

// The callback functions receives the cursor position, measured in screen coordinates but 
// Relative to the top-left corner of the window client area
void InputHandler::cursor_pos_callback(GLFWwindow* window, double xpos, double ypos)
{
    cursorPos.first = xpos;
    cursorPos.second = 600 - ypos;
}

void InputHandler::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
}

void InputHandler::doStuff()
{
    if(m_keys[GLFW_KEY_A]) std::cout << "dafuq" << std::endl;
}
