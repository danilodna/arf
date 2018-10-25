#include "../include/Common.hpp"
#include "../include/Window.h"
#include "../include/ResourceManager.h"
#include "../include/Renderer.h"
#include "../include/Object.h"
#include "../include/DetectCollision.hpp"

// #include "../include/Mesh.hpp"
// #include "../include/Vertex.hpp"

//	Tests lib
#include "../tests/TestMenu.hpp"
#include "../tests/TestClearColor.hpp"

int main(int argc, char **argv)
{
    Vertex coloredVertices[] =
        {
            Vertex(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f)), // 0
            Vertex(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)), // 1
            Vertex(glm::vec4(1.0f, 1.0f, 0.0f, 1.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f)), // 2
            Vertex(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f))  // 3
        };

    Vertex texturedVertices[] =
        {
            Vertex(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f), glm::vec4(0.0f, 0.0f, 0.0f, 0.0f)), //  0
            Vertex(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f), glm::vec4(1.0f, 0.0f, 0.0f, 0.0f)), //  1
            Vertex(glm::vec4(1.0f, 1.0f, 0.0f, 1.0f), glm::vec4(1.0f, 1.0f, 0.0f, 0.0f)), //  2
            Vertex(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f), glm::vec4(0.0f, 1.0f, 0.0f, 0.0f))  //  3
        };

    Window window(800, 600, "Eita nois!");

    // Load Shaders
    Shader colored = ResourceManager::loadShader("shaders/colored.vs", "shaders/colored.fs", nullptr, "colored", 800, 600);
    Shader textured = ResourceManager::loadShader("shaders/textured.vs", "shaders/textured.fs", nullptr, "textured", 800, 600);

    // Create Meshes with the data
    Mesh coloredMesh(coloredVertices, colored, 4, 2, 4, GL_STATIC_DRAW);
    Mesh texturedMesh(texturedVertices, textured, 4, 2, 4, GL_STATIC_DRAW);

    // Build the meshs
    Renderer::buildMesh(coloredMesh);
    Renderer::buildMesh(texturedMesh);

    Texture smiley = ResourceManager::loadTexture("textures/awesomeface.png", true, "smiley");
    Texture bored = ResourceManager::loadTexture("textures/boredface.png", true, "bored");

    Circle smile;
    smile.resize(30, 30);

    Circle circle;
    circle.resize(100, 100);
    circle.move(window.getWidth() / 2, window.getHeight() / 2);

    // DeltaTime variables
    GLfloat deltaTime = 0.0f;
    GLfloat lastFrame = 0.0f;

    while (window.isOpen())
    {
        // Calculate delta time
        GLfloat currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        window.clear();
        // std::cout << "(" << InputHandler::getCursorPos().x << ", "
        //  << InputHandler::getCursorPos().y << ")" << std::endl;

        smile.move(InputHandler::getCursorPos());
        Renderer::draw(smile, texturedMesh, smiley, GL_TRIANGLE_FAN);
        if (DetectCollision::circleToCircle(circle.getCurrentPosition(), circle.getRadius(),
                                            smile.getCurrentPosition(), smile.getRadius(), 0.0f))
            Renderer::draw(circle, texturedMesh, bored, GL_TRIANGLE_FAN);
        else
            Renderer::draw(circle, texturedMesh, smiley, GL_TRIANGLE_FAN);

        window.update();
    };

    window.cleanAndDestroyWindow();

    return 0;
}
