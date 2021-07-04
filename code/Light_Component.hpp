/**
* @file Light_Component.hpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 9 de Febrero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que almacena la luz del componente.
**/
#pragma once
#include <memory>
#include "Component.hpp"

/// Declaracion adelantada de Light
namespace glt
{
	class Light;
}
namespace Engine
{
	//Al ser un componente, este hereda de la clase Component
	class Light_Component : public Component
	{
	public:
		//Variable que guarda el componente luz
		std::shared_ptr<glt::Light> light;
	public:
		//Constructor por defecto
		Light_Component();

		//Funcion que recoge el modelo y se lo pasa a la variable light.
		Light_Component(std::shared_ptr<glt::Light>);
	};
}


