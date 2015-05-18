#ifndef MODEL_UNIVERSE_EVOLUTION_EVOLUTIONMODEL_HPP_
#define MODEL_UNIVERSE_EVOLUTION_EVOLUTIONMODEL_HPP_

//# corresponding header
//# forward declarations
//# system headers
#include <vector>

//## controller headers
//## model headers
#include <model/universe/evolution/Reaper.hpp>
#include <model/universe/evolution/population/PopulationModel.hpp>

//## view headers
//## utils headers

/**
 * @brief		The model of the evolution holds information about the evolution.
 * @details		Details
 * @date		2015-03-08
 * @author		Benjamin Ellenberger
 */
class EvolutionModel {
public:

	// Evolution states
		enum EvolutionState {
			VARIATION, EVALUATION, PROCESSING,REAP_AND_SOW
		};

		/**
		 * The type evaluation
		 */
		enum EvaluationType {
			INDIVIDUAL_EVALUATION /**< Every individual gets separately evaluated.*/,
			N_TOURNAMENT_EVALUATION /**< Individual get evaluated in groups of n (Individuals Tournament).*/,
			POPULATION_EVALUATION /**< Each population gets evaluated as a whole.*/,
			N_POPULATION_EVALUATION /**< A group of n individuals from each population get evaluated.*/,
			N_POPULATIONS_EVALUATION /**< N populations are evaluated together (Populations Tournament).*/,
			POPULATIONS_EVALUATION/**< All populations are evaluated together.*/
		};

	EvolutionModel();
	~EvolutionModel();

	void initialize(double evaluationTime);

	void addNewPopulation(PopulationModel* populationModel);

	bool proceed();

	bool evaluate();

	bool process();

	bool selectAndReap();

	bool variate();

	//accessor methods
	const Reaper& getReaper() const {
		return mReaper;
	}

	EvolutionState getState() const {
		return mState;
	}

	EvaluationType getType() const {
		return mType;
	}

	std::vector<PopulationModel*>& getPopulationModels() {
		return mPopulationModels;
	}

	double getEvaluationTime() const {
		return mEvaluationTime;
	}

private:
	/**
	 * The vector of populations that are evaluated.
	 */
	std::vector<PopulationModel*> mPopulationModels;

	/**
	 * The currently evaluated population.
	 */
	PopulationModel* mCurrentPopulation;

	/**
	 * Amount of populations in this evolution.
	 */
	int mPopulationQty;

	/**
	 * The reaper of this evolution model.
	 */
	Reaper mReaper;

	/**
	 * The state this evolution is in.
	 */
	EvolutionState mState;

	/**
	 * The type of evolution model.
	 */
	EvaluationType mType;

	/**
	 * Evaluation time
	 */
	double mEvaluationTime;
};

#endif /* MODEL_UNIVERSE_EVOLUTION_EVOLUTIONMODEL_HPP_ */
