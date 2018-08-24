#ifndef OBJECT_H_
#define OBJECT_H_

class Object
{
private:
	glm::vec2 m_currentPos;
	glm::vec2 m_size;

public:
	//	Getters
	inline glm::vec2 getCurrentPosition() const {	return m_currentPos; }

	//	Setters
	inline void setCurrentPosition(glm::vec2 newPos) { m_currentPos = newPos; }

	void draw() = 0;
	void move() = 0;
	void getCenter() = 0;
};

class ObjectFactory
{
private:

public:
	ObjectFactory ();
	virtual ~ObjectFactory ();
};

#endif //	OBJECT_H_
