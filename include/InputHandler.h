#ifndef INPUT_HANDLER_H_
#define INPUT_HANDLER_H_

#include "../dependencies/glad/glad.h"
#include <GLFW/glfw3.h>

static const int KEYBOARD_KEYS_MAX = 512;
static const int MOUSE_BUTTONS_MAX = 16;

class InputHandler
{
private:	
	static bool m_keys[KEYBOARD_KEYS_MAX]; 
	static bool m_mouse[MOUSE_BUTTONS_MAX];

public:
	InputHandler () = default ;
	~InputHandler () = default;

	static void error_callback(int error, const char* description);
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void framebuffer_size_callback(GLFWwindow *window, int width, int height);
	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	static void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos);
	static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	static void doStuff();
};

#endif // INPUT_HANDLER_H_
