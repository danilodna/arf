#ifndef SKELETON_H_
#define SKELETON_H_

#include <string>

class Skeleton
{
private:
	nite::UserTracker uTracker;
	std::map    < std::string, glm::vec2 > joints;
	std::vector < std::pair< glm::vec2, glm::vec2 > > bones;

public:
	Skeleton ();
	virtual ~Skeleton ();
};

#endif //	SKELETON_H_
