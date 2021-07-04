/**
* @file Cube_Component.cpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 9 de Febrero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que almacena el modelo cúbico del componente.
**/
#include "Cube_Component.hpp"

namespace Engine
{
	//Constructor por defecto
	Cube_Component::Cube_Component(std::shared_ptr <glt::Model> objeto)
	{
		model = objeto;
	}
}