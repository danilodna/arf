#ifndef SHY_OBJECT_H_
#define SHY_OBJECT_H_

#include "Object.h"
#include "ResourceManager.h"

class ShyObject: public Object 
{
private:
	glm::vec2 m_originalPos;

public:
	//	Getters
	inline glm::vec2 getCurrentPosition() const { return m_currentPos; }

	//	Setters
	inline void setCurrentPosition(glm::vec2 newPos) { m_currentPos = newPos; }

	void draw();
	void move();
};

#endif //	SHY_OBJECT_H_
