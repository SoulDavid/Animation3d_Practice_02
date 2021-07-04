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
#include "Entity.hpp"

namespace Engine
{
	Entity::Entity()
	{

	}
	

	//Añade un componente al mapa con un id y el componente
	void Entity::add_Component(std::string name, std::shared_ptr<Component> component)
	{
		//https://www.cplusplus.com/reference/map/map/insert/
		components.insert({ name, component });
	}

}