/*
 * LimbO3D.cpp
 *
 *  Created on: Dec 19, 2014
 *      Author: leviathan
 */

//# corresponding header
#include <boost/lexical_cast.hpp>
#include <controller/universe/evolution/population/creature/phenome/morphology/Limb.hpp>
#include <OgreSceneNode.h>
#include <SimulationManager.hpp>
#include <view/picking/OgreMeshRay.hpp>
#include <view/universe/evolution/population/creature/phenome/morphology/limb/LimbO3D.hpp>
#include <view/visualization/procedural/ProceduralCapsuleGenerator.h>

//## configuration headers
//## controller headers

//## utils headers

#ifndef NULL
#define NULL 0
#endif

LimbO3D::LimbO3D() :
		mLimbEntity(NULL), mLimbEntityNode(NULL), mSimulationManager(NULL) {

}

LimbO3D::~LimbO3D() {
	delete mLimbEntityNode;
	delete mLimbEntity;
}

void LimbO3D::initialize(SimulationManager* simulationManager,
		LimbModel::PrimitiveType type, Ogre::Vector3 scale,
		Ogre::ColourValue color) {
	mSimulationManager = simulationManager;

	Ogre::String name = boost::lexical_cast<std::string>(this) + "/" + "Limb";
	Ogre::String materialName = boost::lexical_cast<std::string>(this) + "/"
			+ "Limb";

	// add the true as the last parameter to make it a manual material
	Ogre::MaterialPtr material = Ogre::MaterialManager::getSingleton().create(
			materialName,
			Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, false);

	Ogre::Pass *pass = material->getTechnique(0)->getPass(0);
	pass->setLightingEnabled(false);
	pass->setDiffuse(color);
	pass->setEmissive(color);
	pass->setDepthCheckEnabled(true);
	pass->setDepthWriteEnabled(false);
	pass->setSceneBlending(Ogre::SBT_TRANSPARENT_ALPHA);

	Ogre::TextureUnitState *tex = pass->createTextureUnitState("MyCustomState",
			0);
	tex->setTextureName("honeycomb.png");
	tex->setTextureFiltering(Ogre::TFO_ANISOTROPIC);
	tex->setTextureAnisotropy(8);

	switch (type) {
	case LimbModel::BLOCK:

		tex->setTextureScale(4, 4);
		material->load();
		mLimbEntity = mSimulationManager->getSceneManager()->createEntity(
				Ogre::SceneManager::PT_CUBE);
		mLimbEntity->setMaterialName(materialName);
		mLimbEntityNode =
				mSimulationManager->getSceneManager()->createSceneNode();
		mLimbEntityNode->attachObject(mLimbEntity);

		mLimbEntityNode->scale(
				scale.x * PhysicsConfiguration::BULLET_OGRE_BOX_SCALING_FACTOR,
				scale.y * PhysicsConfiguration::BULLET_OGRE_BOX_SCALING_FACTOR,
				scale.z * PhysicsConfiguration::BULLET_OGRE_BOX_SCALING_FACTOR);
		break;
	case LimbModel::CAPSULE:

		material->load();
		//because we can only scale bullet capsule that way, we do not scale this object differently
		Procedural::CapsuleGenerator().setPosition(0, 0, 0).setRadius(
				0.5f * scale.z).setHeight(scale.y).realizeMesh(name);
		mLimbEntity = mSimulationManager->getSceneManager()->createEntity(name);
		mLimbEntity->setMaterialName(materialName);
		mLimbEntityNode =
				mSimulationManager->getSceneManager()->createSceneNode();
		mLimbEntityNode->attachObject(mLimbEntity);
		break;
	}
}

void LimbO3D::update() {
	mLimbEntityNode->setPosition(mPosition);
	mLimbEntityNode->setOrientation(mOrientation);
}

void LimbO3D::addToWorld() {
	if (!isInWorld()) {
		mSimulationManager->getSceneManager()->getRootSceneNode()->addChild(
				mLimbEntityNode);
		setInWorld(true);
	}
}

void LimbO3D::removeFromWorld() {
	if (isInWorld()) {
		mSimulationManager->getSceneManager()->getRootSceneNode()->removeChild(
				mLimbEntityNode);
		setInWorld(false);
	}
}

Ogre::Vector3 LimbO3D::getIntersection(Ogre::Vector3 origin,
		Ogre::Vector3 direction) {
	Ogre::Ray ray;
	ray.setOrigin(origin);
	ray.setDirection(direction);

	Ogre::RaySceneQuery* mRayScnQuery =
			mSimulationManager->getSceneManager()->createRayQuery(Ogre::Ray());
	mRayScnQuery->setSortByDistance(true);
	mRayScnQuery->setRay(ray);

	Ogre::RaySceneQueryResult& result = mRayScnQuery->execute();
	Ogre::RaySceneQueryResult::iterator it = result.begin();

	//Ogre::SceneNode* curObject;
	double distance = 0;
	for (; it != result.end(); it++) {
		std::cout << "Collision name:" << it->movable->getName() << std::endl;
		if (it->movable->getName() == mLimbEntity->getName()) {
			distance = it->distance;
			std::cout << "Distance from center" << distance << std::endl;
			//curObject = it->movable->getParentSceneNode();
		}
	}
	mSimulationManager->getSceneManager()->destroyQuery(mRayScnQuery);

	return origin + direction * distance / direction.length();
}

Ogre::Vector3 LimbO3D::getLocalIntersection(Ogre::Vector3 origin,
		Ogre::Vector3 direction) {
	Ogre::Ray ray;
	ray.setOrigin(origin);
	ray.setDirection(direction);

	Ogre::RaySceneQuery* mRayScnQuery =
			mSimulationManager->getSceneManager()->createRayQuery(Ogre::Ray());
	mRayScnQuery->setSortByDistance(true);
	mRayScnQuery->setRay(ray);

	Ogre::RaySceneQueryResult& result = mRayScnQuery->execute();
	Ogre::RaySceneQueryResult::iterator it = result.begin();

	//Ogre::SceneNode* curObject;
	double distance = 0;
	for (; it != result.end(); it++) {
		if (it->movable->getName() == mLimbEntity->getName()) {
			distance = it->distance;
			//curObject = it->movable->getParentSceneNode();
		}
	}
	mSimulationManager->getSceneManager()->destroyQuery(mRayScnQuery);

	return direction * distance / direction.length();
}

Ogre::Vector3 LimbO3D::getLocalPreciseIntersection(Ogre::Vector3 origin,
		Ogre::Vector3 direction) {
	OgreMeshRay ray(mSimulationManager->getSceneManager());
	Ogre::Vector3 result;
	ray.raycastFromPoint(origin, direction, result, mLimbEntity->getName());

	return result;
}
