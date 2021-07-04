/**
* @file Constraints.hpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 06 de Junio de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que tiene el funcionamiento de los constraints
**/

#pragma once
#include <memory>
#include <vector>
#include "Physics.hpp"
#include <btBulletDynamicsCommon.h>


namespace Engine
{
	class Constraints
	{
	private:
		//Variable que recoge el objeto del constraint
		std::shared_ptr<btHingeConstraint> constraint;

	public:
		///Constructor de los constraints
		Constraints(std::shared_ptr<btRigidBody>, std::shared_ptr<btRigidBody>, Physics*, btVector3, btVector3, btVector3, btVector3);
		//Destructor 
		~Constraints();

	};
}


