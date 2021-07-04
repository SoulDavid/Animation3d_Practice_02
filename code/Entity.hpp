/**
* @file Entity.hpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 06 de Junio de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que tiene el funcionamiento de las entidades
**/
#pragma once
#include <memory>
#include <vector>
#include <iostream>
#include <list>
#include <map>

#include "Component.hpp"
#include "TaskRenderer.hpp"

#include <SFML/Window.hpp>
#include <btBulletDynamicsCommon.h>

namespace Engine
{
	class Entity
	{
	public:
		//Recoge el transform de la entidad
		btTransform transform_entity;
		//Recoge la matriz de la entidad
		glm::mat4 graphics_transform_entity;

	public:
		//Constructor por defecto
		Entity();
		//Mapa que recoge los componentes de la entidad
		std::map<std::string, std::shared_ptr<Component>> components;
	public:
		///Función para añadir componentes, a la que se le pasa un nombre, y el componente
		void add_Component(std::string, std::shared_ptr<Component>);
	};
}


