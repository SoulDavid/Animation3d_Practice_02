/**
* @file Physics_Component.hpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 06 de Junio de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que recoge el rigidbody de la entidad
**/
#pragma once

#include <memory>
#include <vector>
#include "Entity.hpp"
#include <btBulletDynamicsCommon.h>

namespace Engine
{
	class Entity;
	class Physics_Component
	{
	private:
		///Propiedades de los rigid_bodies
		std::vector< std::shared_ptr< btCollisionShape     > > collisionShapes;
		std::vector< std::shared_ptr< btDefaultMotionState > > motionStates;
		std::vector< std::shared_ptr< btRigidBody          > > rigidBodies;

	public:
		///Objeto que recoge el rigid_body
		std::shared_ptr<btRigidBody> rigid_body;

	public:
		//Dynamic cube
		Physics_Component(std::shared_ptr< btDiscreteDynamicsWorld >, btVector3, float, float, btVector3);
		//Dynamic Sphere
		Physics_Component(std::shared_ptr< btDiscreteDynamicsWorld >, float, float, float, btVector3);
	};
}


