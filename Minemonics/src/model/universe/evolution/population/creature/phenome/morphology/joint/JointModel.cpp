//# corresponding header
#include <model/universe/evolution/population/creature/phenome/morphology/joint/JointModel.hpp>

//# forward declarations
#ifndef NULL
#define NULL 0
#endif

//# system headers
//## controller headers
//## model headers
#include <LinearMath/btTransform.h>

//## view headers
//# custom headers
//## base headers
//## configuration headers
//## controller headers
//## model headers
#include <model/universe/evolution/population/creature/phenome/morphology/joint/JointBt.hpp>

//## view headers
//## utils headers

JointModel::JointModel() :
		mJointPhysics(NULL) {

}

JointModel::~JointModel() {
	delete mJointPhysics;
	mJointPhysics = NULL;
}

void JointModel::initialize(btDynamicsWorld* world, btRigidBody* limbA,
		btRigidBody* limbB, btTransform localA, btTransform localB) {
	ComponentModel::initialize(ComponentModel::JointComponent);

	mJointPhysics = new JointBt();
	((JointBt*) mJointPhysics)->initialize(world, limbA, limbB, localA, localB);
}

void JointModel::setAngularLimits(Ogre::Vector3 angularLowerLimit,
		Ogre::Vector3 angularUpperLimit) {
	mJointPhysics->setAngularLimits(angularLowerLimit, angularUpperLimit);
}

void JointModel::setAngularStiffness(double jointPitchStiffness,
		double jointYawStiffness, double jointRollStiffness) {
	mJointPhysics->setAngularStiffness(jointPitchStiffness, jointYawStiffness,
			jointRollStiffness);
}

void JointModel::setAngularDamping(double springPitchDampingCoefficient,
		double springYawDampingCoefficient,
		double springRollDampingCoefficient) {
	mJointPhysics->setAngularDamping(springPitchDampingCoefficient,
			springYawDampingCoefficient, springRollDampingCoefficient);
}

bool JointModel::equals(const JointModel& jointModel) const {
//	if(mJointPhysics->equals(*jointModel.mJointPhysics))
//	{
//		return false;
//	}

	return true;
}

void JointModel::enableAngularMotor(bool pitchEnable, bool yawEnable,
		bool rollEnable) {
	mJointPhysics->setRotationalLimitMotorEnabled(JointPhysics::RDOF_PITCH, pitchEnable);
	mJointPhysics->setRotationalLimitMotorEnabled(JointPhysics::RDOF_YAW, yawEnable);
	mJointPhysics->setRotationalLimitMotorEnabled(JointPhysics::RDOF_ROLL, rollEnable);
}

void JointModel::initializeRotationalLimitMotors(Ogre::Vector3 maxForces,
		Ogre::Vector3 maxSpeeds) {
	((JointBt*) mJointPhysics)->initializeRotationalLimitMotors(
			OgreBulletUtils::convert(maxForces),
			OgreBulletUtils::convert(maxSpeeds));
}

