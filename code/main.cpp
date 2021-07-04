/**
* @file main.cpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 6 de Julio de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Creación de la ventana y escena
**/
#include <memory>
#include <vector>
#include <iostream>

#include "Scene.hpp"
#include "Physics.hpp"

#include <SFML/Window.hpp>
#include <btBulletDynamicsCommon.h>

using namespace std;
using namespace glt;
using namespace Engine;

int main ()
{
    // Se crea la ventana y el contexto de OpenGL asociado a ella:

    sf::Window window
    (
        sf::VideoMode(1800, 1080),
        "Bullet Rigid Bodies",
        sf::Style::Default,
        sf::ContextSettings(24, 0, 0, 3, 2, sf::ContextSettings::Core)      // Se usa OpenGL 3.2 core profile
    );
    
    // Se activa la sincronización vertical:
    window.setVerticalSyncEnabled(true);

    //Se crea la escena
    Scene scene (window);

    //El update de la escena
    scene.Update(window);

    return EXIT_SUCCESS;
}
