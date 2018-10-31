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

	std::map    <unsigned int, glm::vec3 > m_joints;
	std::vector <Vertex> m_bones;

public:
	Skeleton (nite::Skeleton& ID, nite::UserTracker& userTracker);
	~Skeleton () = default;

	void makeBones();
	glm::vec3 getJointCoords(nite::JointType joint);
	
	inline glm::vec3 getJoint(unsigned int jointType) { return m_joints[jointType]; }
	inline std::vector<Vertex> getBones() { return m_bones; }
};

#endif //	SKELETON_H_
