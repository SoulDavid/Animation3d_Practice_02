/**
* @file Scene.hpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 06 de julio de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que controla el comportamiento de la escena
**/

#pragma once
#include <memory>
#include <vector>
#include <iostream>
#include <math.h>
#include <cmath>
#include <list>

#include <Light.hpp>
#include <Cube.hpp>
#include <Model.hpp>
#include <OpenGL.hpp>
#include <Model_Obj.hpp>
#include <Render_Node.hpp>
#include "TaskRenderer.hpp"
#include "Entity.hpp"
#include "Physics.hpp"
#include "Physics_Component.hpp"
#include "Constraints.hpp"

#include <SFML/Window.hpp>
#include <btBulletDynamicsCommon.h>

using namespace std;
using namespace glt;

namespace Engine
{
	class Scene
	{
    private:
        ///Referencia al task_renderer
        TaskRenderer* tr;
        ///Referencia al pysics_task
        Physics* tp;

        //Entidades de las ruedas
        Entity * wheel_01;
        Entity * wheel_02;
        Entity * wheel_03;
        Entity * wheel_04;

        //Nodos de las ruedas
        Node* wheel_01_model;
        Node* wheel_02_model;
        Node* wheel_03_model;
        Node* wheel_04_model;

        //Rigid_bodies de las ruedas
        Physics_Component* p_component_wheel_01;
        Physics_Component* p_component_wheel_02;
        Physics_Component* p_component_wheel_03;
        Physics_Component* p_component_wheel_04;

        //Entidad de la luz
        Entity* light;
        //Entidad de la camara
        Entity* camera;

        //Entidad del cubo del tanque
        Entity* box_tank;
        //Entidad del bloque de la izquierda
        Entity* box_test_02;
        //Nodo del cubo del tanque
        Node* box_tank_model;
        //Nodo del bloque de la izquierad
        Node* box_test_02_model;
        //Rigid_body del cubo del tanque
        Physics_Component* pc_box_tank;
        //Rigid_body del cubo de la izquierda
        Physics_Component* pc_terrain_left;

        //Entidad del cubo central
        Entity* terrain_center;
        //Nodo del cubo central
        Node* terrain_center_model;
        //Rigid_body del cubo central
        Physics_Component* pc_terrain_center;

        //Entidad del cubo derecho
        Entity* terrain_right;
        //Nodo del cubo derecho
        Node* terrain_right_model;
        //Rigid_body del cubo derecho
        Physics_Component* pc_terrain_right;

        //Entidad de la pared
        Entity* FarWall;
        //Nodo de la pared
        Node* FarWall_model;
        //Rigid_body de la pared
        Physics_Component* pc_FarWall;

        //Entidad de la llave
        Entity* Key;
        //Nodo de la llave
        Node* Key_model;
        //Rigid_body de la llave
        Physics_Component* pc_Key;

        //Entidad de la plataforma
        Entity* platform;
        //Nodo de la plataforma
        Node* platform_model;
        //Rigid_body de la plataforma
        Physics_Component* pc_platform;

        ///Los constraints
        Constraints* constraints_Wheel01_carBox;
        Constraints* constraints_Wheel02_carBox;
        Constraints* constraints_Wheel03_carBox;
        Constraints* constraints_Wheel04_carBox;
        Constraints* constraints_Cañon;

        //Entidad de la bala
        Entity* bullet;
        //Nodo de la bala
        Node* bullet_model;
        //Rigid_body de la bala
        Physics_Component* pc_bullet;

        //Entidad de un bolo
        Entity* bolo_01;
        //Nodo de un bolo
        Node* bolo_01_model;
        //Rigid_body de un bolo
        Physics_Component* pc_bolo_01;

        //Entidad de un bolo
        Entity* bolo_02;
        //Nodo de un bolo
        Node* bolo_02_model;
        //Rigid_body de un bolo
        Physics_Component* pc_bolo_02;

        //Entidad de un bolo
        Entity* bolo_03;
        //Nodo de un bolo
        Node* bolo_03_model;
        //Rigid_body de un bolo
        Physics_Component* pc_bolo_03;

        //Entidad de un bolo
        Entity* bolo_04;
        //Nodo de un bolo
        Node* bolo_04_model;
        //Rigid_body de un bolo
        Physics_Component* pc_bolo_04;

        //Entidad del cañon
        Entity* chasis;
        //Nodo del cañon
        Node* chasis_model;
        //Rigid_body del cañon
        Physics_Component* pc_chasis;

        //lista de entidades
        list<Entity*> _entities;
        //lista de rigid_bodies
        list<Physics_Component*> _physics_components;
        //Lista de nodos
        list<Node*> _nodes;

        bool running = true;
        //Booleano que indica cuando el tanque esta encima de la plataforma
        bool platform_boolean = false;
        //Booleano que indica cuando se ha cogido una llave
        bool isDoorOpen = false;
        //Booleano que indica cuando el jugador puede acceder a los controles
        bool canPlay = false;
        int  frame = 0;

        //Fuerza con la que dispara el tanque
        int force = 40;

    public:
        ///Constructor
        Scene(sf::Window &);
        //Destructor
        ~Scene() {}

    public:
        ///Función que crea las entidades
        void create_scene();

        ///Función que crea los rigid_bodies
        void create_physics_components();

        //Configurar la luz y camera
        void configure_scene();

        //Update de los rigid_bodies
        void configurate_physics();

        ///Update de la escena
        void Update(sf::Window&);

        //Calcula la posición local del tanque
        btVector3 addForce(float);

        ///Función que recoge las colisiones que ocurren en el mundo
        void Collision();
	};
}


