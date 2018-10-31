#ifndef RENDERER_H_
#define RENDERER_H_

#include "Common.hpp"
#include "Object.h"

#include "Texture.h"
#include "Shader.h"

#include <map>
#include <string>
#include <memory>

class Renderer
{
  private:
	Renderer() = default;

  public:
	static void buildMesh(Mesh& mesh);
	
	static void draw(const Mesh& mesh, GLenum mode = GL_TRIANGLE_FAN);
	static void draw(Object& obj, const Mesh& mesh, GLenum mode = GL_TRIANGLE_FAN);
	static void draw(Object& obj, const Mesh& mesh, Texture texture, GLenum mode = GL_TRIANGLE_FAN);
};

#endif // RENDERER_H_
