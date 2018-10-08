#ifndef OBJECT_H_
#define OBJECT_H_

#include <glm/glm.hpp>

class Object
{
protected:
	glm::vec2 m_currentPos;
	glm::vec2 m_size;

public:
	//	Getters
	inline glm::vec2 getCurrentPosition() const {	return m_currentPos; }

	//	Setters
	inline void setCurrentPosition(glm::vec2 newPos) { m_currentPos = newPos; }

	virtual void draw() = 0;
	virtual void move() = 0;
	virtual void getCenter() = 0;
};

class ObjectFactory
{
private:

public:
	ObjectFactory ();
	virtual ~ObjectFactory ();
};

#endif //	OBJECT_H_
