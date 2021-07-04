/**
* @file Physics.cpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 06 de Junio de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que recoge el mundo dinámico y el update de todos los objetos.
**/

#include "Physics.hpp"

namespace Engine
{
    ///Constructor por defecto
	Physics::Physics() : collisionDispatcher(&collisionConfiguration)
	{
        //Creamos el mundo con sus propiedades
        std::shared_ptr< btDiscreteDynamicsWorld > given_dynamicsWorld
        (
            new btDiscreteDynamicsWorld
            (
                &collisionDispatcher,
                &overlappingPairCache,
                &constraintSolver,
                &collisionConfiguration
            )
        );
        //Le ponemos la gravedad
        given_dynamicsWorld->setGravity(btVector3(0, -9.8f, 0));
		dynamicsWorld = given_dynamicsWorld;
	} 
    
    ///Update de cada rigidbody
    void Physics::Update(Physics_Component* physic_component, Entity* entity, Node* node)
	{
        physic_component->rigid_body->getMotionState()->getWorldTransform(entity->transform_entity);
        entity->transform_entity.getOpenGLMatrix(glm::value_ptr(entity->graphics_transform_entity));
        node->set_transformation(entity->graphics_transform_entity);
	}
}
