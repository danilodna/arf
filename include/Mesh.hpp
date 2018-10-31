#ifndef MESH_HPP_
#define MESH_HPP_

#include <vector>
#include "Vertex.hpp"
#include "VertexLayout.hpp"
#include "Shader.h"

struct VertexLayout
{
    GLuint m_size;
    GLuint m_type;
};

class Mesh
{
  private:
    enum
    {
        POSITION_VB,
        NUM_BUFFERS
    };

    // Apropriated shader for this mesh
    Shader &m_shader;

    GLuint m_stride;

    // Metadata
    GLuint m_numAttr;
    GLuint m_sizeAttr;
    GLuint m_drawCount;
    GLuint m_indicesCount;

    // OpenGL Handles
    GLuint m_VAO;
    GLuint m_VBO[NUM_BUFFERS];
    GLuint m_EBO[NUM_BUFFERS];
    GLenum m_usage;

    // Data
    std::vector<Vertex> m_vertex;
    std::vector<VertexLayout> m_layout;

  public:
    Mesh() = default;

    // template <typename T>
    // void push(int count)
    // {
    //     static_assert(false);
    // }

    Mesh(Vertex *vertices, Shader &shader, GLuint numVertices, GLuint numAttr, GLuint sizeAttr, GLenum usage) : m_shader(shader), m_stride(0)
    {
        m_drawCount = numVertices; // Number of vertex in the polygon
        m_numAttr = numAttr;       // Number of atributes in each vertex (e.g. vec2 == 2, vec3 == 3, vec4 == 4)
        m_sizeAttr = sizeAttr;     // Size of each attribute
        m_usage = usage;           // Type of usage for OpenGL, e.g. GL_STATIC_DRAW or GL_DYNAMIC_

        for (GLuint i = 0; i < numVertices; ++i)
            m_vertex.emplace_back(vertices[i]);
    }
    Mesh(std::vector<Vertex> vertices, Shader &shader, GLuint numAttr, GLuint sizeAttr, GLenum usage) : m_shader(shader)
    {
        m_drawCount = vertices.size();
        m_numAttr = numAttr;
        m_sizeAttr = sizeAttr;
        m_usage = usage;

        for (const auto& v : vertices)
            m_vertex.emplace_back(v);
    }
    ~Mesh()
    {
        glDeleteBuffers(NUM_BUFFERS, m_VBO);
        glDeleteVertexArrays(1, &m_VAO);
    }

    // void addVertex(Vertex v) { m_vertex.emplace_back(v); }
    void addVertex(Vertex *v, GLuint n)
    {
        for (GLuint i = 0; i < n; ++i)
            m_vertex.emplace_back(v[i]);
    }
    void buildMesh(GLfloat *values, GLuint vNumber, GLuint cNumber);
    void printMesh() const
    {
        GLuint i = 0;
        for (const auto &v : m_vertex)
        {
            std::cout << "Vertex " << i++ << " - ";
            v.print();
        }
    }

    inline Shader getShader() const { return m_shader; }

    inline GLuint getNumAttr() const { return m_numAttr; }
    inline GLuint getSizeAttr() const { return m_sizeAttr; }
    inline GLuint getDrawCount() const { return m_drawCount; }
    inline GLuint getIndicesCount() const { return m_indicesCount; }
    inline GLenum getUsage() const { return m_usage; }
    inline std::vector<Vertex> getVertexList() const { return m_vertex; }

    inline GLuint getVAO() const { return m_VAO; }

    inline void setVAO(GLuint VAO) { m_VAO = VAO; }
    inline void setVBO(GLuint *VBO, GLuint size) { memcpy(m_VBO, VBO, size * sizeof(GLuint)); }
    inline void setEBO(GLuint *EBO, GLuint size) { memcpy(m_EBO, EBO, size * sizeof(GLuint)); }
};

// template <>
// void Mesh::push<float>(int count)
// {
//     m_layout.emplace_back({
//         GLfloat,
//         count,
//     })
// }

// template <>
// void Mesh::push<unsigned int>(int count)
// {
//     m_layout.emplace_back({})
// }

// template <>
// void Mesh::push<char>(int count)
// {
//     m_layout.emplace_back({})
// }

// Mesh::Mesh(Vertex* vertices, GLuint numVertices, GLuint numAttr, GLuint sizeAttr, GLenum usage)
// {
//     m_DrawCount = numVertices;  // Number of vertex in the polygon
// 	m_NumAttr   = numAttr;      // Number of atributes in each vertex (e.g. vec2 == 2, vec3 == 3, vec4 == 4)
// 	m_SizeAttr  = sizeAttr;     // Size of each attribute
//     m_usage     = usage;        // Type of usage for OpenGL, e.g. GL_STATIC_DRAW or GL_DYNAMIC_

//     for(GLuint i = 0; i < numVertices; ++i)
//         m_vertex.emplace_back(vertices[i]);
// }

// Mesh::Mesh(std::vector<Vertex> vertices, GLuint numAttr, GLuint sizeAttr, GLenum usage)
// {
// 	m_DrawCount = vertices.size();
// 	m_NumAttr   = numAttr;
// 	m_SizeAttr  = sizeAttr;
//     m_usage     = usage;

//     for(const auto& v: vertices)
//         m_vertex.emplace_back(v);
// }

// void Mesh::buildMesh(GLfloat *values, GLuint vNumber, GLuint cNumber)
// {
//     glm::vec4 pos;
//     for (GLuint i = 0; i < vNumber; i += cNumber)
//     {
//         for (GLuint j = 0; j < cNumber; ++j)
//             pos[j] = values[i + j];
//         m_vertex.emplace_back(Vertex(pos));
//     }
// }

#endif // MESH_HPP_