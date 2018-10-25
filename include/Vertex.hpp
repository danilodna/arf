#ifndef VERTEX_HPP_
#define VERTEX_HPP_

// #include <GLFW/glfw3.h>
// #include <glm/vec2.hpp> // vec3, bvec3, dvec3, ivec3 and uvec3
// #include <glm/vec3.hpp> // vec3, bvec3, dvec3, ivec3 and uvec3
// #include <glm/vec4.hpp> // vec4, bvec4, dvec4, ivec4 and uvec4

#include "Common.hpp"
#include <iostream>

class Vertex
{
private:
  glm::vec4 m_position;
  glm::vec4 m_color;

public:
  Vertex() = default;
  Vertex(const glm::vec4 &pos) : m_position(pos){};
  Vertex(const glm::vec4 &pos, const glm::vec4 &color)
      : m_position(pos), m_color(color){};
  ~Vertex() = default;

  void print() const
  {
    std::cout << "Position: (" << m_position.x << ", " << m_position.y << ", "
              << m_position.z << ", " << m_position.w << ") " << std::endl;
  }
};

// ==============

// class Vertex1 : public Vertex
// {
// private:
//   glm::vec4 m_position;
  

// public:
//   Vertex1() = default;
//   Vertex1(const glm::vec4 &pos) : m_position(pos){};

//   ~Vertex1() = default;

//   void print() const
//   {
//     std::cout << "Position: (" << m_position.x << ", " << m_position.y << ", "
//               << m_position.z << ", " << m_position.w << ") " << std::endl;
//   }
// };

// // ==============

// class Vertex2 : public Vertex
// {
// private:
//   glm::vec4 m_position;
//   glm::vec4 m_color;

// public:
//   Vertex2() = default;
//   Vertex2(const glm::vec4 &pos, const glm::vec4 &color)
//       : m_position(pos), m_color(color){};
//   ~Vertex2() = default;

//   void print() const
//   {
//     std::cout << "Position: (" << m_position.x << ", " << m_position.y << ", "
//               << m_position.z << ", " << m_position.w << ") " << std::endl;
//     std::cout << "Color: (" << m_color.x << ", " << m_color.y << ", "
//               << m_color.z << ", " << m_color.w << ") " << std::endl;
//   }
// };

// // ==============

// class Vertex3 : public Vertex
// {
// private:
//   glm::vec4 m_position;
//   glm::vec4 m_color;
//   glm::vec4 m_texCoord;

// public:
//   Vertex3() = default;
//   Vertex3(const glm::vec4 &pos, const glm::vec4 &color, const glm::vec4 &texCoord)
//       : m_position(pos), m_color(color), m_texCoord(texCoord){};
//   ~Vertex3() = default;

//   void print() const
//   {
//     std::cout << "Position: (" << m_position.x << ", " << m_position.y << ", "
//               << m_position.z << ", " << m_position.w << ") " << std::endl;
//     std::cout << "Color: (" << m_color.x << ", " << m_color.y << ", "
//               << m_color.z << ", " << m_color.w << ") " << std::endl;
//     std::cout << "Texture Coordinates: (" << m_texCoord.x << ", " << m_texCoord.y << ") " << std::endl;
//   }
// };

struct AttribInfo
{
  GLuint m_number;
  GLenum m_type;
};

#endif // VERTEX_HPP_