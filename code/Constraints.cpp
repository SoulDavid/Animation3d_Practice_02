/**
* @file Constraints.cpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 06 de Junio de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que tiene el funcionamiento de los constraints
**/
#include "Constraints.hpp"

namespace Engine
{
	///Constructor
	//btHingeConstraint(btRigidBody& rbA, btRigidBody& rbB, const btTransform& rbAFrame, const btTransform& rbBFrame, bool useReferenceFrameA = false);
	Constraints::Constraints(std::shared_ptr<btRigidBody> RigidbodyA, std::shared_ptr<btRigidBody> RigidbodyB, Physics* DynamicWorld, btVector3 PivotA, btVector3 PivotB, btVector3 AxisA, btVector3 AxisB)
	{
		//Crea el constraint
		constraint = make_shared<btHingeConstraint>(*RigidbodyA, *RigidbodyB, PivotA, PivotB, AxisA, AxisB, false);
		//Lo añade al mundo
		DynamicWorld->dynamicsWorld->addConstraint(constraint.get());
	}
}