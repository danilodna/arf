#include "../include/Skeleton.h"

Skeleton::Skeleton(nite::Skeleton& ID, nite::UserTracker& userTracker) :
    m_ID(ID), m_userTracker(userTracker)    
{
    m_joints[nite::JOINT_HEAD] =              getJointCoords(nite::JOINT_HEAD);
    m_joints[nite::JOINT_NECK] =              getJointCoords(nite::JOINT_NECK);
    m_joints[nite::JOINT_LEFT_SHOULDER] =     getJointCoords(nite::JOINT_LEFT_SHOULDER);
    m_joints[nite::JOINT_RIGHT_SHOULDER] =    getJointCoords(nite::JOINT_RIGHT_SHOULDER);
    m_joints[nite::JOINT_LEFT_ELBOW] =        getJointCoords(nite::JOINT_LEFT_ELBOW);
    m_joints[nite::JOINT_RIGHT_ELBOW] =       getJointCoords(nite::JOINT_RIGHT_ELBOW);
    m_joints[nite::JOINT_LEFT_HAND] =         getJointCoords(nite::JOINT_LEFT_HAND);
    m_joints[nite::JOINT_RIGHT_HAND] =        getJointCoords(nite::JOINT_RIGHT_HAND);
    m_joints[nite::JOINT_TORSO] =             getJointCoords(nite::JOINT_TORSO);
    m_joints[nite::JOINT_LEFT_HIP] =          getJointCoords(nite::JOINT_LEFT_HIP);
    m_joints[nite::JOINT_RIGHT_HIP] =         getJointCoords(nite::JOINT_RIGHT_HIP);
    m_joints[nite::JOINT_LEFT_KNEE] =         getJointCoords(nite::JOINT_LEFT_KNEE);
    m_joints[nite::JOINT_RIGHT_KNEE] =        getJointCoords(nite::JOINT_RIGHT_KNEE);
    m_joints[nite::JOINT_LEFT_FOOT] =         getJointCoords(nite::JOINT_LEFT_FOOT);
    m_joints[nite::JOINT_RIGHT_FOOT] =        getJointCoords(nite::JOINT_RIGHT_FOOT);

    makeBones();
}

void Skeleton::makeBones()
{
    m_bones.emplace_back(Vertex(m_joints[nite::JOINT_LEFT_HAND]));        
    m_bones.emplace_back(Vertex(m_joints[nite::JOINT_LEFT_ELBOW]));
    m_bones.emplace_back(Vertex(m_joints[nite::JOINT_LEFT_SHOULDER])); 
    m_bones.emplace_back(Vertex(m_joints[nite::JOINT_LEFT_ELBOW]));
    m_bones.emplace_back(Vertex(m_joints[nite::JOINT_LEFT_SHOULDER]));   
    m_bones.emplace_back(Vertex(m_joints[nite::JOINT_RIGHT_SHOULDER]));
    m_bones.emplace_back(Vertex(m_joints[nite::JOINT_RIGHT_HAND]));       
    m_bones.emplace_back(Vertex(m_joints[nite::JOINT_RIGHT_ELBOW]));
    m_bones.emplace_back(Vertex(m_joints[nite::JOINT_RIGHT_SHOULDER]));   
    m_bones.emplace_back(Vertex(m_joints[nite::JOINT_RIGHT_ELBOW]));

    m_bones.emplace_back(Vertex(m_joints[nite::JOINT_LEFT_FOOT]));        
    m_bones.emplace_back(Vertex(m_joints[nite::JOINT_LEFT_KNEE]));
    m_bones.emplace_back(Vertex(m_joints[nite::JOINT_LEFT_HIP]));         
    m_bones.emplace_back(Vertex(m_joints[nite::JOINT_LEFT_KNEE]));
    m_bones.emplace_back(Vertex(m_joints[nite::JOINT_LEFT_HIP]));         
    m_bones.emplace_back(Vertex(m_joints[nite::JOINT_RIGHT_HIP]));
    m_bones.emplace_back(Vertex(m_joints[nite::JOINT_RIGHT_FOOT]));       
    m_bones.emplace_back(Vertex(m_joints[nite::JOINT_RIGHT_KNEE]));
    m_bones.emplace_back(Vertex(m_joints[nite::JOINT_RIGHT_HIP]));        
    m_bones.emplace_back(Vertex(m_joints[nite::JOINT_RIGHT_KNEE]));

    m_bones.emplace_back(Vertex(m_joints[nite::JOINT_NECK]));             
    m_bones.emplace_back(Vertex(m_joints[nite::JOINT_HEAD]));

    m_bones.emplace_back(Vertex(m_joints[nite::JOINT_RIGHT_HIP]));        
    m_bones.emplace_back(Vertex(m_joints[nite::JOINT_RIGHT_SHOULDER]));
    m_bones.emplace_back(Vertex(m_joints[nite::JOINT_LEFT_HIP]));         
    m_bones.emplace_back(Vertex(m_joints[nite::JOINT_LEFT_SHOULDER]));
}

// void Skeleton::makeBones()
// {
//     m_bones.emplace_back(std::make_pair(m_joints[nite::JOINT_LEFT_HAND],        m_joints[nite::JOINT_LEFT_ELBOW]));
//     m_bones.emplace_back(std::make_pair(m_joints[nite::JOINT_LEFT_SHOULDER],    m_joints[nite::JOINT_LEFT_ELBOW]));
//     m_bones.emplace_back(std::make_pair(m_joints[nite::JOINT_LEFT_SHOULDER],    m_joints[nite::JOINT_RIGHT_SHOULDER]));
//     m_bones.emplace_back(std::make_pair(m_joints[nite::JOINT_RIGHT_HAND],       m_joints[nite::JOINT_RIGHT_ELBOW]));
//     m_bones.emplace_back(std::make_pair(m_joints[nite::JOINT_RIGHT_SHOULDER],   m_joints[nite::JOINT_RIGHT_ELBOW]));
  
