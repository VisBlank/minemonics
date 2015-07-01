#ifndef VIEW_OGRE3D_OGREMESHRAY_H_
#define VIEW_OGRE3D_OGREMESHRAY_H_

//# corresponding header
//# forward declarations
//# system headers
#include <stddef.h>

//## controller headers
//## model headers
//## view headers
#include <OgrePrerequisites.h>
#include <OgreQuaternion.h>

//# custom headers
//## base headers
//## configuration headers
//## controller headers
//## model headers
//## view headers
//## utils headers

/***************************************************************************//*!
 * @brief Ray Collision Detection
 * Usage: (Example with FPS view & cursor style (minecraft, cs, ...))
 * @code
 * //...
 * Ogre::SceneManager* sceneMgr = ...
 * //...
 * OgreRay ray(sceneMgr);
 * //...
 *
 * 	Ogre::Vector3 result;
 * 	if( ray.RaycastFromPoint(m_camera->getPosition(), Ogre::Vector3 direction = m_camera->getDirection(), result) ){
 *		printf("Your mouse is over the position %f,%f,%f (which is textured)\n", result.x, result.y, result.z);
 *	}else{
 *		printf("No mouse collision\n Are you looking the sky ?\n");
 * 	}
 * @endcode
 * @date 2015-04-16
 * @author Benjamin Ellenberger
 */
class OgreMeshRay {
private:
	Ogre::RaySceneQuery* m_raySceneQuery; //!< Ray query

public:
	OgreMeshRay(Ogre::SceneManager* sceneMgr);
	bool raycastFromPoint(const Ogre::Vector3& point,
			const Ogre::Vector3& normal, Ogre::Vector3& result,std::string entityName = "");

private:
	static void GetMeshInformation(const Ogre::MeshPtr mesh,
			size_t &vertex_count, Ogre::Vector3*& vertices, size_t& index_count,
			unsigned long*& indices, const Ogre::Vector3& position,
			const Ogre::Quaternion& orient, const Ogre::Vector3& scale);
	static void GetMeshInformation(const Ogre::ManualObject* manual,
			size_t& vertex_count, Ogre::Vector3*& vertices, size_t& index_count,
			unsigned long*& indices, const Ogre::Vector3& position,
			const Ogre::Quaternion& orient, const Ogre::Vector3& scale);
	static void GetMeshInformation(const Ogre::Entity* entity,
			size_t& vertex_count, Ogre::Vector3*& vertices, size_t& index_count,
			unsigned long*& indices, const Ogre::Vector3& position,
			const Ogre::Quaternion& orient, const Ogre::Vector3& scale);
};
#endif /* VIEW_OGRE3D_OGREMESHRAY_H_ */
