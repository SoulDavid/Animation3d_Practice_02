/**
* @file Physics_Component.cpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 06 de Junio de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que recoge el rigidbody de la entidad
**/
#include "Physics_Component.hpp"

namespace Engine
{
    //Dynamic cube
	Physics_Component::Physics_Component(std::shared_ptr< btDiscreteDynamicsWorld > dynamicsWorld, btVector3 size, float given_mass, float restitution, btVector3 pos)
	{
        ///Customizar el rigid_body
        rigid_body;
		{
            std::shared_ptr< btCollisionShape > shape(new btBoxShape(size));

            // Create Dynamic Objects.

            btTransform transform;
            transform.setIdentity();
            transform.setOrigin(pos);

            //Masa del rigid_body y se calcula la localInertia
            btScalar  mass = given_mass;
            btVector3 localInertia(0, 0, 0);

            if (mass != 0.f)
                shape->calculateLocalInertia(mass, localInertia);

            // Using motionstate is recommended, it provides interpolation capabilities, and only synchronizes 'active' objects

            std::shared_ptr< btDefaultMotionState >       state(new btDefaultMotionState(transform));
            btRigidBody::btRigidBodyConstructionInfo info(mass, state.get(), shape.get(), localInertia);

            rigid_body.reset(new btRigidBody(info));

            rigid_body->setRestitution(restitution);

            dynamicsWorld->addRigidBody(rigid_body.get());

            // Save the smart pointers for automatic cleanup.

            rigidBodies.push_back(rigid_body);
            motionStates.push_back(state);
            collisionShapes.push_back(shape);
		}
	}

    //Dynamic Sphere
    Physics_Component::Physics_Component(std::shared_ptr< btDiscreteDynamicsWorld > dynamicsWorld, float radius, float given_mass, float restitution, btVector3 pos)
    {
        rigid_body;
        {
            std::shared_ptr< btCollisionShape > shape(new btSphereShape(btScalar(radius)));

            // Create Dynamic Objects.

            btTransform transform;
            transform.setIdentity();
            transform.setOrigin(pos);

            //Masa del rigid_body y se calcula la localInertia
            btScalar  mass = given_mass;
            btVector3 localInertia(0, 0, 0);

            if(mass != 0.f)
                shape->calculateLocalInertia(mass, localInertia);

            // Using motionstate is recommended, it provides interpolation capabilities, and only synchronizes 'active' objects

            std::shared_ptr< btDefaultMotionState >       state(new btDefaultMotionState(transform));
            btRigidBody::btRigidBodyConstructionInfo info(mass, state.get(), shape.get(), localInertia);

            rigid_body.reset(new btRigidBody(info));

            rigid_body->setRestitution(restitution);

            dynamicsWorld->addRigidBody(rigid_body.get());

            // Save the smart pointers for automatic cleanup.

            rigidBodies.push_back(rigid_body);
            motionStates.push_back(state);
            collisionShapes.push_back(shape);
        }
    }
}
