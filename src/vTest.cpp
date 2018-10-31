#include "../include/Common.hpp"
#include "../include/Window.h"
#include "../include/ResourceManager.h"
#include "../include/Renderer.h"
#include "../include/Object.h"
#include "../include/DetectCollision.hpp"
#include "../include/Kinect.h"

//	Tests lib
#include "../tests/TestMenu.hpp"
#include "../tests/TestClearColor.hpp"

void printVec(glm::vec2 vec2) { std::cout << "(" << vec2.x << ", " << vec2.y << ")" << std::endl; }
void printVec(glm::vec3 vec3) { std::cout << "(" << vec3.x << ", " << vec3.y << ", " << vec3.z << ")" << std::endl; }
void printVec(glm::vec4 vec4) { std::cout << "(" << vec4.x << ", " << vec4.y << ", " << vec4.z << ", " << vec4.w << ")" << std::endl; }

int main(int argc, char **argv)
{
    Vertex texturedVertices[] =
        {
            Vertex(glm::vec4(-0.5f, 0.5f, 0.0f, 1.0f), glm::vec4(0.0f, 1.0f, 0.0f, 0.0f)), //  3
            Vertex(glm::vec4(0.5f, 0.5f, 0.0f, 1.0f), glm::vec4(1.0f, 1.0f, 0.0f, 0.0f)),  //  2
            Vertex(glm::vec4(0.5f, -0.5f, 0.0f, 1.0f), glm::vec4(1.0f, 0.0f, 0.0f, 0.0f)), //  1
            Vertex(glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f), glm::vec4(0.0f, 0.0f, 0.0f, 0.0f)) //  0
        };

    Window window(640, 480, "Eita nois!");

    // Load Shaders
    // Shader colored = ResourceManager::loadShader("shaders/colored.vs", "shaders/colored.fs", nullptr, "colored", 640, 480);
    Shader textured = ResourceManager::loadShader("shaders/textured.vs", "shaders/textured.fs", nullptr, "textured", 640, 480);
    Shader skelShader = ResourceManager::loadShader("shaders/skeleton.vs", "shaders/skeleton.fs", nullptr, "skelShader", 640, 480);

    // Create Meshes with the data
    Mesh texturedMesh(texturedVertices, textured, 4, 2, 4, GL_STATIC_DRAW);
    texturedMesh.push<glm::vec4>(4);
    texturedMesh.push<glm::vec4>(4);

    // Build the meshs
    Renderer::buildMesh(texturedMesh);

    Texture smiley = ResourceManager::loadTexture("textures/awesomeface.png", true, "smiley");
    Texture bored = ResourceManager::loadTexture("textures/boredface.png", true, "bored");

    Kinect kinect;
    kinect.initOpenNI();
    kinect.initNITE();

    Object rgbCam, emoteFace;
    rgbCam.resize(window.getWidth(), window.getHeight());
    rgbCam.move(window.getWidth() / 2, window.getHeight() / 2);
    emoteFace.resize(75.0f, 75.0f);

    // DeltaTime variables
    GLfloat deltaTime = 0.0f;
    GLfloat lastFrame = 0.0f;

    glm::vec3 clear_color;

    glLineWidth(5);

    while (window.isOpen())
    {
        // Calculate delta time
        GLfloat currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        window.clear();

        std::vector<Skeleton> skels = kinect.trackSkeletons();
        kinect.updateRGBCam();
        Renderer::draw(rgbCam, texturedMesh, kinect.getRGBTex(), GL_TRIANGLE_FAN);

        // Start the Dear ImGui frame
        ImGui_ImplGlfwGL3_NewFrame();
        {
            static float f = 0.0f;
            static int counter = 0;
            ImGui::Text("Hello, world!");                            // Display some text (you can use a format string too)
            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);             // Edit 1 float using a slider from 0.0f to 1.0f
            ImGui::ColorEdit3("clear color", (float *)&clear_color); // Edit 3 floats representing a color
            ImGui::Text("Red: %.2f\n Green: %.2f\n Blue: %.2f", clear_color.x, clear_color.y, clear_color.z);

            if (ImGui::Button("Button")) // Buttons return true when clicked (NB: most widgets return true when edited/activated)
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        }

        if (!skels.empty())
        {
            glm::vec3 skel_pos = skels[0].getJoint(nite::JOINT_HEAD);

            emoteFace.move(skel_pos.x, skel_pos.y);
            emoteFace.resize((5000 / skel_pos.z) * 26, (5000 / skel_pos.z) * 28);

            std::cout << skels[0].getBones().size() << std::endl;

            Mesh nononon(skels[0].getBones(), skelShader, 2, 4, GL_DYNAMIC_DRAW);
            nononon.push<glm::vec4>(4);
            nononon.push<glm::vec4>(4);
            Renderer::buildMesh(nononon);

            Renderer::draw(nononon, GL_LINES);
            Renderer::draw(emoteFace, texturedMesh, smiley, GL_TRIANGLE_FAN);
        }

        ImGui::Render();
        ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
        window.update();
    };

    ImGui_ImplGlfwGL3_Shutdown();
    kinect.close();
    window.cleanAndDestroyWindow();

    return 0;
}
