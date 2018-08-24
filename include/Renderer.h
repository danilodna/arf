#ifndef RENDERER_H_
#define RENDERER_H_

#include "../dependencies/glad/glad.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../include/Texture.h"
#include "../include/Shader.h"

class Renderer
{
private:
	Shader m_shader;
	GLuint m_VAO;
	// Initializes and configures the quad's buffer and vertex attributes
	void initRenderData();

public:
	Renderer(Shader& shader);
	virtual ~Renderer();

	void draw(Texture& texture, glm::vec2 currentPos, glm::vec2 size = glm::vec2(10, 10), GLfloat rotate = 0.0f, glm::vec3 color = glm::vec3(0.0f));
};

#endif // RENDERER_H_
