#ifndef KINECT_H_
#define KINECT_H_

#include "Texture.h"
#include "ResourceManager.h"
#include "Common.hpp"

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

	// Window Variables
	const int w_Width;
	const int	w_Height;

public:
	nite::UserTracker uTracker;
	Kinect(const int window_width, const int window_height);
	~Kinect();
	void toogleSkeleton();

	// inline OniRGB888Pixel* getRGBTex() { return rgbData; }
	inline Texture getRGBTex() { return rgbTex; }
	inline OniRGB888Pixel* getRGBData() { return rgbData; }
	inline bool getToogleSkel() { return _toogleSkel; }

	void initOpenNI();
	void initNITE();
	void updateRGBCam();
	std::vector< std::vector<Vertex> > detectSkeleton();
	Vertex jointCoords(nite::Skeleton user_skel, nite::JointType joint);
	void enableImageRegistration();
	void close();

};

#endif	//	KINECT_H_