//     m_bones.emplace_back(std::make_pair(m_joints[nite::JOINT_LEFT_FOOT],        m_joints[nite::JOINT_LEFT_KNEE]));
//     m_bones.emplace_back(std::make_pair(m_joints[nite::JOINT_LEFT_HIP],         m_joints[nite::JOINT_LEFT_KNEE]));
//     m_bones.emplace_back(std::make_pair(m_joints[nite::JOINT_LEFT_HIP],         m_joints[nite::JOINT_RIGHT_HIP]));
//     m_bones.emplace_back(std::make_pair(m_joints[nite::JOINT_RIGHT_FOOT],       m_joints[nite::JOINT_RIGHT_KNEE]));
//     m_bones.emplace_back(std::make_pair(m_joints[nite::JOINT_RIGHT_HIP],        m_joints[nite::JOINT_RIGHT_KNEE]));
    
//     m_bones.emplace_back(std::make_pair(m_joints[nite::JOINT_NECK],             m_joints[nite::JOINT_HEAD]));

//     m_bones.emplace_back(std::make_pair(m_joints[nite::JOINT_RIGHT_HIP],        m_joints[nite::JOINT_RIGHT_SHOULDER]));
//     m_bones.emplace_back(std::make_pair(m_joints[nite::JOINT_LEFT_HIP],         m_joints[nite::JOINT_LEFT_SHOULDER]));
// }

glm::vec3 Skeleton::getJointCoords(nite::JointType joint)
{
	float x, y;

	m_userTracker.convertJointCoordinatesToDepth(
		m_ID.getJoint(joint).getPosition().x,
		m_ID.getJoint(joint).getPosition().y,
		m_ID.getJoint(joint).getPosition().z,
		&x, &y);

	return glm::vec3(x, y, m_ID.getJoint(joint).getPosition().z);
}

// drawCircle(posX, posY, (1 - (user_skel.getJoint(nite::JOINT_HEAD).getPosition().z / 5000)) * 35);

// void Skeleton::detectSkeleton()
// {
//   nite::Status niStatus;
//   if(uTracker.isValid())
// 	{
// 		niStatus = nite::STATUS_OK;
// 		nite::UserTrackerFrameRef usersFrame;
// 		niStatus = uTracker.readFrame(&usersFrame);

// 		if (niStatus == nite::STATUS_OK && usersFrame.isValid())
// 		{
// 			const nite::Array<nite::UserData>& users = usersFrame.getUsers();
// 			for (int i = 0; i < users.getSize(); ++i)
// 			{
// 				if (users[i].isNew())
// 					uTracker.startSkeletonTracking(users[i].getId());

// 				nite::Skeleton user_skel = users[i].getSkeleton();
// 				if (user_skel.getState() == nite::SKELETON_TRACKED && users[i].isVisible())
// 				{
// 					std::vector<Vertex> v;

// 					v.push_back(jointCoords(user_skel, nite::JOINT_LEFT_HAND));
// 					v.push_back(jointCoords(user_skel, nite::JOINT_LEFT_ELBOW));
// 					v.push_back(jointCoords(user_skel, nite::JOINT_LEFT_SHOULDER));
// 					v.push_back(jointCoords(user_skel, nite::JOINT_LEFT_ELBOW));
// 					v.push_back(jointCoords(user_skel, nite::JOINT_LEFT_SHOULDER));
// 					v.push_back(jointCoords(user_skel, nite::JOINT_RIGHT_SHOULDER));
// 					v.push_back(jointCoords(user_skel, nite::JOINT_RIGHT_HAND));
// 					v.push_back(jointCoords(user_skel, nite::JOINT_RIGHT_ELBOW));
// 					v.push_back(jointCoords(user_skel, nite::JOINT_RIGHT_SHOULDER));
// 					v.push_back(jointCoords(user_skel, nite::JOINT_RIGHT_ELBOW));

// 					v.push_back(jointCoords(user_skel, nite::JOINT_LEFT_FOOT));
// 					v.push_back(jointCoords(user_skel, nite::JOINT_LEFT_KNEE));
// 					v.push_back(jointCoords(user_skel, nite::JOINT_LEFT_HIP));
// 					v.push_back(jointCoords(user_skel, nite::JOINT_LEFT_KNEE));
// 					v.push_back(jointCoords(user_skel, nite::JOINT_LEFT_HIP));
// 					v.push_back(jointCoords(user_skel, nite::JOINT_RIGHT_HIP));
// 					v.push_back(jointCoords(user_skel, nite::JOINT_RIGHT_FOOT));
// 					v.push_back(jointCoords(user_skel, nite::JOINT_RIGHT_KNEE));
// 					v.push_back(jointCoords(user_skel, nite::JOINT_RIGHT_HIP));
// 					v.push_back(jointCoords(user_skel, nite::JOINT_RIGHT_KNEE));

// 					v.push_back(jointCoords(user_skel, nite::JOINT_NECK));
// 					v.push_back(jointCoords(user_skel, nite::JOINT_HEAD));

// 					v.push_back(jointCoords(user_skel, nite::JOINT_RIGHT_HIP));
// 					v.push_back(jointCoords(user_skel, nite::JOINT_RIGHT_SHOULDER));
// 					v.push_back(jointCoords(user_skel, nite::JOINT_LEFT_HIP));
// 					v.push_back(jointCoords(user_skel, nite::JOINT_LEFT_SHOULDER));

// 					Skeletons.push_back(v);
// 				}
// 			}
// 		}
// 	}
// 	return Skeletons;
// }
