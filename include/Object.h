#ifndef OBJECT_H_
#define OBJECT_H_

#include "Mesh.hpp"
#include <vector>

class Object
{
  protected:
	glm::vec2	m_currentPos;	// Position in regards to the center of the object
	glm::vec2	m_size;			
	GLfloat		m_rotation;

  public:
	Object() : m_currentPos(glm::vec2(0.5f, 0.5f)), m_size(glm::vec2(1.0f, 1.0f)), m_rotation(0) { };
	virtual ~Object() = default;

	//	Getters
	inline	glm::vec2	getCurrentPosition()	const { return m_currentPos;	}
	inline	glm::vec2	getCurrentSize()		const { return m_size; 			}
	inline	GLfloat		getCurrentOrientation()	const { return m_rotation;		}
			glm::mat4 	getModelMatrix();
	
	//	Setters
	// inline void setPosition		(glm::vec2 position)	{ m_currentPos = position;	}
	// inline void setSize			(glm::vec2 size)		{ m_size = size;			}
	// inline void setOrientation	(GLfloat rotation)		{ m_rotation = rotation;	}

	virtual void resize		(glm::vec2 newSize);
	virtual void resize		(GLfloat x, GLfloat y);
	virtual void rotate		(GLfloat rotation);
	virtual void move		(glm::vec2 newPos);
	virtual void move		(GLfloat x, GLfloat y);
	
	void printPosition() const;


	// virtual void draw() = 0;
	// virtual void move() = 0;
	// virtual void getCenter() = 0;
};

class Circle : public Object
{
private:
	GLfloat m_radius;

public:
	Circle () : m_radius(0.5f) { }
	~Circle () = default;

	inline	GLfloat	getRadius()	const { return m_radius; }

	void resize	(glm::vec2 newSize);
	void resize	(GLfloat x, GLfloat y);
};

#endif //	OBJECT_H_
