/*
 * PlaneBt.h
 *
 *  Created on: Mar 17, 2015
 *      Author: leviathan
 */

#ifndef MODEL_ENVIRONMENT_PLANEBT_H_
#define MODEL_ENVIRONMENT_PLANEBT_H_

//# corresponding header
#include <btBulletDynamicsCommon.h>
#include <model/universe/environments/bullet/EnvironmentBt.hpp>

//## view headers
//# custom headers
//## base headers
//## configuration headers
//## controller headers
//## model headers
//## view headers
//## utils headers

/**
 * @brief		Brief
 * @details		Details
 * @date		2015-04-27
 * @author		Benjamin Ellenberger
 */
class PlaneBt : public EnvironmentBt {
public:
	PlaneBt();
	virtual ~PlaneBt();

	void initialize();

	virtual void update();

	btRigidBody*& getBody() {
		return mGroundBody;
	}
};

#endif /* MODEL_ENVIRONMENT_PLANEBT_H_ */
