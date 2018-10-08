#ifndef VERTEX_HPP_
#define VERTEX_HPP_

#include <GLFW/glfw3.h>
#include <glm/vec2.hpp>               // vec3, bvec3, dvec3, ivec3 and uvec3
#include <glm/vec4.hpp>               // vec4, bvec4, dvec4, ivec4 and uvec4

#include <iostream>

class Vertex
{
private:
    glm::vec4 m_position; 
    glm::vec4 m_color; 
    glm::vec2 m_texCoord; 

public:
    Vertex() = default;
    Vertex(const glm::vec4& pos) : m_position(pos) {};
    Vertex(const glm::vec4& pos, const glm::vec4& color) : m_position(pos), m_color(color) {};
    Vertex(const glm::vec4& pos, const glm::vec2& coord) : m_position(pos), m_texCoord(coord) {};
    Vertex(const glm::vec4& pos, const glm::vec4& color, const glm::vec2& coord) : 
            m_position(pos), m_color(color), m_texCoord(coord) {};


    ~Vertex() = default;

    void printVertexPos() const
    { 
        std::cout << "Position: (" << m_position.x << ", " << m_position.y << ", " 
                                   << m_position.z << ", " << m_position.w << ") " << std::endl; 
    
    }

    void printVertexColor() const
    { 
        std::cout << "Color: (" << m_color.x << ", " << m_color.y << ", " 
                                << m_color.z << ", " << m_color.w << ") " << std::endl; 
    
    }

    void printVertexTexCoord() const
    { 
        std::cout << "Texture Coordinates: (" << m_texCoord.x << ", " << m_texCoord.y << ") " << std::endl;  
    }

    void printVertex() const
    {
        std::cout << " == Vertex Info == " << std::endl;
        printVertexPos();
        printVertexColor();
        printVertexTexCoord();
        std::cout << " ================= " << std::endl;
    }
};



#endif // VERTEX_HPP_