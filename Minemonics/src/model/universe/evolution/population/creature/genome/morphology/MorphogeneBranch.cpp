/*
 * MorphoGeneBranch.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: leviathan
 */

//# corresponding header
#include <boost/math/constants/constants.hpp>
#include <model/universe/evolution/population/creature/genome/morphology/Morphogene.hpp>
#include <model/universe/evolution/population/creature/genome/morphology/MorphogeneBranch.hpp>

//## view headers
//# custom headers
//## base headers
//## configuration headers
//## controller headers
//## model headers
#include <utils/Randomness.hpp>

MorphogeneBranch::MorphogeneBranch() :
		mBranchGeneType(-1), mFlipped(false), mJointAnchorX(0), mJointAnchorY(
				0), mJointAnchorZ(0), mJointPitch(0), mJointYaw(0), mJointRoll(
				0), mJointPitchMinAngle(0), mJointPitchMaxAngle(0), mJointYawMinAngle(
				0), mJointYawMaxAngle(0), mJointRollMinAngle(0), mJointRollMaxAngle(
				0), mMirrored(0), mSpringPitchDampingCoefficient(0), mJointPitchStiffness(
				0), mSpringYawDampingCoefficient(0), mJointYawStiffness(0), mSpringRollDampingCoefficient(
				0), mJointRollStiffness(0), mJointPitchMotorEnabled(false), mJointYawMotorEnabled(
				false), mJointRollMotorEnabled(false), mJointMaxPitchForce(0), mJointMaxPitchSpeed(
				0), mJointMaxYawForce(0), mJointMaxYawSpeed(0), mJointMaxRollForce(
				0), mJointMaxRollSpeed(0), mJointPitchXOffset(0), mJointPitchYOffset(
				0), mJointPitchAmplitude(0), mJointPitchFrequency(0), mJointYawXOffset(
				0), mJointYawYOffset(0), mJointYawAmplitude(0), mJointYawFrequency(
				0), mJointRollXOffset(0), mJointRollYOffset(0), mJointRollAmplitude(
				0), mJointRollFrequency(0) {
}

MorphogeneBranch::MorphogeneBranch(const MorphogeneBranch& morphogeneBranch) {
	mActive = morphogeneBranch.mActive;
	mBranchGeneType = morphogeneBranch.mBranchGeneType;
	mFlipped = morphogeneBranch.mFlipped;
	mType = morphogeneBranch.mType;
	mJointAnchorX = morphogeneBranch.mJointAnchorX;
	mJointAnchorY = morphogeneBranch.mJointAnchorY;
	mJointAnchorZ = morphogeneBranch.mJointAnchorZ;
	mJointMaxPitchForce = morphogeneBranch.mJointMaxPitchForce;
	mJointMaxPitchSpeed = morphogeneBranch.mJointMaxPitchSpeed;
	mJointMaxRollForce = morphogeneBranch.mJointMaxRollForce;
	mJointMaxRollSpeed = morphogeneBranch.mJointMaxRollSpeed;
	mJointMaxYawForce = morphogeneBranch.mJointMaxYawForce;
	mJointMaxYawSpeed = morphogeneBranch.mJointMaxYawSpeed;
	mJointPitch = morphogeneBranch.mJointPitch;
	mJointPitchMaxAngle = morphogeneBranch.mJointPitchMaxAngle;
	mJointPitchMinAngle = morphogeneBranch.mJointPitchMinAngle;
	mJointPitchMotorEnabled = morphogeneBranch.mJointPitchMotorEnabled;
	mJointPitchStiffness = morphogeneBranch.mJointPitchStiffness;
	mJointYaw = morphogeneBranch.mJointYaw;
	mJointYawMaxAngle = morphogeneBranch.mJointYawMaxAngle;
	mJointYawMinAngle = morphogeneBranch.mJointYawMinAngle;
	mJointYawMotorEnabled = morphogeneBranch.mJointYawMotorEnabled;
	mJointYawStiffness = morphogeneBranch.mJointYawStiffness;
	mJointRoll = morphogeneBranch.mJointRoll;
	mJointRollMaxAngle = morphogeneBranch.mJointRollMaxAngle;
	mJointRollMinAngle = morphogeneBranch.mJointRollMinAngle;
	mJointRollMotorEnabled = morphogeneBranch.mJointRollMotorEnabled;
	mJointRollStiffness = morphogeneBranch.mJointRollStiffness;
	mMirrored = morphogeneBranch.mMirrored;
	mSpringPitchDampingCoefficient =
			morphogeneBranch.mSpringPitchDampingCoefficient;
	mSpringYawDampingCoefficient =
			morphogeneBranch.mSpringYawDampingCoefficient;
	mSpringRollDampingCoefficient =
			morphogeneBranch.mSpringRollDampingCoefficient;

	mJointPitchXOffset = morphogeneBranch.mJointPitchXOffset;
	mJointPitchYOffset = morphogeneBranch.mJointPitchYOffset;
	mJointPitchAmplitude = morphogeneBranch.mJointPitchAmplitude;
	mJointPitchFrequency = morphogeneBranch.mJointPitchFrequency;
	mJointYawXOffset = morphogeneBranch.mJointYawXOffset;
	mJointYawYOffset = morphogeneBranch.mJointYawYOffset;
	mJointYawAmplitude = morphogeneBranch.mJointYawAmplitude;
	mJointYawFrequency = morphogeneBranch.mJointYawFrequency;
	mJointRollXOffset = morphogeneBranch.mJointRollXOffset;
	mJointRollYOffset = morphogeneBranch.mJointRollYOffset;
	mJointRollAmplitude = morphogeneBranch.mJointRollAmplitude;
	mJointRollFrequency = morphogeneBranch.mJointRollFrequency;
}

