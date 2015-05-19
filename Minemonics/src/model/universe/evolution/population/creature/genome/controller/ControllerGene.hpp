#ifndef MODEL_UNIVERSE_EVOLUTION_POPULATION_CREATURE_GENOME_CONTROLLER_CONTROLLERGENE_HPP_
#define MODEL_UNIVERSE_EVOLUTION_POPULATION_CREATURE_GENOME_CONTROLLER_CONTROLLERGENE_HPP_

//# forward declarations
//# system headers
//## controller headers
//## model headers
// include headers that implement a archive in xml format
#include <boost/archive/tmpdir.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/serialization/version.hpp>

//## view headers
//# custom headers
//## base headers
//## configuration headers
//## controller headers
//## model headers
//## view headers
//## utils headers

/**
 * @brief		The controller gene is the base class for all genes encoding different controllers.
 * @details		Details
 * @date		2015-03-09
 * @author		Benjamin Ellenberger
 */
class ControllerGene {
public:
	ControllerGene();
	virtual ~ControllerGene();

	virtual void initialize() = 0;

	virtual ControllerGene* clone() = 0;

	bool equals (const ControllerGene& controllerGene) const;

	enum ControllerGeneType {
		SineControllerGene,
		GenericControllerGene
	};

	/**
	 * Give access to boost serialization
	 */
	friend class boost::serialization::access;

	/**
	 * Serializes the controller gene to a string.
	 * @param os The ostream.
	 * @param controllerGene The controller gene we want to serialize.
	 * @return A string containing all information about the controller gene.
	 */
	friend std::ostream & operator<<(std::ostream &os, const ControllerGene &controllerGene) {
		return os << "ControllerGene:" << controllerGene.mControllerGeneType;

	}

	ControllerGeneType getControllerGeneType() const {
		return mControllerGeneType;
	}

	void setControllerGeneType(ControllerGeneType controllerGeneType) {
		mControllerGeneType = controllerGeneType;
	}

	/**
	 * Serializes the controller gene to an xml file.
	 * @param ar The archive.
	 * @param The file version.
	 */
	template<class Archive>
	void serialize(Archive & ar, const unsigned int /* file_version */) {
		ar & BOOST_SERIALIZATION_NVP(mControllerGeneType);
	}

protected:
	ControllerGeneType mControllerGeneType;
};
BOOST_CLASS_VERSION(ControllerGene, 1)
BOOST_SERIALIZATION_ASSUME_ABSTRACT(ControllerGene)

#endif /* MODEL_UNIVERSE_EVOLUTION_POPULATION_CREATURE_GENOME_CONTROLLER_CONTROLLERGENE_HPP_ */
