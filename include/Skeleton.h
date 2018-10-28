#ifndef SKELETON_H_
#define SKELETON_H_

#include <string>
#include <vector>
#include <map>
#include "Vertex.hpp"
#include "Common.hpp"

#include <OpenNI.h>
#include <NiTE.h>

class Skeleton
{
private:
	nite::Skeleton& m_ID;
	nite::UserTracker& m_userTracker;

	std::map    <unsigned int, glm::vec2 > joints;
	std::vector <std::pair<glm::vec2, glm::vec2> > bones;

public:
	Skeleton (nite::Skeleton& ID, nite::UserTracker& userTracker);
	~Skeleton () = default;

	void makeBones();
	glm::vec2 getJointCoords(nite::JointType joint);
	glm::vec2 getJoint(unsigned int jointType) { return joints[jointType]; }
};

#endif //	SKELETON_H_
