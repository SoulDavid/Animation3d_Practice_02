/**
* @file Task_Renderer.cpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 19 de Enero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que pinta por pantalla todos los componentes de la escena
**/
#pragma once
#include <memory>
#include <vector>
#include <iostream>

#include <Render_Node.hpp>
#include <Light.hpp>
#include <Cube.hpp>
#include <Model.hpp>
#include <OpenGL.hpp>
#include <Model_Obj.hpp>

#include "Light_Component.hpp"
#include "Render_Component.hpp"
#include "Camera_Component.hpp"
#include "Cube_Component.hpp"

#include <SFML/Window.hpp>
#include <btBulletDynamicsCommon.h>

using namespace std;
using namespace glt;

namespace Engine
{
	class TaskRenderer
	{

	public:
		//Puntero de render Node, se encarga de por así decirlo, el lienzo de la escena, donde se añadiran los objetos para pintarse
		shared_ptr< Render_Node > scene;
	public:
		//Constructor para inicializar el TaskRenderer
		TaskRenderer();
		//Destructor
		~TaskRenderer() {}
		///Función que crea un model y lo añade a la escena con el id que recibe y 
		///lo que hace es retornar un shared_ptr que guarda la dirección de un componente de render nuevo.
		std::shared_ptr<Render_Component> create_render_model(const std::string& id, const std::string& path);
		///Función que crea un model y lo añade a la escena con el id que recibe y 
		///lo que hace es retornar un shared_ptr que guarda la dirección de un componente de render cube nuevo.
		std::shared_ptr<Cube_Component> create_render_cube(const std::string& id);
		///Función que crea una luz y lo añade a la escena con el id que recibe y 
		///lo que hace es retornar un shared_ptr que guarda la dirección de un componente de luz nuevo.
		std::shared_ptr<Light_Component> create_light_component(const std::string& id);
		///Función que crea una camera y lo añade a la escena con el id que recibe y 
		///lo que hace es retornar un shared_ptr que guarda la dirección de un componente de camera nuevo.
		std::shared_ptr<Camera_Component> create_camera_component(const std::string& id, const float, const float, const float, const float);
		//Función que recibe el id, y un número para escalar ese objeto. Se escala en x, y y z con el esa misma escala que le pasamos
		void ScaleComponents(const std::string&, const float);

		//Función que recibe el id y tres medidas para escalar el objeto. Diferencia con la otra función, esta es más detallada
		void ScaleComponentsDetail(const std::string&, const float, const float, const float);

		//Función que recoge el id y tres medidas para trasladar ese componente 
		void TranslateComponents(const std::string&, const float, const float, const float);

		//Función que recoge el id y tres medidas para rotar ese componente.
		void RotateComponent(const std::string&, const float, const float, const float);

		//Función que recoge el id y el bool para hacer un item visible o no visible
		void SetVisible(const std::string&, bool);

		void reset_viewport(const sf::Window&);
	};
}