void MorphogeneBranch::initialize() {
	GeneBranch::initialize(GeneBranch::MORPHOGENE_BRANCH);
	/** Set joint anchor X, Y and Z, where the anchor lies in the center of mass
	 and the X, Y and Z form a vector, pointing to the point on the surface where
	 the joint will be attached.*/
	do {
		mJointAnchorX = Randomness::getSingleton()->nextUnifDouble(-1.0f, 1.0f);
		mJointAnchorY = Randomness::getSingleton()->nextUnifDouble(-1.0f, 1.0f);
		mJointAnchorZ = Randomness::getSingleton()->nextUnifDouble(-1.0f, 1.0f);
	} while (mJointAnchorX == 0 && mJointAnchorY == 0 && mJointAnchorZ == 0);

	/**
	 * The yaw, pitch and roll values representing a correction in angle of the joint anchor on the surface.
	 */
	mJointYaw = Randomness::getSingleton()->nextUnifDouble(
			-boost::math::constants::pi<double>(),
			boost::math::constants::pi<double>());
	mJointPitch = Randomness::getSingleton()->nextUnifDouble(
			-boost::math::constants::pi<double>(),
			boost::math::constants::pi<double>());
	mJointRoll = Randomness::getSingleton()->nextUnifDouble(
			-boost::math::constants::pi<double>(),
			boost::math::constants::pi<double>());

	/**
	 * The joint limits in each direction (pitch=1=Y,yaw=2=Z, roll=0=X)
	 */
	mJointPitchMinAngle = Randomness::getSingleton()->nextUnifDouble(
			0,
			boost::math::constants::pi<double>() / 2.0f);
	mJointPitchMaxAngle = Randomness::getSingleton()->nextUnifDouble(
			0,
			boost::math::constants::pi<double>() / 2.0f);
	mJointYawMinAngle = Randomness::getSingleton()->nextUnifDouble(
			0,
			boost::math::constants::pi<double>() / 2.0f);
	mJointYawMaxAngle = Randomness::getSingleton()->nextUnifDouble(
			0,
			boost::math::constants::pi<double>() / 2.0f);
	mJointRollMinAngle = Randomness::getSingleton()->nextUnifDouble(
			0,
			boost::math::constants::pi<double>() / 2.0f);
	mJointRollMaxAngle = Randomness::getSingleton()->nextUnifDouble(
			0,
			boost::math::constants::pi<double>() / 2.0f);

	/**
	 * Set whether the branch should be mirrored or flipped to the other side.
	 */
	mMirrored = Randomness::getSingleton()->nextUnifBoolean();

	mFlipped = Randomness::getSingleton()->nextUnifBoolean();

	mActive = Randomness::getSingleton()->nextUnifBoolean();

	mBranchGeneType = -1;

	/**
	 * The spring damping coefficient
	 */
	mSpringPitchDampingCoefficient = Randomness::getSingleton()->nextUnifDouble(
			MorphologyConfiguration::JOINT_MIN_SPRING_COEFFICIENT,
			MorphologyConfiguration::JOINT_MAX_SPRING_COEFFICIENT);
	mSpringYawDampingCoefficient = Randomness::getSingleton()->nextUnifDouble(
			MorphologyConfiguration::JOINT_MIN_SPRING_COEFFICIENT,
			MorphologyConfiguration::JOINT_MAX_SPRING_COEFFICIENT);
	mSpringRollDampingCoefficient = Randomness::getSingleton()->nextUnifDouble(
			MorphologyConfiguration::JOINT_MIN_SPRING_COEFFICIENT,
			MorphologyConfiguration::JOINT_MAX_SPRING_COEFFICIENT);

	/**
	 * The joint stiffness
	 */
	mJointPitchStiffness = Randomness::getSingleton()->nextUnifDouble(
			MorphologyConfiguration::JOINT_MIN_STIFFNESS,
			MorphologyConfiguration::JOINT_MAX_STIFFNESS);
	mJointYawStiffness = Randomness::getSingleton()->nextUnifDouble(
			MorphologyConfiguration::JOINT_MIN_STIFFNESS,
			MorphologyConfiguration::JOINT_MAX_STIFFNESS);
	mJointRollStiffness = Randomness::getSingleton()->nextUnifDouble(
			MorphologyConfiguration::JOINT_MIN_STIFFNESS,
			MorphologyConfiguration::JOINT_MAX_STIFFNESS);

	/**
	 * Whether the joint motors are enabled or not.
	 */
	mJointPitchMotorEnabled = Randomness::getSingleton()->nextUnifBoolean();
	mJointYawMotorEnabled = Randomness::getSingleton()->nextUnifBoolean();
	mJointRollMotorEnabled = Randomness::getSingleton()->nextUnifBoolean();

	/**
	 * The maximum joint force
	 */
	mJointMaxPitchForce = Randomness::getSingleton()->nextUnifDouble(
			MorphologyConfiguration::JOINT_MIN_FORCE,
			MorphologyConfiguration::JOINT_MAX_FORCE);
	mJointMaxYawForce = Randomness::getSingleton()->nextUnifDouble(
			MorphologyConfiguration::JOINT_MIN_FORCE,
			MorphologyConfiguration::JOINT_MAX_FORCE);
	mJointMaxRollForce = Randomness::getSingleton()->nextUnifDouble(
			MorphologyConfiguration::JOINT_MIN_FORCE,
			MorphologyConfiguration::JOINT_MAX_FORCE);

	/**
	 * The maximum joint speed
	 */
	mJointMaxPitchSpeed = Randomness::getSingleton()->nextUnifDouble(
			MorphologyConfiguration::JOINT_MIN_SPEED,
			MorphologyConfiguration::JOINT_MAX_SPEED);
	mJointMaxYawSpeed = Randomness::getSingleton()->nextUnifDouble(
			MorphologyConfiguration::JOINT_MIN_SPEED,
			MorphologyConfiguration::JOINT_MAX_SPEED);
	mJointMaxRollSpeed = Randomness::getSingleton()->nextUnifDouble(
			MorphologyConfiguration::JOINT_MIN_SPEED,
			MorphologyConfiguration::JOINT_MAX_SPEED);

	/**
	 * The joint frequency
	 */
	mJointPitchFrequency = Randomness::getSingleton()->nextUnifDouble(
			MorphologyConfiguration::JOINT_MIN_FREQUENCY,
			MorphologyConfiguration::JOINT_MAX_FREQUENCY);
	mJointYawFrequency = Randomness::getSingleton()->nextUnifDouble(
			MorphologyConfiguration::JOINT_MIN_FREQUENCY,
			MorphologyConfiguration::JOINT_MAX_FREQUENCY);
	mJointRollFrequency = Randomness::getSingleton()->nextUnifDouble(
			MorphologyConfiguration::JOINT_MIN_FREQUENCY,
			MorphologyConfiguration::JOINT_MAX_FREQUENCY);

	/**
	 * The joint amplitude
	 */
	mJointPitchAmplitude = Randomness::getSingleton()->nextUnifDouble(
			MorphologyConfiguration::JOINT_MIN_AMPLITUDE,
			MorphologyConfiguration::JOINT_MAX_AMPLITUDE);
	mJointYawAmplitude = Randomness::getSingleton()->nextUnifDouble(
			MorphologyConfiguration::JOINT_MIN_AMPLITUDE,
			MorphologyConfiguration::JOINT_MAX_AMPLITUDE);
	mJointRollAmplitude = Randomness::getSingleton()->nextUnifDouble(
			MorphologyConfiguration::JOINT_MIN_AMPLITUDE,
			MorphologyConfiguration::JOINT_MAX_AMPLITUDE);

	/**
	 * The joint x offset
	 */
	mJointPitchXOffset = Randomness::getSingleton()->nextUnifDouble(
			MorphologyConfiguration::JOINT_MIN_X_OFFSET,
			MorphologyConfiguration::JOINT_MAX_X_OFFSET);
	mJointYawXOffset = Randomness::getSingleton()->nextUnifDouble(
			MorphologyConfiguration::JOINT_MIN_X_OFFSET,
			MorphologyConfiguration::JOINT_MAX_X_OFFSET);
	mJointRollXOffset = Randomness::getSingleton()->nextUnifDouble(
			MorphologyConfiguration::JOINT_MIN_X_OFFSET,
			MorphologyConfiguration::JOINT_MAX_X_OFFSET);

	/**
	 * The joint y offset
	 */
	mJointPitchYOffset = Randomness::getSingleton()->nextUnifDouble(
			MorphologyConfiguration::JOINT_MIN_Y_OFFSET,
			MorphologyConfiguration::JOINT_MAX_Y_OFFSET);
	mJointYawYOffset = Randomness::getSingleton()->nextUnifDouble(
			MorphologyConfiguration::JOINT_MIN_Y_OFFSET,
			MorphologyConfiguration::JOINT_MAX_Y_OFFSET);
	mJointRollYOffset = Randomness::getSingleton()->nextUnifDouble(
			MorphologyConfiguration::JOINT_MIN_Y_OFFSET,
			MorphologyConfiguration::JOINT_MAX_Y_OFFSET);
}

