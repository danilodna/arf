#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include "../include/Shader.h"
#include "../include/Texture.h"

#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <map>


class ResourceManager
{
private:
	ResourceManager() = default;
	// Loads and generates a shader from file
	static Shader    loadShaderFromFile(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile = NULL);
	// Loads a single texture from file
	static Texture loadTextureFromFile(const GLchar *file, GLboolean alpha);

public:
	// Resource storage
	static std::map<std::string, Shader> Shaders;
	static std::map<std::string, Texture> Textures;

	// Loads (and generates) a shader program from file loading vertex, fragment (and geometry) shader's source code. If gShaderFile is not NULL, it also loads a geometry shader
	static Shader loadShader(const GLchar* vertexShaderFile, const GLchar* fragmentShaderFile, const GLchar* geometryShaderFile, const std::string& name);
	// Retrieves a stored sader
	static Shader getShader(const std::string& name);
	// Loads (and generates) a texture from file
	static Texture loadTexture(const GLchar *file, GLboolean alpha, const std::string& name);
	// Retrieves a stored texture
	static Texture getTexture(const std::string& name);
	// Properly de-allocates all loaded resources
	static void clear();
};

#endif // RESOURCE_MANAGER_H
