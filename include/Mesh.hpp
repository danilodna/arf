#ifndef MESH_HPP_
#define MESH_HPP_

#include <vector>
#include "Vertex.hpp"

class Mesh
{
  private:
    std::vector<Vertex> m_vertex;
    glm::vec4 m_worldPos;

  public:
    Mesh() = default;
    Mesh(GLfloat *values, GLuint vNumber, GLuint cNumber);
    ~Mesh() = default;

    void addVertex(Vertex v) { m_vertex.emplace_back(v); }
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
            std::cout << "Vertex " <<  i++ << " - ";
            v.printVertexPos();
        }
    }
};

Mesh::Mesh(GLfloat *values, GLuint vNumber, GLuint cNumber)
{
    buildMesh(values, vNumber, cNumber);
}

void Mesh::buildMesh(GLfloat *values, GLuint vNumber, GLuint cNumber)
{
    glm::vec4 pos;
    for (GLuint i = 0; i < vNumber; i += cNumber)
    {
        for (GLuint j = 0; j < cNumber; ++j) pos[j] = values[i + j];
        m_vertex.emplace_back(Vertex(pos));
    }
}

#endif // MESH_HPP_