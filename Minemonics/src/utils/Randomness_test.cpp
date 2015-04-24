/*
 * Randomness_test.cpp
 *
 *  Created on: Mar 13, 2015
 *      Author: leviathan
 */

//# corresponding header
#include "Randomness.h"

//# forward declarations
#include <math.h>

//# system headers
#include <gtest/gtest.h>

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

class RandomnessTest: public ::testing::Test {
protected:
	virtual void SetUp() {
		randomness = new Randomness();
	}

	virtual void TearDown() {
		delete randomness;
		randomness = 0;
	}
	Randomness* randomness;
};

TEST_F(RandomnessTest,distributionsStayWithinBounds) {
	for (int i = 0; i < 100; i++) {
		//biased log distribution
		double biasedLogNumber = randomness->nextBiasedLog(3,7);
		std::cout << biasedLogNumber << "\t";
		ASSERT_TRUE(3 <= biasedLogNumber);
		ASSERT_TRUE(biasedLogNumber <= 7);

		// uniformly distributed double
		double uniformDouble = randomness->nextDouble(10,100);
		std::cout << uniformDouble << "\t";
		ASSERT_TRUE(10 <= uniformDouble);
		ASSERT_TRUE(uniformDouble <= 100);

		// positive integer
		double positiveInt = randomness->nextPosInt(10,100);
		std::cout << positiveInt << "\t";
		ASSERT_TRUE(10 <= positiveInt);
		ASSERT_TRUE(positiveInt <= 100);
		ASSERT_TRUE(positiveInt == floor(positiveInt));

		// normally distributed boolean
		double normalBoolean = randomness->nextNormalBoolean(0.8f,3);
		std::cout << normalBoolean << "\t";
		ASSERT_TRUE(0 <= normalBoolean);
		ASSERT_TRUE(normalBoolean <= 1);

		// normally distributed double
		double normalDouble = randomness->nextNormalDouble(404.404f,30);
		std::cout << normalDouble << "\t";

		// normally distributed integer
		double normalInt = randomness->nextNormalInt(404.404f,30);
		std::cout << normalInt << std::endl;
		ASSERT_TRUE(340 <= normalInt);
		ASSERT_TRUE(normalInt <= 470);
		ASSERT_TRUE(normalInt == floor(normalInt));
	}
}
