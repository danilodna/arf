#ifndef DETECT_COLLISION_HPP_
#define DETECT_COLLISION_HPP_

#include "Common.hpp"
#include "cmath"

class DetectCollision
{
  private:
	DetectCollision() = default;

  public:
	static bool linePoint(glm::vec2 lineA, glm::vec2 lineB, glm::vec2 point, GLfloat offset);
	static bool AABB(glm::vec2 quadCenterA, glm::vec2 quadSizeA,
					 glm::vec2 quadCenterB, glm::vec2 quadSizeB);
	static bool circlePoint(glm::vec2 center, GLfloat radius, glm::vec2 point);
	static bool circleToCircle(glm::vec2 centerA, GLfloat radiusA,
							 glm::vec2 centerB, GLfloat radiusB, GLfloat offset);

	static GLfloat euclidianDistance(glm::vec2 pointA, glm::vec2 pointB);
};

#endif // DETECT_COLLISION_HPP_
