#include "../include/Window.h"
#include <iostream>

Window::Window()
{

}

Window::Window(const GLuint width, const GLuint height, const std::string& title)
{
	m_width = width;
	m_height = height;
	m_title = title;

	if(!init())
		std::cerr << "[ERROR]: Could not initialize Window." << '\n';
}

Window::~Window()
{

}

bool Window::init()
{
	/* Initialize the library */
	if (!glfwInit())
	{
		std::cerr << "[ERROR]: Could not initialize GLFW." << '\n';
		return false;
	}

	// Setting some options for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

	/* Create a windowed mode window and its OpenGL context */
	m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), NULL, NULL);
	if (!m_window)
	{
		std::cerr << "[ERROR]: Could not create a window." << '\n';
		glfwTerminate();
		return false;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(m_window);

	// Loading glad
	if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
	{
		std::cerr << "[ERROR]: Failed to initialize GlAD." << std::endl;
		return false;
	}

	// OpenGL configuration
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	// glViewport(0, 0, m_width, m_height);
	glViewport(0, 0, m_width, m_height);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	return true;
}


bool Window::isOpen()
{
	return !glfwWindowShouldClose(m_window);
}

void Window::clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::update()
{
	/* Swap front and back buffers */
	glfwSwapBuffers(m_window);

	/* Poll for and process events */
	glfwPollEvents();
}