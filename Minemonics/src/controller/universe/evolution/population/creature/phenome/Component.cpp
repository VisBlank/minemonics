/*
 * Component.cpp
 *
 *  Created on: Mar 23, 2015
 *      Author: leviathan
 */

//# corresponding header
#include <controller/universe/evolution/population/creature/phenome/Component.hpp>

//# forward declarations
//# system headers
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

Component::Component() {
}

Component::~Component() {
}

void Component::initialize(ComponentModel::ComponentType componentType) {
	mComponentModel.initialize(componentType);
}
