/**
* @file Cube_Component.cpp
* Copyright (c) David Mart�n
* @author David Mart�n Almaz�n
* @date 9 de Febrero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que almacena el modelo c�bico del componente.
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