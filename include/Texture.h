#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "Common.hpp"
#include <OpenNI.h>

class Texture
{
public:
	Texture();
	virtual ~Texture();

	// Holds the ID of the texture object, used for all texture operations to reference to this particlar texture
	GLuint m_id;
	
	// Texture image dimensions
	GLuint m_texWidth, m_texHeight;
	
	// Texture Format
	GLuint Internal_Format; // Format of texture object
	GLuint Image_Format; // Format of loaded image

	// Texture configuration
	GLuint Wrap_S; // Wrapping mode on S axis
	GLuint Wrap_T; // Wrapping mode on T axis
	GLuint Filter_Min; // Filtering mode if texture pixels < screen pixels
	GLuint Filter_Max; // Filtering mode if texture pixels > screen pixels

	// Generates texture from image data
	void generate(GLuint width, GLuint height, unsigned char* data = nullptr);
	void bind(const GLuint slot = 0) const;
	void unbind() const;
	void update(unsigned char* data) const;
	void update(OniRGB888Pixel* data) const;

};

#endif // TEXTURE_H_