MorphogeneBranch::~MorphogeneBranch() {
}

bool MorphogeneBranch::equals(const MorphogeneBranch& geneBranch) const {


	if(!GeneBranch::equals(geneBranch)){
		return false;
	}

	if (mFlipped != geneBranch.mFlipped) {
		return false;
	}

	if (mMirrored != geneBranch.mMirrored) {
		return false;
	}

	if (mJointAnchorX != geneBranch.mJointAnchorX) {
		return false;
	}

	if (mJointAnchorY != geneBranch.mJointAnchorY) {
		return false;
	}

	if (mJointAnchorZ != geneBranch.mJointAnchorZ) {
		return false;
	}

	if (mJointPitch != geneBranch.mJointPitch) {
		return false;
	}

	if (mJointYaw != geneBranch.mJointYaw) {
		return false;
	}

	if (mJointRoll != geneBranch.mJointRoll) {
		return false;
	}

	if (mJointPitchMinAngle != geneBranch.mJointPitchMinAngle) {
		return false;
	}

	if (mJointPitchMaxAngle != geneBranch.mJointPitchMaxAngle) {
		return false;
	}

	if (mJointYawMinAngle != geneBranch.mJointYawMinAngle) {
		return false;
	}

	if (mJointYawMaxAngle != geneBranch.mJointYawMaxAngle) {
		return false;
	}

	if (mJointRollMinAngle != geneBranch.mJointRollMinAngle) {
		return false;
	}

	if (mJointRollMaxAngle != geneBranch.mJointRollMaxAngle) {
		return false;
	}

	if (mSpringPitchDampingCoefficient
			!= geneBranch.mSpringPitchDampingCoefficient) {
		return false;
	}

	if (mSpringYawDampingCoefficient
			!= geneBranch.mSpringYawDampingCoefficient) {
		return false;
	}


	if (mSpringRollDampingCoefficient
			!= geneBranch.mSpringRollDampingCoefficient) {
		return false;
	}

	if (mJointPitchStiffness != geneBranch.mJointPitchStiffness) {
		return false;
	}

	if (mJointYawStiffness != geneBranch.mJointYawStiffness) {
		return false;
	}

	if (mJointRollStiffness != geneBranch.mJointRollStiffness) {
		return false;
	}

	if (mJointPitchMotorEnabled != geneBranch.mJointPitchMotorEnabled) {
		return false;
	}

	if (mJointYawMotorEnabled != geneBranch.mJointYawMotorEnabled) {
		return false;
	}

	if (mJointRollMotorEnabled != geneBranch.mJointRollMotorEnabled) {
		return false;
	}

	if (mJointMaxPitchForce != geneBranch.mJointMaxPitchForce) {
		return false;
	}

	if (mJointMaxYawForce != geneBranch.mJointMaxYawForce) {
		return false;
	}

	if (mJointMaxRollForce != geneBranch.mJointMaxRollForce) {
		return false;
	}

	if (mJointMaxPitchSpeed != geneBranch.mJointMaxPitchSpeed) {
		return false;
	}

	if (mJointMaxYawSpeed != geneBranch.mJointMaxYawSpeed) {
		return false;
	}

	if (mJointMaxRollSpeed != geneBranch.mJointMaxRollSpeed) {
		return false;
	}

	if (mJointPitchFrequency != geneBranch.mJointPitchFrequency) {
		return false;
	}

	if (mJointYawFrequency != geneBranch.mJointYawFrequency) {
		return false;
	}

	if (mJointRollFrequency != geneBranch.mJointRollFrequency) {
		return false;
	}

	if (mJointPitchAmplitude != geneBranch.mJointPitchAmplitude) {
		return false;
	}

	if (mJointYawAmplitude != geneBranch.mJointYawAmplitude) {
		return false;
	}

	if (mJointRollAmplitude != geneBranch.mJointRollAmplitude) {
		return false;
	}

	if (mJointPitchXOffset != geneBranch.mJointPitchXOffset) {
		return false;
	}

	if (mJointYawXOffset != geneBranch.mJointYawXOffset) {
		return false;
	}

	if (mJointRollXOffset != geneBranch.mJointRollXOffset) {
		return false;
	}

	if (mJointPitchYOffset != geneBranch.mJointPitchYOffset) {
		return false;
	}

	if (mJointYawYOffset != geneBranch.mJointYawYOffset) {
		return false;
	}

	if (mJointRollYOffset != geneBranch.mJointRollYOffset) {
		return false;
	}

	if(mBranchGeneType != geneBranch.mBranchGeneType){
		return false;
	}

	return true;
}

MorphogeneBranch* MorphogeneBranch::clone() {
	return new MorphogeneBranch(*this);
}

void MorphogeneBranch::mutate() {

	//no clean up necessary

	initialize();
}
