/**
* @file Cube_Component.hpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 9 de Febrero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que almacena el modelo cúbico del componente.
**/

#pragma once
#include <memory>
#include "Component.hpp"

/// Declaracion adelantada de Model_Obj
namespace glt
{
	class Model;
}

namespace Engine
{
	class Cube_Component : public Component
	{
	public:
		//Variable que guarda el modelo
		std::shared_ptr <glt::Model> model;
	public:
		//Constructor por defecto
		Cube_Component();

		//Funcion que recoge el modelo y se lo pasa a la variable model.
		Cube_Component(std::shared_ptr <glt::Model>);
	};
}


