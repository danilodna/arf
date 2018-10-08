#include "../include/Common.hpp"
#include "../include/Window.h"
#include "../include/ResourceManager.h"
#include "../include/Renderer.h"
#include <iostream>

//	Tests lib
#include "../tests/TestMenu.hpp"
#include "../tests/TestClearColor.hpp"

//	OpenGL/Window Lib
// #include "../dependencies/imgui/imgui.h"
// #include "../dependencies/imgui/imgui_impl_glfw_gl3.h"
// #include "../dependencies/glad/glad.h"
// #include <GLFW/glfw3.h>

//	Some mathematical functions lib
// #include <glm/glm.hpp>
// #include <glm/gtc/matrix_transform.hpp>
// #include <glm/gtc/type_ptr.hpp>

//      Library to load textures
// #include "../dependencies/stb/stb_image.h"


int main(int argc, char** argv)
{
	Window mainWindow(640.0f, 480.0f, "Main");
	// mainWindow.createWindow();

	ImGui::CreateContext();
	ImGui_ImplGlfwGL3_Init(mainWindow.getWindowPointer(), true, NULL);
	ImGui::StyleColorsDark();

	Test* currentTest = nullptr;
	TestMenu* testMenu = new TestMenu(currentTest);
	// argc > 1 ? currentTest =  argv[1] : currentTest = menu;
	currentTest = testMenu;

	Shader basic = ResourceManager::loadShader("shaders/basic.vs", "shaders/basic.fs", nullptr, "basic");
	glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(mainWindow.getWidth()), 0.0f,  static_cast<GLfloat>(mainWindow.getHeight()), -1.0f, 1.0f);
	basic.use().setMatrix4("projection", projection);
	Renderer render(basic);
	Texture tex = ResourceManager::loadTexture("textures/kitten.jpeg", GL_FALSE, "kitten");

	testMenu->addTest<TestClearColor>("Clear Color");

	while (mainWindow.isOpen())
	{
		mainWindow.clear();

		ImGui_ImplGlfwGL3_NewFrame();
		if(currentTest)
		{
			currentTest->onUpdate(0.0f);
			currentTest->onRender();
			ImGui::Begin("Tests");
			if(currentTest != testMenu && ImGui::Button("Back"))
			{
				delete currentTest;
				currentTest = testMenu;
			}
			currentTest->onImGuiRender();
			ImGui::End();
		}

		render.someFunc();

		ImGui::Render();
		ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());

		mainWindow.update();
	}

	mainWindow.cleanAndDestroyWindow();

	return 0;
}
