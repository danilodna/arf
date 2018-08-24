#ifndef SHY_OBJECT_H_
#define SHY_OBJECT_H_

class Object: public ShyObject
{
private:
	glm::vec2 m_originalPos;

public:
	//	Getters
	inline glm::vec2 getCurrentPosition() const {	return m_currentPos; }

	//	Setters
	inline void setCurrentPosition(glm::vec2 newPos) { m_currentPos = newPos; }

	void draw() = 0;
	void move() = 0;
};

#endif //	SHY_OBJECT_H_
