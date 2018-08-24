#include "../include/Renderer.h"
#include "../include/Shader.h"
#include "../include/Texture.h"

#include <iostream>

Renderer::Renderer(Shader& shader)
{
	m_shader = shader;
	initRenderData();
}

Renderer::~Renderer()
{
	glDeleteVertexArrays(1, &m_VAO);
}

void Renderer::draw(Texture& texture, glm::vec2 currentPos, glm::vec2 size, GLfloat rotate, glm::vec3 color)
{
	m_shader.use();

	glm::mat4 model(1.0);
	//model = glm::translate(model, glm::vec3(currentPos, 0.0f)); // First translate (transformations are: scale happens first, then rotation and then finall translation happens; reversed order)

	//model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f)); // Move origin of rotation to center of quad
	//model = glm::rotate(model, rotate, glm::vec3(0.0f, 0.0f, 1.0f)); // Then rotate
	//model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f)); // Move origin back

	model = glm::scale(model, glm::vec3(size, 1.0f)); // Last scale

	m_shader.setMatrix4("model", model);

	// Render textured quad
	m_shader.setVector3f("objectColor", glm::vec3(0.0f, 1.0f, 0.0f));

	glActiveTexture(GL_TEXTURE0);
	texture.bind();

	glBindVertexArray(m_VAO);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	glBindVertexArray(0);
}

void Renderer::initRenderData()
{
	// Configure VAO/VBO
	GLuint VBO;
	// GLfloat vertices[] =
	// {
	// 	// Pos
	// 	0.0f, 1.0f,
	// 	1.0f, 1.0f,
	// 	1.0f, 0.0f,
	// 	0.0f, 0.0f,
	// };

	GLfloat vertices[] =
	{
		// Pos
		-0.5f,  0.5f,
		 0.5f,  0.5f,
		 0.5f, -0.5f,
		-0.5f, -0.5f,
	};

	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindVertexArray(m_VAO);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);	//	Unbind VBO
	glBindVertexArray(0);							//	Unbind VAO
}
