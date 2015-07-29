//# corresponding header
#include <model/universe/environments/physics/PhysicsController.hpp>
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

PhysicsController::PhysicsController() :
		mBroadphase(NULL), mCollisionConfiguration(NULL), mDispatcher(NULL), mDynamicsWorld(
		NULL), mPhysicsPaused(false), mPhysicsStepped(false), mSolver(
		NULL), mSimulationSpeed(
				pow(2, PhysicsConfiguration::SIMULATION_SPEED_01)) {

}

PhysicsController::~PhysicsController() {

}

void PhysicsController::initBulletPhysics() {

	mCollisionConfiguration = new btDefaultCollisionConfiguration(); //collision configuration contains default setup for memory, collision setup
	mDispatcher = new btCollisionDispatcher(mCollisionConfiguration); //use the default collision dispatcher
	mBroadphase = new btDbvtBroadphase();
	mSolver = new btSequentialImpulseConstraintSolver; //the default constraint solver
	mDynamicsWorld = new btDiscreteDynamicsWorld(mDispatcher, mBroadphase,
			mSolver, mCollisionConfiguration);
	mDynamicsWorld->setGravity(
			btVector3(0,
					-PhysicsConfiguration::EARTH_GRAVITY
							* PhysicsConfiguration::REALITY_BULLET_GRAVITY_SCALING_FACTOR,
					0));
}

void PhysicsController::exitBulletPhysics() {
	//cleanup in the reverse order of creation/initialization

	for (int i = mDynamicsWorld->getNumCollisionObjects() - 1; i >= 0; i--) //remove the rigidbodies from the dynamics world and delete them
			{
		btCollisionObject* obj = mDynamicsWorld->getCollisionObjectArray()[i];
		btRigidBody* body = btRigidBody::upcast(obj);
		if (body && body->getMotionState())
			delete body->getMotionState();

		mDynamicsWorld->removeCollisionObject(obj);
		delete obj;
	}

	for (int j = 0; j < mCollisionShapes.size(); j++) //delete collision shapes
			{
		btCollisionShape* shape = mCollisionShapes[j];
		delete shape;
	}

	mCollisionShapes.clear();
	delete mDynamicsWorld;
	mDynamicsWorld = 0;
	delete mSolver;
	mSolver = 0;
	delete mBroadphase;
	mBroadphase = 0;
	delete mDispatcher;
	mDispatcher = 0;
	delete mCollisionConfiguration;
	mCollisionConfiguration = 0;
}

void PhysicsController::stepBulletPhysics(const double timeStep) {
	//step the simulation
	if (mDynamicsWorld && (!mPhysicsPaused || mPhysicsStepped)) {

		//calculate the number of substeps the simulator needs to take
		int subSteps =
				PhysicsConfiguration::SIMULATOR_SECURITY_MARGIN
						+ ceil(
								pow(2,
										PhysicsConfiguration::SIMULATION_SPEEDS[mSimulationSpeed])
										* timeStep
										/ PhysicsConfiguration::SIMULATOR_PHYSICS_FIXED_STEP_SIZE);
		if (timeStep) {
			mDynamicsWorld->stepSimulation(
					pow(2,
							PhysicsConfiguration::SIMULATION_SPEEDS[mSimulationSpeed])
							* timeStep, subSteps,
					PhysicsConfiguration::SIMULATOR_PHYSICS_FIXED_STEP_SIZE);
		}

		//if step trigger is pressed, we pause the simulation and it steps forward every time we press the step trigger
		if (mPhysicsStepped) {
			mPhysicsStepped = false;
			mPhysicsPaused = true;
		}
	}
}

void PhysicsController::addBody(btRigidBody* const body) {
	mCollisionShapes.push_back(body->getCollisionShape());
	mDynamicsWorld->addRigidBody(body); //add the body to the dynamics world
}

void PhysicsController::removeBody(btRigidBody* body) {
	mCollisionShapes.remove(body->getCollisionShape());
	mDynamicsWorld->removeRigidBody(body); //remove the body to the dynamics world
}
