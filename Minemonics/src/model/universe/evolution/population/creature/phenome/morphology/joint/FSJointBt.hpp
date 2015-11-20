#ifndef MODEL_UNIVERSE_EVOLUTION_POPULATION_CREATURE_PHENOME_MORPHOLOGY_JOINT_JOINTBT_HPP_
#define MODEL_UNIVERSE_EVOLUTION_POPULATION_CREATURE_PHENOME_MORPHOLOGY_JOINT_JOINTBT_HPP_

//# corresponding header
#include <configuration/Definitions.hpp>
#include <model/universe/evolution/population/creature/phenome/morphology/joint/JointPhysics.hpp>

//# forward declarations
class btDynamicsWorld;
class btRigidBody;
class btTransform;
class btMultiBody;
namespace boost {
namespace serialization {
class access;
} /* namespace serialization */
} /* namespace boost */

//# system headers
#include <iostream>
#include <vector>

//## controller headers
//## model headers
#include <boost/serialization/vector.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/version.hpp>
#include <LinearMath/btVector3.h>
#include <OgreVector3.h>

//## view headers
//# custom headers
//## base headers
//## configuration headers
//## controller headers
//## model headers
#include <model/universe/evolution/population/creature/phenome/morphology/effector/motor/FSServoMotor.hpp>

//## view headers
//## utils headers
#include <utils/ogre3D/OgreBulletUtils.hpp>

/**
 * @brief		The Joint Bullet model holds the definition of the joint for the Bullet Physics engine.
 * @details		Details
 * @date		2015-03-25
 * @author		Benjamin Ellenberger
 */
class FSJointBt: public JointPhysics {
public:
	FSJointBt();
	FSJointBt(const FSJointBt& jointBt);
	FSJointBt(btDynamicsWorld* const world, btRigidBody* const bodyA,
		btRigidBody* const bodyB, const btTransform& tframeInA,
		const btTransform& tframeInB, JointPhysics::JointType type,
		bool jointPitchEnabled, bool jointYawEnabled, bool jointRollEnabled,
		btVector3 jointPitchAxis, btVector3 jointLowerLimits,
		btVector3 jointUpperLimits, int ownIndex);

	/**
	 * Initialize the joint bullet physics model.
	 * @param world A handle to the bullet dynamics world.
	 * @param bodyA The rigidbody A to be connected.
	 * @param bodyB The rigidbody B to be connected.
	 * @param tframeInA The joint position in reference frame A.
	 * @param tframeInB The joint position in reference frame B.
	 */
	void initialize();
	virtual ~FSJointBt();

	/**
	 * Initialize the rotational limit motors.
	 * @param maxForces The maximum forces of the joint.
	 * @param maxSpeeds The maximum speeds of the joint.
	 */
	void generateMotors(const btVector3 maxForces, const btVector3 lowerLimits,
		const btVector3 upperLimits, bool positionControlled);

	virtual void setAngularDamping(double jointPitchDamping,
		double jointYawDamping, double jointRollDamping);

	virtual void reset(const Ogre::Vector3 position); /** Reset the joint to the place when the creature was born. */

	virtual void reposition(const Ogre::Vector3 position); /** Reposition the joint without resetting it. */

	void update(double timeSinceLastTick); /** Update the joint bullet physics model. */

	void addToWorld(); /** Add the joint bullet physics model to the world. */

	void removeFromWorld(); /** Remove the joint bullet physics models from the world. */

	virtual void applyJointTorque(int jointAxisIndex, double torque); /**!< Apply a torque to a joint axis*/

	virtual double getJointPos(int jointAxisIndex); /**!< Get the joint position of a joint axis */

	virtual double getJointVel(int jointAxisIndex); /**!< Get the joint velocity of a joint axis */

	/**
	 * Compare the joint bullet physics to another joint bullet physics.
	 * @param jointBt Another joint bullet physics model.
	 * @return If the joint bullet physics is equal to the other joint bullet physics.
	 */
	bool equals(const FSJointBt & jointBt) const;

	/**
	 * Clone the joint bt.
	 * @return The clone of the joint bt.
	 */
	virtual FSJointBt* clone();

	// Accessor methods ##########################

	void setLimits(const Ogre::Vector3 limits) {
		setLimits(OgreBulletUtils::convert(limits));
	}

	void setLimit(JointPhysics::RotationalDegreeOfFreedom dof,
		const double limit) {
//		mJoint->setLimit(dof, limit);
	}

	void setLimits(const btVector3 limits) {
//		mJoint->setLimit(limits.x(),limits.y(),limits.z());
	}

	void setBreakingThreshold(const double breakingThreshold) {
//		mJoint->setBreakingImpulseThreshold(breakingThreshold);
	}

	void setRotationalLimitMotorEnabled(
		const JointPhysics::RotationalDegreeOfFreedom index, const bool enable);

	bool isRotationalLimitMotorEnabled(
		const JointPhysics::RotationalDegreeOfFreedom index) {
		return true;
//		return mJoint->getRotationalLimitMotor(index)->m_enableMotor;
	}

	void setMaxRotationalForce(
		const JointPhysics::RotationalDegreeOfFreedom index,
		const double maxMotorForce) {
//		mJoint->setMaxMotorImpulse(maxMotorForce);

	}

	double getMaxRotationalForce(
		const JointPhysics::RotationalDegreeOfFreedom index) {
		return 0;
//		return mJoint->getRotationalLimitMotor(index)->m_maxMotorForce;
	}

	const std::vector<Motor*>& getMotors() const {
		return mMotors;
	}

	std::vector<Motor*>& getMotors() {
		return mMotors;
	}

	// Serialization ##########################
	friend class boost::serialization::access; /**!< Give access to boost serialization */

	/**
	 * Serializes the joint bullet physics model to a string.
	 * @param os The ostream.
	 * @param jointBt The joint bullet physics model we want to serialize.
	 * @return A string containing all information about the joint bullet physics model.
	 */
	friend std::ostream & operator<<(std::ostream &os,
		const FSJointBt & jointBt) {
		for (std::vector<Motor*>::const_iterator it = jointBt.mMotors.begin(); /**!< The motors of the joint bullet physics model*/
		it != jointBt.mMotors.end(); it++) {
			os << (**it);
			os << "||";
		}
		return os;
	}

	void setMultiBody(btMultiBody* multiBody) {
		mMultiBody = multiBody;
	}

	/**
	 * Serializes the joint bullet physics model to an xml file.
	 * @param ar The archive.
	 * @param The file version.
	 */
	template<class Archive>
	void serialize(Archive & ar, const unsigned int /* file_version */) {
		ar.register_type(static_cast<FSServoMotor*>(NULL));
		ar & BOOST_SERIALIZATION_BASE_OBJECT_NVP(JointPhysics); /**!< Serialize the base object */
	}

private:

	/**
	 * The bullet dynamics world of the bullet physics engine. Reference only.
	 */
	btDynamicsWorld* mWorld;

	btMultiBody* mMultiBody;
};

#endif /* MODEL_UNIVERSE_EVOLUTION_POPULATION_CREATURE_PHENOME_MORPHOLOGY_JOINT_JOINTBT_HPP_ */
