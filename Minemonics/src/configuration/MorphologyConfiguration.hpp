#ifndef CONFIGURATION_MORPHOLOGYCONFIGURATION_H_
#define CONFIGURATION_MORPHOLOGYCONFIGURATION_H_

//# corresponding headers
//# forward declarations
//# system headers
#include <math.h>

//## controller headers
//## model headers
//## view headers
//# custom headers
//## base headers
//## configuration headers
//## controller headers
//## model headers
//## view headers
//## utils headers

/**
 * @brief		The configuration of the creature morphology.
 * It defines limits of size and weight that are usually given by nature.
 * @details		Details
 * @date		2015-02-26
 * @author		Benjamin Ellenberger
 */
class MorphologyConfiguration {
public:

	/**
	 * The limb minimum dimension size
	 */
	static const double LIMB_MIN_SIZE = 0.1;

	/**
	 * The limb maximum dimension size
	 */
	static const double LIMB_MAX_SIZE = 10;

	/**
	 * The limb minimum density
	 */
	static const double LIMB_MIN_DENSITY = 0.01;
	//TODO: Optimize with bullet physics engine

	/**
	 * The limb maximum density
	 */
	static const double LIMB_MAX_DENSITY = 1;
	//TODO: Optimize with bullet physics engine

	/**
	 * The limb initial restitution/elasticity.
	 */
	static const double LIMB_INITIAL_RESTITUTION = 0.2;

	/**
	 * The limb initial friction
	 */
	static const double LIMB_INITIAL_FRICTION = 10.0f;

	/**
	 * This limit is intended to help the system avoid the numerical explosions that can arise from time to time during creature evolution. This is done to discourage the evolution of undesirable creatures that exploit the weaknesses in the physics engine.
	 */
	static const double LIMB_MAX_VELOCITY = 80000;

	/**
	 * The limb scale min constant determines how much the subtree of this body segment should be scaled at least.
	 */
	static const double LIMB_SCALE_MIN = -0.5;

	/**
	 * The limb scale max constant determines how much the subtree of this body segment should be scaled at most.
	 */
	static const double LIMB_SCALE_MAX = 1.0;

	/**
	 * The initial maximum limb type repeats
	 */
	static const double LIMB_INITIAL_TYPE_REPEATS = 12;

	/**
	 * Initial limbs depth mean
	 */
	static const double LIMB_DEPTH_INITIAL_MEAN = 5;

	/**
	 * Initial segments depth variance
	 */
	static const double LIMB_DEPTH_INITIAL_VAR = 5;

	/**
	 * Initial total segments mean
	 */
	static const double LIMB_TOTAL_INITIAL_MEAN = 20;

	/**
	 * Initial total segments variance
	 */
	static const double LIMB_TOTAL_INITIAL_VAR = 10;

	/**
	 * The density of fat in kg per cubic meter
	 *  https://en.wikipedia.org/wiki/Muscle#cite_ref-Urbancheka_2001_6-0
	 */
	static const double FAT_DENSITY = 900; // kg/m^3

	/**
	 * The density of muscle in kg per cubic meter
	 * https://en.wikipedia.org/wiki/Muscle#cite_ref-Urbancheka_2001_6-0
	 */
	static const double MUSCLE_DENSITY = 1060; // kg/m^3

	/**
	 * For every 1 square centimeter of cross sectional area, muscle fibres can exert a maximum force of approximately 30–40 newtons (the weight of a 3–4 kg mass).
	 * http://sciencelearn.org.nz/Contexts/Sporting-Edge/Science-Ideas-and-Concepts/Muscle-performance
	 */
	static const double MUSCLE_STRENGTH_PER_CSA = 400000; // N/m^2

	/**
	 * The maximum allowable torque that can be exerted by a servo motor in its effort to
	 * reach its desired angle is computed as [BODY_MUSCLE_MAX_TORQUE_LINEAR_CONSTANT*(mass1 +mass2)+BODY_MUSCLE_MAX_TORQUE_SQUARE_CONSTANT * (mass1 + mass2)^2]
	 */
	static const double MUSCLE_MAX_TORQUE_LINEAR_CONSTANT = 8.0f * 10e2;

	/**
	 * The maximum allowable torque that can be exerted by a servo motor in its effort to
	 * reach its desired angle is computed as [BODY_MUSCLE_MAX_TORQUE_LINEAR_CONSTANT*(mass1 +mass2)+BODY_MUSCLE_MAX_TORQUE_SQUARE_CONSTANT * (mass1 + mass2)^2]
	 */
	static const double MUSCLE_MAX_TORQUE_SQUARE_CONSTANT = 0;

	/**
	 * The joints between body segments are set to break if they experience torques beyond
	 * a given threshold. The breaking threshold value for a given joint is computed as
	 * BODY_JOINT_MAX_TORQUE_CONSTANT*(mass1+ mass2) (2.0x10^6 in 3DVCE) where mass1 and mass2
	 * are the masses of the two limbs connected by the joint. This formula allows joints between
	 *  larger segments to sustain correspondingly larger torques.
	 */
	static const double JOINT_MAX_TORQUE_CONSTANT = 1;

	/**
	 * The length of an object between the parent joint and the child joint, 1 meaning its correct length. This is basically how much the creature is rayman.
	 */
	static const double LINK_LENGTH = 2;

	/**
	 * The minimum stiffness of the joint
	 */
	static const double JOINT_MIN_STIFFNESS = 0;

	/**
	 * The maximum stiffness of the joint
	 */
	static const double JOINT_MAX_STIFFNESS = 10;

	static const double JOINT_MIN_FREQUENCY = 0.1;

	static const double JOINT_MAX_FREQUENCY = 2;

	static const double JOINT_MIN_AMPLITUDE = 0;

	static const double JOINT_MAX_AMPLITUDE = 0.5;

	static const double JOINT_MIN_X_OFFSET = 0;

	static const double JOINT_MAX_X_OFFSET = 2 * M_PI;

	static const double JOINT_MIN_Y_OFFSET = 0;

	static const double JOINT_MAX_Y_OFFSET = 1;

	/**
	 * The minimum spring damping coefficient of the joint
	 */
	static const double JOINT_MIN_SPRING_COEFFICIENT = 0;

	/**
	 * The maximum spring damping coefficient of the joint
	 */
	static const double JOINT_MAX_SPRING_COEFFICIENT = 10;

	/**
	 * The smallest max strength of a joint motor
	 */
	static const double JOINT_MIN_FORCE = 1;

	/**
	 * The smallest max speed of a joint motor
	 */
	static const double JOINT_MIN_SPEED = 10;

	/**
	 * The highest max speed of a joint motor
	 */
	static const double JOINT_MAX_SPEED = 100;

	/**
	 * The initial branch number mean
	 */
	static const double BODY_BRANCH_INITIAL_MEAN = 6;

	/**
	 * The initial branch number variance
	 */
	static const double BODY_BRANCH_INITIAL_VAR = 3;
};

#endif /* CONFIGURATION_MORPHOLOGYCONFIGURATION_H_ */
