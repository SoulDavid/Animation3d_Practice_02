/**
* @file Light_Component.cpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 9 de Febrero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que tiene el funcionamiento de recogida del componente luz.
**/

#include "Light_Component.hpp"

namespace Engine
{
	/// <summary>
	/// Función que sirve para igualar el componente luz a la luz que le pasamos. 
	/// </summary>
	/// <param name="objeto"></param>
	Light_Component::Light_Component(std::shared_ptr<glt::Light> given_light)
	{
		light = given_light;
	}
}
