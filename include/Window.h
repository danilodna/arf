#ifndef WINDOW_H_
#define WINDOW_H_

#include "../dependencies/glad/glad.h"
#include <GLFW/glfw3.h>
#include <string>

class Window
{
private:
	GLFWwindow* m_window;
	GLuint m_width, m_height;
	std::string m_title;

	bool init();

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

};

#endif // WINDOW_H_
