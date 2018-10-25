#include "Skeleton.h"

Skeleton::Skeleton()
{

}

Skeleton::~Skeleton()
{

}

Skeleton::detectSkeleton()
{
  nite::Status niStatus;
  if(uTracker.isValid())
	{
		niStatus = nite::STATUS_OK;
		nite::UserTrackerFrameRef usersFrame;
		niStatus = uTracker.readFrame(&usersFrame);

		if (niStatus == nite::STATUS_OK && usersFrame.isValid())
		{
			const nite::Array<nite::UserData>& users = usersFrame.getUsers();
			for (int i = 0; i < users.getSize(); ++i)
			{
				if (users[i].isNew())
					uTracker.startSkeletonTracking(users[i].getId());

				nite::Skeleton user_skel = users[i].getSkeleton();
				if (user_skel.getState() == nite::SKELETON_TRACKED && users[i].isVisible())
				{
					std::vector<Vertex> v;

					v.push_back(jointCoords(user_skel, nite::JOINT_LEFT_HAND));
					v.push_back(jointCoords(user_skel, nite::JOINT_LEFT_ELBOW));
					v.push_back(jointCoords(user_skel, nite::JOINT_LEFT_SHOULDER));
					v.push_back(jointCoords(user_skel, nite::JOINT_LEFT_ELBOW));
					v.push_back(jointCoords(user_skel, nite::JOINT_LEFT_SHOULDER));
					v.push_back(jointCoords(user_skel, nite::JOINT_RIGHT_SHOULDER));
					v.push_back(jointCoords(user_skel, nite::JOINT_RIGHT_HAND));
					v.push_back(jointCoords(user_skel, nite::JOINT_RIGHT_ELBOW));
					v.push_back(jointCoords(user_skel, nite::JOINT_RIGHT_SHOULDER));
					v.push_back(jointCoords(user_skel, nite::JOINT_RIGHT_ELBOW));

					v.push_back(jointCoords(user_skel, nite::JOINT_LEFT_FOOT));
					v.push_back(jointCoords(user_skel, nite::JOINT_LEFT_KNEE));
					v.push_back(jointCoords(user_skel, nite::JOINT_LEFT_HIP));
					v.push_back(jointCoords(user_skel, nite::JOINT_LEFT_KNEE));
					v.push_back(jointCoords(user_skel, nite::JOINT_LEFT_HIP));
					v.push_back(jointCoords(user_skel, nite::JOINT_RIGHT_HIP));
					v.push_back(jointCoords(user_skel, nite::JOINT_RIGHT_FOOT));
					v.push_back(jointCoords(user_skel, nite::JOINT_RIGHT_KNEE));
					v.push_back(jointCoords(user_skel, nite::JOINT_RIGHT_HIP));
					v.push_back(jointCoords(user_skel, nite::JOINT_RIGHT_KNEE));

					v.push_back(jointCoords(user_skel, nite::JOINT_NECK));
					v.push_back(jointCoords(user_skel, nite::JOINT_HEAD));

					v.push_back(jointCoords(user_skel, nite::JOINT_RIGHT_HIP));
					v.push_back(jointCoords(user_skel, nite::JOINT_RIGHT_SHOULDER));
					v.push_back(jointCoords(user_skel, nite::JOINT_LEFT_HIP));
					v.push_back(jointCoords(user_skel, nite::JOINT_LEFT_SHOULDER));

					Skeletons.push_back(v);
				}
			}
		}
	}
	return Skeletons;
}
