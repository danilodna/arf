#ifndef SHADER_H_
#define SHADER_H_
#include <string>

#include "../dependencies/glad/glad.h"
#include <glm/gtc/type_ptr.hpp>

class Shader
{
private:
	// Checks if compilation or linking failed and if so, print the error logs
	void    checkCompileErrors(GLuint object, std::string type);

public:
	// State
	GLuint m_id;

	Shader () = default;
	virtual ~Shader () = default;

	// Set the current shader as active
	Shader& use();

	// Note: geometry source code is optional
	void compile(const GLchar* vertexSource, const GLchar* fragmentSource, const GLchar* geometrySource = NULL);

	// Utility functions
	void    setFloat    (const GLchar *name, GLfloat value, GLboolean useShader = false);
	void    setInteger  (const GLchar *name, GLint value, GLboolean useShader = false);
	void    setVector2f (const GLchar *name, GLfloat x, GLfloat y, GLboolean useShader = false);
	void    setVector2f (const GLchar *name, const glm::vec2 &value, GLboolean useShader = false);
	void    setVector3f (const GLchar *name, GLfloat x, GLfloat y, GLfloat z, GLboolean useShader = false);
	void    setVector3f (const GLchar *name, const glm::vec3 &value, GLboolean useShader = false);
	void    setVector4f (const GLchar *name, GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLboolean useShader = false);
	void    setVector4f (const GLchar *name, const glm::vec4 &value, GLboolean useShader = false);
	void    setMatrix4  (const GLchar *name, const glm::mat4 &matrix, GLboolean useShader = false);
};

#endif // SHADER_H_
