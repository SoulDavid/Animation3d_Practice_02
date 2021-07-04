/**
* @file Physics.hpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 06 de Junio de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que recoge el mundo dinámico y el update de todos los objetos.
**/

#pragma once
#include <btBulletDynamicsCommon.h>
#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <iterator>

#include "Entity.hpp"
#include "Physics_Component.hpp"
#include <Render_Node.hpp>

using namespace std;

namespace Engine
{
	class Entity;
	class Physics_Component;

	class Physics
	{ 
	private:
		// Collision configuration contains default setup for memory, collision setup.
		// Advanced users can create their own configuration.
		btDefaultCollisionConfiguration collisionConfiguration;

		// Use the default collision dispatcher. For parallel processing you can use a diffent dispatcher (see Extras/BulletMultiThreaded).
		btCollisionDispatcher collisionDispatcher;

		// btDbvtBroadphase is a good general purpose broadphase. You can also try out btAxis3Sweep.
		btDbvtBroadphase overlappingPairCache;

		// The default constraint solver. For parallel processing you can use a different solver (see Extras/BulletMultiThreaded).
		btSequentialImpulseConstraintSolver constraintSolver;

	public:
		// Create and configure the physiscs world:
		std::shared_ptr< btDiscreteDynamicsWorld > dynamicsWorld;
		

	public:
		//Constructor por defecto
		Physics();
		//Update de los objetos
		void Update(Physics_Component* physic_component, Entity* enitity, Node* node);
	};
}


