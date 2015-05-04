#ifndef CONTROLLER_EVOLUTION_POPULATION_CREATURE_CREATURE_HPP_
#define CONTROLLER_EVOLUTION_POPULATION_CREATURE_CREATURE_HPP_

//# corresponding header
//# forward declarations
class SimulationManager;

//# system headers
//## controller headers
//## model headers
//## view headers
//# custom headers
//## base headers
//## configuration headers
//## controller headers
#include <controller/evolution/population/creature/phenome/Phenome.hpp>

//## model headers
#include <model/evolution/population/creature/CreatureModel.hpp>

//## view headers
//## utils headers

/**
 * @brief		Brief
 * @details		Details
 * @date		2015-04-07
 * @author		Benjamin Ellenberger
 */
class Creature {
public:
	Creature();
	virtual ~Creature();

	void initialize(SimulationManager* simulationManager,
			Ogre::Vector3 position, double bushiness);

	void performEmbryogenesis();

	void update();

	void addToWorld();

	void removeFromWorld();

	/**
	 * The model of the creature
	 */
	CreatureModel* mCreature;

	/**
	 * The phenotype of the creature.
	 */
	Phenome* mPhenotype;
};

#endif /* CONTROLLER_EVOLUTION_POPULATION_CREATURE_CREATURE_HPP_ */