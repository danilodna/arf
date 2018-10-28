#include "../include/Object.h"

void Object::resize(glm::vec2 newSize)
{
    m_size.x = newSize.x;
    m_size.y = newSize.y;

    // m_currentPos.x -= (m_size.x/2); 
    // m_currentPos.y -= (m_size.y/2); 
}

void Object::resize(GLfloat x, GLfloat y)
{
    m_size.x = x;
    m_size.y = y;

    // m_currentPos.x -= (m_size.x/2); 
    // m_currentPos.y -= (m_size.y/2); 
}

void Object::rotate(GLfloat rotation)
{
    m_rotation += rotation;
}

void Object::move(glm::vec2 newPos)
{
    m_currentPos.x = newPos.x;
    m_currentPos.y = newPos.y;

    // m_currentPos.x = newPos.x - (m_size.x / 2);
    // m_currentPos.y = newPos.y - (m_size.y / 2);
}

void Object::move(GLfloat x, GLfloat y)
{
    m_currentPos.x = x;
    m_currentPos.y = y;
    
    // m_currentPos.x = x - (m_size.x / 2);
    // m_currentPos.y = y - (m_size.y / 2);
}

void Object::printPosition() const
{
    std::cout << "Position: (" << m_currentPos.x << ", " << m_currentPos.y << ") " << std::endl;
}

glm::mat4 Object::getModelMatrix()
{
    glm::mat4 model(1);

    // First translate (transformations are: scale happens first, then rotation and then finall translation happens; reversed order)
    model = glm::translate(model, glm::vec3(m_currentPos, 0.0f)); 

    model = glm::translate(model, glm::vec3(0.5f * m_size.x, 0.5f * m_size.y, 0.0f));   // Move origin of rotation to center of quad
    model = glm::rotate(model, m_rotation, glm::vec3(0.0f, 0.0f, 1.0f));                // Then rotate
    model = glm::translate(model, glm::vec3(-0.5f * m_size.x, -0.5f * m_size.y, 0.0f)); // Move origin back

    model = glm::scale(model, glm::vec3(m_size, 1.0f)); // Last scale

    return model;
}

// ===== CIRCLE =====
void Circle::resize(glm::vec2 newSize)
{
    std::cout << "CIRCLE RESIZE!" << std::endl;

    // New size
    m_size.x = newSize.x;
    m_size.y = newSize.y;

    // New position
    // m_currentPos.x -= (m_size.x/2); 
    // m_currentPos.y -= (m_size.y/2); 

    // New radius
    m_radius = m_size.x / 2;
}

void Circle::resize(GLfloat x, GLfloat y)
{
    std::cout << "CIRCLE RESIZE!" << std::endl;

    // New size
    m_size.x = x;
    m_size.y = y;

    // New position
    // m_currentPos.x -= (m_size.x/2); 
    // m_currentPos.y -= (m_size.y/2); 

    // New radius
    m_radius = m_size.x / 2;
}