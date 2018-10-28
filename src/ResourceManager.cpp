#include "../include/ResourceManager.h"
#include "../include/Window.h"

// 	Library to load textures
#include "../dependencies/stb/stb_image.h"

#include <iostream>
#include <sstream>
#include <fstream>

// Instantiate static variables
std::map<std::string, Texture> ResourceManager::Textures;
std::map<std::string, Shader> ResourceManager::Shaders;

// Loads (and generates) a shader program from file loading vertex, fragment (and geometry) shader's source code. If gShaderFile is not NULL, it also loads a geometry shader
Shader ResourceManager::loadShader(const GLchar *vertexShaderFile, const GLchar *fragmentShaderFile, const GLchar *geometryShaderFile,
								   const std::string &name, GLfloat width, GLfloat height)
{
	Shaders[name] = loadShaderFromFile(vertexShaderFile, fragmentShaderFile, geometryShaderFile);

	// Hiding here matrix projection from user
	glm::mat4 projection = glm::ortho<float>(width, 0, height, 0, -1.0f, 1.0f);
	Shaders[name].use().setMatrix4("projection", projection);

	return Shaders[name];
}

// Retrieves a stored sader
Shader ResourceManager::getShader(const std::string &name)
{
	return Shaders[name];
}

// Loads (and generates) a texture from file
Texture ResourceManager::loadTexture(const GLchar *file, GLboolean alpha, const std::string &name)
{
	Textures[name] = loadTextureFromFile(file, alpha);
	return Textures[name];
}

// Retrieves a stored texture
Texture ResourceManager::getTexture(const std::string &name)
{
	return Textures[name];
}

// Properly de-allocates all loaded resources
void ResourceManager::clear()
{
	// (Properly) delete all shaders
	for (auto iter : Shaders)
		glDeleteProgram(iter.second.m_id);
	// (Properly) delete all textures
	for (auto iter : Textures)
		glDeleteTextures(1, &iter.second.m_id);
}

Shader ResourceManager::loadShaderFromFile(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile)
{
	// 1. Retrieve the vertex/fragment source code from filePath
	std::string vertexCode;
	std::string fragmentCode;
	std::string geometryCode;
	try
	{
		// Open files
		std::ifstream vertexShaderFile(vShaderFile);
		std::ifstream fragmentShaderFile(fShaderFile);
		std::stringstream vShaderStream, fShaderStream;

		// Read file's buffer contents into streams
		vShaderStream << vertexShaderFile.rdbuf();
		fShaderStream << fragmentShaderFile.rdbuf();

		// close file handlers
		vertexShaderFile.close();
		fragmentShaderFile.close();

		// Convert stream into string
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();

		// If geometry shader path is present, also load a geometry shader
		if (gShaderFile != NULL)
		{
			std::ifstream geometryShaderFile(gShaderFile);
			std::stringstream gShaderStream;
			gShaderStream << geometryShaderFile.rdbuf();
			geometryShaderFile.close();
			geometryCode = gShaderStream.str();
		}
	}
	catch (std::exception e)
	{
		std::cout << "[ERROR] SHADER: Failed to read shader files" << std::endl;
	}

	const GLchar *vShaderCode = vertexCode.c_str();
	const GLchar *fShaderCode = fragmentCode.c_str();
	const GLchar *gShaderCode = geometryCode.c_str();

	// 2. Now create shader object from source code
	Shader shader;
	shader.compile(vShaderCode, fShaderCode, gShaderFile != NULL ? gShaderCode : NULL);

	return shader;
}

Texture ResourceManager::loadTextureFromFile(const GLchar *file, GLboolean alpha)
{
	// Create Texture object
	Texture texture;
	if (alpha)
	{
		texture.Internal_Format = GL_RGBA;
		texture.Image_Format = GL_RGBA;
	}

	// Flip texture because OpenGL (0, 0) is left bottom and
	// And the standart (0, 0) is top right
	// stbi_set_flip_vertically_on_load(1);
	// Load image
	int width, height, nrChannelsText;
	unsigned char *image = stbi_load(file, &width, &height, &nrChannelsText, 0);

	GLuint wid = width;
	GLuint hei = height;
	// Now generate texture
	texture.generate(wid, hei, image);

	// And finally free image data
	stbi_image_free(image);

	return texture;
}
