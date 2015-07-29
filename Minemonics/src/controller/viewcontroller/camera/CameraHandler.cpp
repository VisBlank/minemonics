//# corresponding headers
//# forward declarations
//# system headers
#include <stddef.h>

//## controller headers
//## model headers
//## view headers
#include <OgreMath.h>
#include <OgreNode.h>
#include <OgreSceneNode.h>
#include <OgreVector3.h>

//# custom headers
//## base headers
//## configuration headers
#include <configuration/CameraConfiguration.hpp>

//## controller headers
#include <controller/viewcontroller/camera/CameraHandler.hpp>

//## model headers
//## view headers
//## utils headers

BoostLogger CameraHandler::mBoostLogger; /*<! initialize the boost logger*/
CameraHandler::_Init CameraHandler::_initializer;
CameraHandler::CameraHandler() :
		mCamNode(NULL), mDirection(Ogre::Vector3::ZERO) {
}

CameraHandler::~CameraHandler() {
	delete mCamNode;
	mCamNode = NULL;
}

void CameraHandler::reposition(float timeSinceLastFrame) {
	mCamNode->translate(mDirection * timeSinceLastFrame, Ogre::Node::TS_LOCAL);
}

void CameraHandler::rotate(int pitch, int yaw, int roll) {
	mCamNode->yaw(
			Ogre::Degree(-CameraConfiguration::CAMERA_ROTATION_SPEED * yaw),
			Ogre::Node::TS_WORLD);
	mCamNode->pitch(
			Ogre::Degree(-CameraConfiguration::CAMERA_ROTATION_SPEED * pitch),
			Ogre::Node::TS_LOCAL);
}

void CameraHandler::move(double x, double y, double z) {
	moveX(x);
	moveY(y);
	moveZ(z);
}

void CameraHandler::moveX(double x) {
	mDirection.x = CameraConfiguration::CAMERA_MOVEMENT_SPEED * x;
}

void CameraHandler::moveY(double y) {
	mDirection.y = CameraConfiguration::CAMERA_MOVEMENT_SPEED * y;
}

void CameraHandler::moveZ(double z) {
	mDirection.z = CameraConfiguration::CAMERA_MOVEMENT_SPEED * z;
}

