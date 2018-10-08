#ifndef WINDOW_H_
#define WINDOW_H_

// #include "../dependencies/glad/glad.h"
// #include <GLFW/glfw3.h>
#include "InputHandler.h"
#include <string>

class Window
{
private:
	std::string m_title;
	GLFWwindow* m_window;
	GLuint m_width, m_height;

	bool initGLFWParams();
	// void oGLInitialConfig();
	// void setCallbackFunctions();

public:
	Window ();
	Window (const GLuint width, const GLuint height, const std::string& title);
	virtual ~Window ();

	inline GLFWwindow* getWindowPointer() const { return m_window; }
	inline GLfloat getWidth() const { return m_width; }
	inline GLfloat getHeight() const { return m_height; }

	bool isOpen();
	void update();
	void clear();
	void cleanAndDestroyWindow();
	bool createWindow();
};

#endif // WINDOW_H_
