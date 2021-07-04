/**
* @file Render_Component.hpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 2 de Febrero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que almacena el modelo del componente.
**/

#pragma once
#include <memory>
#include "Component.hpp"


/// Declaracion adelantada de Model_Obj
namespace glt
{
	class Model_Obj;
}

namespace Engine
{
	//Al ser un componente, este hereda de la clase Component
	class Render_Component : public Component
	{
	public: 
		//Variable que guarda el modelo
		std::shared_ptr <glt::Model_Obj> model;
	public:
		//Constructor por defecto
		Render_Component();

		//Funcion que recoge el modelo y se lo pasa a la variable model.
		Render_Component(std::shared_ptr <glt::Model_Obj>);
	};
}


