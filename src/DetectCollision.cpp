#include "../include/DetectCollision.hpp"


bool DetectCollision::linePoint(glm::vec2 lineA, glm::vec2 lineB, glm::vec2 point, GLfloat offset)
{
    GLfloat lineSize = euclidianDistance(lineA, lineB);

    GLfloat firstDist = euclidianDistance(lineA, point);
    GLfloat secondDist = euclidianDistance(lineB, point);

    GLfloat totalDist = firstDist + secondDist;

    if ((totalDist >= lineSize - offset) && (totalDist <= lineSize + offset))
        return true;
    else
        return false;
}

bool DetectCollision::circleToCircle(glm::vec2 centerA, GLfloat radiusA, glm::vec2 centerB, GLfloat radiusB, GLfloat offset)
{
    GLfloat distAB = euclidianDistance(centerA, centerB);

    if(distAB >= radiusA + radiusB + offset)
        return false; // There is no colision
    else
        return true; // There is colision
}

GLfloat DetectCollision::euclidianDistance(glm::vec2 pointA, glm::vec2 pointB)
{
    return sqrt(((pointA.x - pointB.x) * (pointA.x - pointB.x)) + ((pointA.y - pointB.y) * (pointA.y - pointB.y)));
}