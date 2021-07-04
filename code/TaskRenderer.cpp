/**
* @file Task_Renderer.hpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 19 de Enero de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que pinta por pantalla todos los componentes de la escena
**/
#include "TaskRenderer.hpp"

namespace Engine
{
	//Constructor para inicializar el TaskRenderer
	TaskRenderer::TaskRenderer()
	{
		scene.reset(new Render_Node);
	}

	///Función que crea un model y lo añade a la escena con el id que recibe y 
	///lo que hace es retornar un shared_ptr que guarda la dirección de un componente de render nuevo.
	std::shared_ptr<Render_Component> TaskRenderer::create_render_model(const std::string& id, const std::string& path)
	{
		std::shared_ptr<glt::Model_Obj> model(new Model_Obj(path));
		scene->add(id, model);

		return std::shared_ptr<Render_Component>(new Render_Component{ model });
	}

	///Función que crea un model y lo añade a la escena con el id que recibe y 
	///lo que hace es retornar un shared_ptr que guarda la dirección de un componente de render cube nuevo.
	std::shared_ptr<Cube_Component> TaskRenderer::create_render_cube(const std::string& id)
	{
		std::shared_ptr< Model       > model(new Model);
		model->add(shared_ptr<Drawable>(new Cube), Material::default_material());
		scene->add(id, model);

		return std::shared_ptr<Cube_Component>(new Cube_Component{ model });
	}

	///Función que crea una luz y lo añade a la escena con el id que recibe y 
	///lo que hace es retornar un shared_ptr que guarda la dirección de un componente de luz nuevo.
	std::shared_ptr<Light_Component> TaskRenderer::create_light_component(const std::string& id)
	{
		std::shared_ptr<glt::Light> light(new Light);
		scene->add(id, light);

		return std::shared_ptr<Light_Component>(new Light_Component{ light });
	}

	///Función que crea una camera y lo añade a la escena con el id que recibe y 
	///lo que hace es retornar un shared_ptr que guarda la dirección de un componente de camera nuevo.
	std::shared_ptr<Camera_Component> TaskRenderer::create_camera_component(const std::string& id, const float pov, const float near, const float far, const float aspect_ratio)
	{
		std::shared_ptr<glt::Camera> camera(new Camera(pov, near, far, aspect_ratio));
		scene->add(id, camera);

		return std::shared_ptr<Camera_Component>(new Camera_Component{ camera });
	}

	//Función que recoge el id y tres medidas para trasladar ese componente 
	void TaskRenderer::TranslateComponents(const std::string& id, const float x, const float y, const float z)
	{
		scene->get(id)->translate(Vector3(x, y, z));
	}

	//Función que recibe el id, y un número para escalar ese objeto. Se escala en x, y y z con el esa misma escala que le pasamos
	void TaskRenderer::ScaleComponents(const std::string& id, const float scale)
	{
		scene->get(id)->scale(scale);
	}

	//Función que recibe el id y tres medidas para escalar el objeto. Diferencia con la otra función, esta es más detallada
	void TaskRenderer::ScaleComponentsDetail(const std::string& id, const float scale_x, const float scale_y, const float scale_z)
	{
		scene->get(id)->scale(scale_x, scale_y, scale_z);
	}

	//Función que recoge el id y tres medidas para rotar ese componente.
	void TaskRenderer::RotateComponent(const std::string& id, const float rotate_x, const float rotate_y, const float rotate_z)
	{
		scene->get(id)->rotate_around_x(rotate_x);
		scene->get(id)->rotate_around_y(rotate_y);
		scene->get(id)->rotate_around_z(rotate_z);
	}

	void TaskRenderer::reset_viewport(const sf::Window& window)
	{
		GLsizei width = GLsizei(window.getSize().x);
		GLsizei height = GLsizei(window.getSize().y);

		scene->get_active_camera()->set_aspect_ratio(float(width) / height);

		glViewport(0, 0, width, height);
	}
}