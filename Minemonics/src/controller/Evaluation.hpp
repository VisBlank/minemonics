#ifndef CONTROLLER_EVALUATION_HPP_
#define CONTROLLER_EVALUATION_HPP_

//# corresponding headers
//# forward declarations
//# system headers
#include <vector>

//## controller headers
//## model headers
//## view headers
//# custom headers
//## base headers
//## configuration headers
//## controller headers
#include <controller/universe/evolution/population/Population.hpp>

//## model headers
#include <model/universe/EvaluationModel.hpp>

//## view headers
//## utils headers

/**
 * @brief		An evaluation holds the creatures and the planet that is evaluated by the simulator, possibly in parallel with other planets.
 * @details		 Details
 * @date		2015-06-01
 * @author		Benjamin Ellenberger
 */
class Evaluation {
public:
	Evaluation();
	virtual ~Evaluation();

	/**
	 * Initialize the evaluation.
	 * @param planet The planet on which the evaluation takes place.
	 * @param evaluationTime The evaluation time in this evaluation
	 */
	void initialize(Planet* planet,double evaluationTime);

	/**
	 * Add a population to the evaluation
	 * @param population The population to be added to the evaluation.
	 */
	void addPopulation(Population* population);

	/**
	 * Setup the evaluation.
	 */
	void setup();

	/**
	 * Process the evaluated individuals.
	 */
	void process();

	/**
	 * Tear the evaluation down.
	 */
	void teardown();

	/**
	 * Update the evaluation.
	 * @param timeSinceLastFrame The time since the last graphics frame.
	 */
	void update(double timeSinceLastFrame);

	// Facade accessor methods
	bool isEvaluating() const {
		return mEvaluationModel.isEvaluating();
	}

	bool isTornDown() const {
		return mEvaluationModel.isTornDown();
	}

private:
	EvaluationModel mEvaluationModel;

	Planet* mPlanet;

	std::vector<Population*> mPopulations;
};

#endif /* CONTROLLER_EVALUATION_HPP_ */
