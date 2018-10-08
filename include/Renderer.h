#ifndef RENDERER_H_
#define RENDERER_H_

#include "Common.hpp"

#include "Texture.h"
#include "Shader.h"

#include <map>
#include <string>
#include <memory>

class Renderer
{
private:
	std::map<std::string, std::unique_ptr<GLuint> > m_handle;

	Shader m_shader;
	GLuint m_VAO;
	// Initializes and configures the quad's buffer and vertex attributes
	void initRenderData();

public:
	Renderer(Shader& shader);
	virtual ~Renderer();

	void draw(Texture& texture, glm::vec2 currentPos, glm::vec2 size = glm::vec2(10, 10), GLfloat rotate = 0.0f, glm::vec3 color = glm::vec3(0.0f));

	void someFunc();
};

#endif // RENDERER_H_
