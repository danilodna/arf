#include "../include/Kinect.h"

// TO-DO: CREATE A BETTER ERROR HANDLING FOR THIS CLASS

bool HandleStatus(Status status);
bool HandleStatus(nite::Status status);
char ReadLastCharOfLine();

Kinect::Kinect() : _toogleSkel(true)
{
	rgbTex.generate(KINECT_RESOLUTION_WIDTH, KINECT_RESOLUTION_HEIGHT);
	rgbData = (OniRGB888Pixel *)calloc(KINECT_RESOLUTION_WIDTH * KINECT_RESOLUTION_HEIGHT, sizeof(OniRGB888Pixel));
}

Kinect::~Kinect()
{
	rgbSensor.destroy();
	device.close();
	OpenNI::shutdown();

	free(rgbData);
	rgbData = NULL;
}

void Kinect::initOpenNI()
{
	Status openNIStatus;
	openNIStatus = OpenNI::initialize();
	openNIStatus = device.open(ANY_DEVICE);
	if (!HandleStatus(openNIStatus))
		exit(EXIT_FAILURE);

	// rgbSensor
	openNIStatus = rgbSensor.create(device, SENSOR_COLOR);
	if (!HandleStatus(openNIStatus))
		exit(EXIT_FAILURE);

	vmod.setFps(30);
	vmod.setPixelFormat(PIXEL_FORMAT_RGB888);
	vmod.setResolution(KINECT_RESOLUTION_WIDTH, KINECT_RESOLUTION_HEIGHT); // The resolution is hard coded because is the only one accepted by Kinect v1

	openNIStatus = rgbSensor.setVideoMode(vmod);
	if (!HandleStatus(openNIStatus))
		exit(EXIT_FAILURE);

	openNIStatus = rgbSensor.start();
	if (!HandleStatus(openNIStatus))
		exit(EXIT_FAILURE);
}

void Kinect::initNITE()
{
	nite::Status niStatus;
	niStatus = nite::NiTE::initialize();
	printf("Creating a user tracker object ...\n");
	niStatus = uTracker.create();
	if (!HandleStatus(niStatus))
		exit(EXIT_FAILURE);

	enableImageRegistration();
}

void Kinect::enableImageRegistration()
{
	Status openNIStatus;
	printf("Enabling Depth to Image mapping\n");
	openNIStatus = this->device.setImageRegistrationMode(IMAGE_REGISTRATION_DEPTH_TO_COLOR);
	if (!HandleStatus(openNIStatus))
		exit(EXIT_FAILURE);
}

void Kinect::updateRGBCam()
{
	unsigned int w_Width = KINECT_RESOLUTION_WIDTH;
	unsigned int w_Height = KINECT_RESOLUTION_HEIGHT;

	if (rgbSensor.isValid())
	{
		Status status = STATUS_OK;
		VideoStream *streamPointer = &rgbSensor;
		int streamReadyIndex;
		status = OpenNI::waitForAnyStream(&streamPointer, 1, &streamReadyIndex, 50);

		if (status == STATUS_OK && streamReadyIndex == 0)
		{
			VideoFrameRef newFrame;
			status = rgbSensor.readFrame(&newFrame);
			if (status == STATUS_OK && newFrame.isValid())
			{
				// UPDATING TEXTURE (RGB888 TO RGB888)
				double resizeFactor = std::min((w_Width / (double)newFrame.getWidth()), (w_Height / (double)newFrame.getHeight()));
				unsigned int texture_x = (unsigned int)(w_Width - (resizeFactor * newFrame.getWidth())) / 2;
				unsigned int texture_y = (unsigned int)(w_Height - (resizeFactor * newFrame.getHeight())) / 2;

				// For each row of the image
				for (unsigned int y = 0; y < (w_Height - 2 * texture_y); ++y)
				{
					OniRGB888Pixel *texturePixel = rgbData + ((y + texture_y) * w_Width) + texture_x;

					// For each pixel of the current row
					for (unsigned int x = 0; x < (w_Width - 2 * texture_x); ++x)
					{
						OniRGB888Pixel *streamPixel =
							(OniRGB888Pixel *)((char *)newFrame.getData() +
											   ((int)(y / resizeFactor) * newFrame.getStrideInBytes())) +
							(int)(x / resizeFactor);
						memcpy(texturePixel, streamPixel, sizeof(OniRGB888Pixel));
						texturePixel += 1;
					}
				}
			}
		}
	}
	this->rgbTex.update(this->rgbData);
}

//	A vector for each person skeleton, the person vector stores all the vertices of him
std::vector<Skeleton> Kinect::trackSkeletons()
{
	std::vector<Skeleton> Skeletons;

	if (!uTracker.isValid())
	{
		printf("[ERROR]: uTracker is not valid!\n");
		exit(EXIT_FAILURE);
	}

	nite::Status niStatus = nite::STATUS_OK;
	nite::UserTrackerFrameRef usersFrame;
	niStatus = uTracker.readFrame(&usersFrame);

	if (niStatus != nite::STATUS_OK || !(usersFrame.isValid()) )
	{
		printf("[ERROR]: NiTE status is not OK or User Frame is invalid!\n");
		exit(EXIT_FAILURE);
	}

	const nite::Array<nite::UserData> &users = usersFrame.getUsers();
	for (int i = 0; i < users.getSize(); ++i)
	{
		if (users[i].isNew())
			uTracker.startSkeletonTracking(users[i].getId());

		nite::Skeleton user_skel = users[i].getSkeleton();

		if (user_skel.getState() == nite::SKELETON_TRACKED && users[i].isVisible())
		{
			Skeleton skeleton(user_skel, uTracker);
			Skeletons.emplace_back(skeleton);
		}
	}
	return Skeletons;
}

Vertex Kinect::jointCoords(nite::Skeleton user_skel, nite::JointType joint)
{
	float x, y;
	uTracker.convertJointCoordinatesToDepth(
		user_skel.getJoint(joint).getPosition().x,
		user_skel.getJoint(joint).getPosition().y,
		user_skel.getJoint(joint).getPosition().z,
		&x,
		&y);

	return Vertex(glm::vec2(x, y));
}

void Kinect::close()
{
	rgbSensor.destroy();
	device.close();
	OpenNI::shutdown();

	uTracker.destroy();
	nite::NiTE::shutdown();

	free(rgbData);
	rgbData = NULL;
}

// =========================================================

bool HandleStatus(Status status)
{
	if (status == STATUS_OK)
		return true;

	printf("ERROR: #%d, %s", status, OpenNI::getExtendedError());
	ReadLastCharOfLine();
	return false;
}

bool HandleStatus(nite::Status status)
{
	if (status == nite::STATUS_OK)
		return true;
	printf("ERROR: #%d, %s", status, OpenNI::getExtendedError());
	ReadLastCharOfLine();
	return false;
}

char ReadLastCharOfLine()
{
	int newChar = 0;
	int lastChar;
	fflush(stdout);
	do
	{
		lastChar = newChar;
		newChar = getchar();
	} while ((newChar != '\n') && (newChar != EOF));

	return (char)lastChar;
}

void Kinect::toogleSkeleton()
{
	(_toogleSkel ? (_toogleSkel = false) : (_toogleSkel = true));
}
