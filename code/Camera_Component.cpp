/**
* @file Camera_Component.cpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 9 de Febrero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que tiene el funcionamiento de recogida de la camera.
**/

#include "Camera_Component.hpp"

namespace Engine
{
	/// <summary>
	/// Función que sirve para igualar la camera a la camera que le pasamos. 
	/// </summary>
	/// <param name="objeto"></param>
	Camera_Component::Camera_Component(std::shared_ptr<glt::Camera> given_camera)
	{
		camera = given_camera;
	}
}

