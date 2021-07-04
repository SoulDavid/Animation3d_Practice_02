/**
* @file Camera_Component.hpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 9 de Febrero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que almacena la camara del componente.
**/
#pragma once
#include "Component.hpp"
#include <memory>

/// Declaracion adelantada de Camera
namespace glt
{
	class Camera;
}

namespace Engine
{
	//Al ser un componente, este hereda de la clase Component
	class Camera_Component : public Component
	{
	public:
		//Variable que guarda la camera
		std::shared_ptr<glt::Camera> camera;
	public:
		//Constructor por defecto
		Camera_Component();

		//Funcion que recoge el modelo y se lo pasa a la variable camera.
		Camera_Component(std::shared_ptr<glt::Camera>);
	};
}


