#include "../include/Window.h"
#include "../include/ResourceManager.h"
#include "../include/Renderer.h"
#include <iostream>

//	OpenGL/Window Lib
#include "../dependencies/imgui/imgui.h"
#include "../dependencies/imgui/imgui_impl_glfw_gl3.h"
#include "../dependencies/glad/glad.h"
#include <GLFW/glfw3.h>

//	Some mathematical functions lib
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//      Library to load textures
#include "../dependencies/stb/stb_image.h"


int main(int argc, char** argv)
{
	Window mainWindow(640.0f, 480.0f, "Main");

	ImGui::CreateContext();
	ImGui_ImplGlfwGL3_Init(mainWindow.getWindowPointer(), true);
	ImGui::StyleColorsDark();

	Shader basic = ResourceManager::loadShader("shaders/basic.vs", "shaders/basic.fs", nullptr, "basic");
	glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(mainWindow.getWidth()), 0.0f,  static_cast<GLfloat>(mainWindow.getHeight()), -1.0f, 1.0f);

	basic.use().setMatrix4("projection", projection);
	Renderer render(basic);

	Texture tex;

	GLfloat x = 0, y = 0;
	while (mainWindow.isOpen())
	{
		mainWindow.clear();

		ImGui_ImplGlfwGL3_NewFrame();

		ImGui::Begin("Hehehe");
		ImGui::Text("Mexa o bloco!");
		ImGui::SliderFloat("X: ", &x, 0.0f, static_cast<GLfloat>(mainWindow.getWidth()));
		ImGui::SliderFloat("Y: ", &y, 0.0f, static_cast<GLfloat>(mainWindow.getHeight()));
		ImGui::End();

		render.draw(tex, glm::vec2(x, y), glm::vec2(x, y));

		ImGui::Render();
		ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());

		mainWindow.update();
	}
	ImGui_ImplGlfwGL3_Shutdown();
	ImGui::DestroyContext();
	glfwTerminate();

	return 0;
}
