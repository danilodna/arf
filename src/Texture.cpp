#include "../include/Texture.h"

#include <iostream>

Texture::Texture()
	: m_texWidth(0), m_texHeight(0), Internal_Format(GL_RGB), Image_Format(GL_RGB), Wrap_S(GL_REPEAT), Wrap_T(GL_REPEAT), Filter_Min(GL_LINEAR), Filter_Max(GL_LINEAR)
{
	glGenTextures(1, &m_id);
}

Texture::~Texture()
{
	
}

void Texture::generate(GLuint width, GLuint height, unsigned char* data)
{
	m_texWidth = width;
	m_texHeight = height;

	glBindTexture(GL_TEXTURE_2D, m_id); // Create Texture

	glTexImage2D(GL_TEXTURE_2D, 0, this->Internal_Format, m_texWidth, m_texHeight, 0, this->Image_Format, GL_UNSIGNED_BYTE, data);
	// Set Texture wrap and filter modes
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this->Wrap_S);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this->Wrap_T);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->Filter_Min);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->Filter_Max);

	glBindTexture(GL_TEXTURE_2D, 0);	// Unbind texture
}

void Texture::bind() const
{
	glBindTexture(GL_TEXTURE_2D, m_id);
}

void Texture::unbind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::update(unsigned char* data) const
{
  glBindTexture(GL_TEXTURE_2D, m_id);
	glTexImage2D(GL_TEXTURE_2D, 0, this->Internal_Format, m_texWidth, m_texHeight, 0, this->Image_Format, GL_UNSIGNED_BYTE, data);
  glBindTexture(GL_TEXTURE_2D, 0);
}
