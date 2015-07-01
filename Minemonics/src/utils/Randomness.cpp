//# corresponding header
//## controller headers
//## model headers
#include <boost/random/uniform_real_distribution.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/math/special_functions/round.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

//## view headers
//# custom headers
//## base headers
//## configuration headers
//## controller headers
//## model headers
//## view headers
//## utils headers
#include <utils/Randomness.hpp>

Randomness::Randomness() {
	boost::posix_time::ptime time_t_epoch(boost::gregorian::date(1970, 1, 1));
	boost::posix_time::ptime now =
			boost::posix_time::microsec_clock::local_time();
	boost::posix_time::time_duration diff = now - time_t_epoch;

	rng.seed(diff.total_milliseconds());
}

Randomness::~Randomness() {

}

/**
 * Get a uniformly distributed random double which is limited by a lower and an upper limit.
 *
 * @param lowerLimit The lower limit we want to draw from.
 * @param upperLimit The upper limit we want to draw from.
 * @return A random double which is limited by a lower and an upper limit.
 */
double Randomness::nextUnifDouble(double lowerLimit, double upperLimit) {
	boost::random::uniform_real_distribution<> unifDoubleDistribution(
			lowerLimit, upperLimit);

	return unifDoubleDistribution(rng);
}
/**
 * Get a non-negative uniformly distributed random integer number to draw random array elements.
 * @param lowerLimit The lower limit we want to draw from.
 * @param upperLimit The upper limit we want to draw from.
 * @return A non-negative integer number.
 */
int Randomness::nextUnifPosInt(int lowerLimit, int upperLimit) {
	if (upperLimit <= 0) {
		return 0;
	}

	//create a uniform integer distribution
	boost::random::uniform_int_distribution<> unifIntDistribution(lowerLimit,
			upperLimit);

	//draw from it via the mersenne twister

	return unifIntDistribution(rng);
}
/**
 * Is a function which generates two values,
 1O^m and 10^n, both between 10^lowerLimit and 10^upperLimit with exponents m and n chosen uniformly at random from the
 range [10^lowerLimit..10^upperLimit],and returning whichever of the two values is closer to upperLimit.
 * @param lowerLimit The lower limit we want to draw from.
 * @param upperLimit The upper limit we want to draw from.
 * @return The double which is nearer to
 */
double Randomness::nextBiasedLogDouble(double lowerLimit, double upperLimit) {
	boost::random::uniform_real_distribution<> unifDoubleDistribution(
			pow(10, lowerLimit), pow(10, upperLimit));

	//draw m and n

	double tenpowm = unifDoubleDistribution(rng);
	double tenpown = unifDoubleDistribution(rng);

	//return m or n whichever is higher
	return (tenpowm > tenpown) ? log10(tenpowm) : log10(tenpown);
}

bool Randomness::nextUnifBoolean() {
	//create a uniform integer distribution
	boost::random::uniform_int_distribution<> unifIntDistribution(0, 1);

	// return true if 1 else false

	return (unifIntDistribution(rng)) ? true : false;
}

int Randomness::nextNormalInt(double mean, double variance, double limit) {
	//create a uniform integer distribution
	boost::random::normal_distribution<> normalIntDistribution(mean,
			(variance));

	double number = normalIntDistribution(rng);
	int integer = round(number);

	if (limit > 0) {
		//99.9% lie in between mean +- variance*2.0f
		if (integer > mean + variance * limit) {
			integer = mean + variance * limit;
		} else if (integer < mean - variance * limit) {
			integer = mean - variance * limit;
		}
	}
	return integer;
}

double Randomness::nextNormalDouble(double mean, double variance,
		double limit) {
	//create a uniform integer distribution
	boost::random::normal_distribution<> normalDoubleDistribution(mean,
			variance);

	double number = normalDoubleDistribution(rng);

	if (limit > 0) {
		//99.9% lie in between mean +- variance*2.0f
		if (number > mean + variance * limit) {
			number = mean + variance * limit;
		} else if (number < mean - variance * limit) {
			number = mean - variance * limit;
		}
	}

	return number;
}

bool Randomness::nextNormalBoolean(double mean, double variance) {
	//create a uniform integer distribution
	boost::random::normal_distribution<> normalBooleanDistribution(mean,
			variance);

	double number = normalBooleanDistribution(rng);
	bool result = false;
	if (number > 1) {
		result = true;
	} else if (number < 0) {
		result = false;
	} else {
		result = ((int) round(number)) ? true : false;
	}

	return result;
}
