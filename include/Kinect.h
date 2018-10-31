#ifndef KINECT_H_
#define KINECT_H_

#include "Texture.h"
#include "ResourceManager.h"
#include "Common.hpp"

#include "../include/Vertex.hpp"
#include "../include/Skeleton.h"
#include <vector>

// OpenNI2 and NiTE headers
#include <OpenNI.h>
#include <NiTE.h>
using namespace openni;

class Kinect
{
private:
	// OpenNI variables
	Device device;
	VideoStream rgbSensor;
	VideoMode vmod;
	Texture rgbTex;
	OniRGB888Pixel* rgbData;
	bool _toogleSkel;

	void enableImageRegistration();

public:
	nite::UserTracker uTracker;
	Kinect();
	~Kinect();
	void toogleSkeleton();

	inline Texture getRGBTex()			{ return rgbTex;		}
	inline OniRGB888Pixel* getRGBData()	{ return rgbData;		}
	inline bool getToogleSkel()			{ return _toogleSkel;	}

	void initOpenNI();
	void initNITE();
	void close();
	
	void updateRGBCam();
	std::vector<Skeleton> trackSkeletons();
	Vertex jointCoords(nite::Skeleton user_skel, nite::JointType joint);
};

#endif	//	KINECT_H_
