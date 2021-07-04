/**
* @file Render_Component.cpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 2 de Febrero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que tiene el funcionamiento de recogida del modelo.
**/

#include "Render_Component.hpp"

namespace Engine
{
	/// <summary>
	/// Función que sirve para igualar el modelo al modelo que le pasamos. 
	/// </summary>
	/// <param name="objeto"></param>
	Render_Component::Render_Component(std::shared_ptr <glt::Model_Obj> objeto)
	{
		model = objeto;
	}
}
