#ifndef CONTROLLER_UNIVERSE_EVOLUTION_POPULATION_CREATURE_CREATURE_HPP_
#define CONTROLLER_UNIVERSE_EVOLUTION_POPULATION_CREATURE_CREATURE_HPP_

//# corresponding header
//# forward declarations
class SimulationManager;
class Population;

//# system headers
//## controller headers
//## model headers
//## view headers
//# custom headers
//## base headers
//## configuration headers
//## controller headers
#include <controller/universe/evolution/population/creature/phenome/Phenome.hpp>

//## model headers
#include <model/universe/evolution/population/PopulationModel.hpp>
#include <model/universe/evolution/population/creature/CreatureModel.hpp>

//## view headers
//## utils headers

/**
 * @brief		The creature controller synchronizes the model with the view.
 * @details		Details
 * @date		2015-04-07
 * @author		Benjamin Ellenberger
 */
class Creature {
public:
	Creature();
	virtual ~Creature();

	void initialize(SimulationManager* simulationManager,Population* population,
			Ogre::Vector3 position, double branchiness);

	void performEmbryogenesis();

	void update();

	void addToWorld();

	void removeFromWorld();


	//Facade
	void setPosition(Ogre::Vector3 position){
		mCreatureModel->setPosition(position);
	}

	PlanetModel* getPlanet(){
		return mCreatureModel->getPopulationModel()->getPlanetModel();
	}

	void setPlanet(PlanetModel* planetModel)
	{
		mCreatureModel->getPopulationModel()->setPlanetModel(planetModel);
	}

	bool isDeveloped()
	{
		return mCreatureModel->isDeveloped();
	}

	/**
	 * The model of the creature
	 */
	CreatureModel* mCreatureModel;

	/**
	 * The phenotype of the creature.
	 */
	Phenome* mPhenotype;
};

#endif /* CONTROLLER_UNIVERSE_EVOLUTION_POPULATION_CREATURE_CREATURE_HPP_ */
