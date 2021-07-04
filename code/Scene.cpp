/**
* @file Scene.cpp
* Copyright (c) David Martín
* @author David Martín Almazán
* @date 06 de julio de 2021
* @section LICENSE
* Licencia MIT
* @section DESCRIPTION
* Script que controla el comportamiento de la escena
**/
#include "Scene.hpp"

namespace Engine
{
    Scene::Scene(sf::Window& window)
    {
        // Se determinan las características de OpenGL disponibles en la máquina:

        if (!glt::initialize_opengl_extensions())
        {
            exit(-1);
        }


        tp = new Physics();

        // Se crea y se configura la escena:
        tr = new TaskRenderer();

        create_scene();

        configure_scene();

        //Creación de nodos
        #pragma region nodes
        wheel_01_model = tr->scene->get("wheel_01");
        wheel_02_model = tr->scene->get("wheel_02");
        wheel_03_model = tr->scene->get("wheel_03");
        wheel_04_model = tr->scene->get("wheel_04");

        box_tank_model = tr->scene->get("Test_01");
        box_test_02_model = tr->scene->get("Test_02");
        terrain_center_model = tr->scene->get("Terrain_Center");
        terrain_right_model = tr->scene->get("Terrain_Right");

        FarWall_model = tr->scene->get("FarWall");
        Key_model = tr->scene->get("Key");

        platform_model = tr->scene->get("Platform");

        bullet_model = tr->scene->get("Bullet");

        bolo_01_model = tr->scene->get("Bolo_01");
        bolo_02_model = tr->scene->get("Bolo_02");
        bolo_03_model = tr->scene->get("Bolo_03");
        bolo_04_model = tr->scene->get("Bolo_04");

        chasis_model = tr->scene->get("chasis");
        #pragma endregion

        //Crear los physics Components
        create_physics_components();

        // Se inicializan algunos elementos de OpenGL:

        tr->reset_viewport(window);

        glClearColor(0.2f, 0.2f, 0.2f, 1.f);
    }

    //Update de los rigid_bodies
    void Scene::configurate_physics()
    {
        tp->Update(p_component_wheel_01, wheel_01, wheel_01_model);
        tp->Update(p_component_wheel_02, wheel_02, wheel_02_model);
        tp->Update(p_component_wheel_03, wheel_03, wheel_03_model);
        tp->Update(p_component_wheel_04, wheel_04, wheel_04_model);

        tp->Update(pc_box_tank, box_tank, box_tank_model);
        tp->Update(pc_terrain_left, box_test_02, box_test_02_model);
        tp->Update(pc_terrain_center, terrain_center, terrain_center_model);
        tp->Update(pc_terrain_right, terrain_right, terrain_right_model);

        tp->Update(pc_FarWall, FarWall, FarWall_model);
        tp->Update(pc_Key, Key, Key_model);

        tp->Update(pc_platform, platform, platform_model);
        tp->Update(pc_bullet, bullet, bullet_model);

        tp->Update(pc_bolo_01, bolo_01, bolo_01_model);
        tp->Update(pc_bolo_02, bolo_02, bolo_02_model);
        tp->Update(pc_bolo_03, bolo_03, bolo_03_model);
        tp->Update(pc_bolo_04, bolo_04, bolo_04_model);

        tp->Update(pc_chasis, chasis, chasis_model);

        Collision();
    }

    ///Función que crea los rigid_bodies
    void Scene::create_physics_components()
    {
        //Rigid_body de la rueda 1
        p_component_wheel_01 = new Physics_Component(tp->dynamicsWorld, .1f, 0.5f, 0.f, { -4, 0.5, 0 });
        _physics_components.push_back(p_component_wheel_01);
        //Rigid_body de la rueda 2
        p_component_wheel_02 = new Physics_Component(tp->dynamicsWorld, .1f, 0.5f, 0.f, { -3.5, 0.5, 0 });
        _physics_components.push_back(p_component_wheel_02);
        //Rigid_body de la rueda 3
        p_component_wheel_03 = new Physics_Component(tp->dynamicsWorld, .1f, 0.5f, 0.f, { -4, 0.5, 0.5 });
        _physics_components.push_back(p_component_wheel_03);
        //Rigid_body de la rueda 4
        p_component_wheel_04 = new Physics_Component(tp->dynamicsWorld, .1f, 0.5f, 0.f, { -3.5, 0.5, 0.5 });
        _physics_components.push_back(p_component_wheel_04);
        //Rigid_body del cubo del tanque
        pc_box_tank = new Physics_Component(tp->dynamicsWorld, { 0.35f, 0.15f, 0.5f }, .5f,.5f, { -4, 1, 0 });
        _physics_components.push_back(pc_box_tank);
        //Rigid_body del cubo de la izquierad
        pc_terrain_left = new Physics_Component(tp->dynamicsWorld, { 3, 1, 3 }, 0, 0, { -6, -3.f, 0 });
        _physics_components.push_back(pc_terrain_left);
        //Rigid_body del cubo central
        pc_terrain_center = new Physics_Component(tp->dynamicsWorld, { 1, 1, 3 }, 0, 0, { 1.f, -3.075f, 0 });
        _physics_components.push_back(pc_terrain_center);
        //Rigid_body del cubo derecho
        pc_terrain_right = new Physics_Component(tp->dynamicsWorld, {3, 1, 3}, 0, 0, {7.f, -3.f, 0.f });
        _physics_components.push_back(pc_terrain_right);
        //Rigid_body de la pared
        pc_FarWall = new Physics_Component(tp->dynamicsWorld, { 0.05f, 1, 3 }, 500.f, 0, { 2.f, -1.05, 0 });
        _physics_components.push_back(pc_FarWall);
        //Rigid_body de la llave
        pc_Key = new Physics_Component(tp->dynamicsWorld, { 0.05, 0.05, 0.05 }, 10.f, 0, { 0.5, -1.5, -2 });
        _physics_components.push_back(pc_Key);
        //Rigid_body de la plataforma
        pc_platform = new Physics_Component(tp->dynamicsWorld, { 0.5, 0.2, 3 }, 500.f, 0.f, { -2.4, -2.25f, 0 });
        _physics_components.push_back(pc_platform);
        //Rigid_body del bolo 1
        pc_bolo_01 = new Physics_Component(tp->dynamicsWorld, { 0.1, 0.4, 0.1 }, 10.f, 0.f, { 4.3, 1, 0 });
        _physics_components.push_back(pc_bolo_01);
        //Rigid_body del bolo 2
        pc_bolo_02 = new Physics_Component(tp->dynamicsWorld, { 0.1, 0.4, 0.1 }, 10.f, 0.f, { 4.3, 1, 0.4 });
        _physics_components.push_back(pc_bolo_02);
        //Rigid_body del bolo 3
        pc_bolo_03 = new Physics_Component(tp->dynamicsWorld, { 0.1, 0.4, 0.1 }, 10.f, 0.f, { 4.3, 1, -0.4 });
        _physics_components.push_back(pc_bolo_03);
        //Rigid_body del bolo 4
        pc_bolo_04 = new Physics_Component(tp->dynamicsWorld, { 0.1, 0.4, 0.1 }, 10.f, 0.f, { 4.7, 1, 0 });
        _physics_components.push_back(pc_bolo_04);
        //Rigid_body de la bala
        pc_bullet = new Physics_Component(tp->dynamicsWorld, { 0.05, 0.05, 0.05 }, 0.2, 0.2, { 0, 0, 1000 });
        _physics_components.push_back(pc_bullet);
        //Rigid_body del cañon
        pc_chasis = new Physics_Component(tp->dynamicsWorld, { 0.05, 0.05, 0.05 }, .2f, 0.2, { -4, 1.5, 0.5 });
        _physics_components.push_back(pc_chasis);

        //Seteo de las gravedades para determinados rigid_bodies
        pc_platform->rigid_body->setGravity({ 0, 0, 0 });
        pc_Key->rigid_body->setGravity({ 0, 0, 0 });
        pc_FarWall->rigid_body->setGravity({ 0, 0, 0 });

        //Constraints
        constraints_Wheel01_carBox = new Constraints(p_component_wheel_01->rigid_body, pc_box_tank->rigid_body, tp, { 0.f, 0.f, 0.f }, { -0.4f, -0.3f, 0.35f }, { 0.f, 0.f, 1.f }, { 0.f, 0.f, 1.f });
        constraints_Wheel02_carBox = new Constraints(p_component_wheel_02->rigid_body, pc_box_tank->rigid_body, tp, { 0.f, 0.f, 0.f }, { 0.4f, -0.3f, 0.35f }, { 0.f, 0.f, 1.f }, { 0.f, 0.f, 1.f });
        constraints_Wheel03_carBox = new Constraints(p_component_wheel_03->rigid_body, pc_box_tank->rigid_body, tp, { 0.f, 0.f, 0.f }, { -0.4f, -0.3f, -0.35f }, { 0.f, 0.f, 1.f }, { 0.f, 0.f, 1.f });
        constraints_Wheel04_carBox = new Constraints(p_component_wheel_04->rigid_body, pc_box_tank->rigid_body, tp, { 0.f, 0.f, 0.f }, { 0.4f, -0.3f, -0.35f }, { 0.f, 0.f, 1.f }, { 0.f, 0.f, 1.f });
    
        constraints_Cañon = new Constraints(pc_box_tank->rigid_body, pc_chasis->rigid_body, tp, { 0.025f, 0.015f, 0.05f }, { 0.f, 0.2f, 0.5f }, { 0.f, 0.f, 1.f }, { 0.f, 0.f, 1.f });
    }

    ///Función que crea las entidades
    void Scene::create_scene()
    {
        //Entidad de la rueda 1
        wheel_01 = new Entity();
        _entities.push_back(wheel_01);
        wheel_01->add_Component("Wheel_01", tr->create_render_model("wheel_01", "../../assets/sphere.obj"));

        //Entidad de la rueda 2
        wheel_02 = new Entity();
        _entities.push_back(wheel_02);
        wheel_02->add_Component("Wheel_02", tr->create_render_model("wheel_02", "../../assets/sphere.obj"));

        //Entidad de la rueda 3
        wheel_03 = new Entity();
        _entities.push_back(wheel_03);
        wheel_03->add_Component("Wheel_03", tr->create_render_model("wheel_03", "../../assets/sphere.obj"));

        //Entidad de la rueda 4
        wheel_04 = new Entity();
        _entities.push_back(wheel_04);
        wheel_04->add_Component("Wheel_04", tr->create_render_model("wheel_04", "../../assets/sphere.obj"));

        //Entidad del cubo del tanque
        box_tank = new Entity();
        _entities.push_back(box_tank);
        box_tank->add_Component("Test_01", tr->create_render_cube("Test_01"));

        //Entidad del cubo izquierdo
        box_test_02 = new Entity();
        _entities.push_back(box_test_02);
        box_test_02->add_Component("Test_02", tr->create_render_cube("Test_02"));

        //Entidad del cubo central
        terrain_center = new Entity();
        _entities.push_back(terrain_center);
        terrain_center->add_Component("Terrain_Center", tr->create_render_cube("Terrain_Center"));

        //Entidad del cubo derecho
        terrain_right = new Entity();
        _entities.push_back(terrain_right);
        terrain_right->add_Component("Terrain_Right", tr->create_render_cube("Terrain_Right"));

        //Entidad de la pared
        FarWall = new Entity();
        _entities.push_back(FarWall);
        FarWall->add_Component("FarWall", tr->create_render_cube("FarWall"));

        //Entidad de la llave
        Key = new Entity();
        _entities.push_back(Key);
        Key->add_Component("Key", tr->create_render_model("Key", "../../assets/Key_01.obj"));

        //Entidad de la plataforma
        platform = new Entity();
        _entities.push_back(platform);
        platform->add_Component("Platform", tr->create_render_cube("Platform"));

        //Entidad del bolo 1
        bolo_01 = new Entity();
        _entities.push_back(bolo_01);
        bolo_01->add_Component("Bolo_01", tr->create_render_cube("Bolo_01"));

        //Entidad del bolo 2
        bolo_02 = new Entity();
        _entities.push_back(bolo_02);
        bolo_02->add_Component("Bolo_02", tr->create_render_cube("Bolo_02"));

        //Entidad del bolo 3
        bolo_03 = new Entity();
        _entities.push_back(bolo_03);
        bolo_03->add_Component("Bolo_03", tr->create_render_cube("Bolo_03"));

        //Entidad del bolo 4
        bolo_04 = new Entity();
        _entities.push_back(bolo_04);
        bolo_04->add_Component("Bolo_04", tr->create_render_cube("Bolo_04"));

        //Entidad de la bala
        bullet = new Entity();
        _entities.push_back(bullet);
        bullet->add_Component("Bullet", tr->create_render_cube("Bullet"));

        //Entidad del cañon
        chasis = new Entity();
        _entities.push_back(chasis);
        chasis->add_Component("chasis", tr->create_render_cube("chasis"));

        //Entidad de la luz
        light = new Entity();
        light->add_Component("MainLight", tr->create_light_component("MainLight"));

        //Entidad de la camara
        camera = new Entity();
        camera->add_Component("MainCamera", tr->create_camera_component("MainCamera", 20.f, 1.f, 50.f, 1.f));
    }

    //Configurar la luz y camera
    void Scene::configure_scene()
    {
        tr->TranslateComponents("MainLight", 10.f, 10.f, 10.f);
        tr->TranslateComponents("MainCamera", 0.f, 0.f, 5.f);
    }

    ///Update de la escena
    void Scene::Update(sf::Window& window)
    {
        do
        {
            // Read the user input:
            sf::Event event;
            //Se calcula la posición del tanque localmente
            btVector3 force_bullet = addForce(-75);

            while (window.pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                    running = false;
                if(event.type == sf::Event::Resized)
                    tr->reset_viewport(window);
                if(event.type == sf::Event::KeyPressed && canPlay)
                {
                    switch (event.key.code)
                    {
                        case sf::Keyboard::D:
                            pc_box_tank->rigid_body->activate(true);
                            pc_box_tank->rigid_body->setAngularVelocity(btVector3(0, -2, 0));
                            break;
                        case sf::Keyboard::A:
                            pc_box_tank->rigid_body->activate(true);
                            pc_box_tank->rigid_body->setAngularVelocity(btVector3(0, 2, 0));
                            break;
                        case sf::Keyboard::S:
                            pc_box_tank->rigid_body->activate(true);

                            pc_box_tank->rigid_body->setLinearVelocity(addForce(1));
                            break;
                        case sf::Keyboard::W:
                            pc_box_tank->rigid_body->activate(true);
                            pc_box_tank->rigid_body->setLinearVelocity(addForce(-1));
                            break;
                        case sf::Keyboard::Space:
                            pc_bullet->rigid_body->activate(true);
                            pc_bullet->rigid_body->setAngularVelocity({ 0, 0, 0 });
                            pc_bullet->rigid_body->setLinearVelocity({0, 0, 0});

                            pc_bullet->rigid_body->getWorldTransform().setOrigin({
                                pc_chasis->rigid_body->getCenterOfMassPosition().getX(),
                                pc_chasis->rigid_body->getCenterOfMassPosition().getY() + 0.3f,
                                pc_chasis->rigid_body->getCenterOfMassPosition().getZ(),
                                });


                            pc_bullet->rigid_body->applyCentralForce({ force_bullet.getX(), force_bullet.getY() + force, force_bullet.getZ()});
                            
                            break;
                        case sf::Keyboard::Escape:
                            running = false;
                            break;
                        case sf::Keyboard::M:
                            if(force < 60)
                                force++;
                            break;
                        case sf::Keyboard::N:
                            if(force > 20)
                                force--;
                            break;
                    }
                }
            }

            tp->dynamicsWorld->stepSimulation(1.f / 60.f);

            //Se le quita la velocidad angular
            #pragma region Seteo de la velocidad angular
            pc_box_tank->rigid_body->setAngularVelocity({ 0, 0, 0 });
            pc_box_tank->rigid_body->setAngularFactor({ 0, 0, 0 });
            pc_platform->rigid_body->setAngularVelocity({ 0, 0, 0 });
            pc_Key->rigid_body->setAngularVelocity({ 0,0,0 });
            pc_FarWall->rigid_body->setAngularVelocity({ 0, 0, 0 });

            pc_platform->rigid_body->setAngularFactor({ 0, 0, 0 });
            pc_FarWall->rigid_body->setAngularFactor({ 0, 0, 0 });

            p_component_wheel_01->rigid_body->setAngularVelocity({ 0, 0, 0 });
            p_component_wheel_02->rigid_body->setAngularVelocity({ 0, 0, 0 });
            p_component_wheel_03->rigid_body->setAngularVelocity({ 0, 0, 0 });
            p_component_wheel_04->rigid_body->setAngularVelocity({ 0, 0, 0 });

            pc_chasis->rigid_body->setAngularVelocity({ 0, 0, 0 });
            #pragma endregion

            configurate_physics();

            #pragma region Scale de los componentes
            tr->ScaleComponents("wheel_01", 0.5f);
            tr->ScaleComponents("wheel_02", 0.5f);
            tr->ScaleComponents("wheel_03", 0.5f);
            tr->ScaleComponents("wheel_04", 0.5f);

            tr->ScaleComponentsDetail("Test_01", 0.35f, 0.15f, 0.50f);
            tr->ScaleComponentsDetail("Test_02", 3.f, 1.f, 3.f);
            tr->ScaleComponentsDetail("Terrain_Center", 1.f, 1.f, 3.f);
            tr->ScaleComponentsDetail("Terrain_Right", 3.f, 1.f, 3.f);

            tr->ScaleComponentsDetail("FarWall", 0.05f, 1, 3);
            tr->ScaleComponentsDetail("Key", 0.05, 0.05, 0.05);

            tr->ScaleComponentsDetail("Platform", 0.6, 0.2, 3.f);
            tr->ScaleComponentsDetail("Bullet", 0.05, 0.05, 0.05);

            tr->ScaleComponentsDetail("Bolo_01", 0.1, 0.4, 0.1);
            tr->ScaleComponentsDetail("Bolo_02", 0.1, 0.4, 0.1);
            tr->ScaleComponentsDetail("Bolo_03", 0.1, 0.4, 0.1);
            tr->ScaleComponentsDetail("Bolo_04", 0.1, 0.4, 0.1);

            tr->ScaleComponentsDetail("chasis", 0.05, 0.05, 0.5);
            #pragma endregion

            //Si la plataforma esta activada
            if (platform_boolean)
            {
                //Se activa
                pc_platform->rigid_body->activate(true);

                //Controla su posición para ver si se tiene que mover
                if (pc_platform->rigid_body->getCenterOfMassPosition().getX() < 0.5)
                {
                    pc_platform->rigid_body->setLinearVelocity({ 0.2, 0, 0 });
                }
                else
                {
                    pc_platform->rigid_body->setLinearVelocity({ 0, 0, 0 });
                }
            }

            //Si la puerta esta abierta
            if (isDoorOpen)
            {
                //Se mueve la llave
                pc_Key->rigid_body->setLinearVelocity({ 0, 1, 0 });

                //Se calcula la posición para ver si se tiene que mover
                if (pc_FarWall->rigid_body->getCenterOfMassPosition().getZ() > -7.f)
                {
                    pc_FarWall->rigid_body->setLinearVelocity({ 0, 0, -2 });
                }
                else
                {
                    pc_FarWall->rigid_body->setLinearVelocity({ 0, 0, 0 });
                }

                //Se calcula la posición para ver si se tiene que ver
                if (pc_Key->rigid_body->getCenterOfMassPosition().getY() > 0)
                {
                    Key_model->set_visible(false);
                }
            }

            Key_model->rotate_around_x(-90);

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            tr->scene->render();

            window.display();
        } while (running);
    }

    //Calcula la posición local del tanque
    btVector3 Scene::addForce(float speed)
    {
        const btVector3 forward(0, 0, 1);
        btVector3 localVelocity = speed * forward;
        btTransform trans = pc_box_tank->rigid_body->getWorldTransform();
        trans.setOrigin(btVector3(0, 0, 0));
        btVector3 worldVelocity = trans * localVelocity;

        return worldVelocity;
    }

    ///Función que recoge las colisiones que ocurren en el mundo
    void Scene::Collision()
    {
        int manifold_count = tp->dynamicsWorld->getDispatcher()->getNumManifolds();
        for (int i = 0; i < manifold_count; i++)
        {
            btPersistentManifold* manifold = tp->dynamicsWorld->getDispatcher()->getManifoldByIndexInternal(i);
            btCollisionObject* object_a = (btCollisionObject*)(manifold->getBody0());
            btCollisionObject* object_b = (btCollisionObject*)(manifold->getBody1());

     
            int numContacts = manifold->getNumContacts();
            for (int j = 0; j < numContacts; j++)
            {
                btManifoldPoint& point = manifold->getContactPoint(j);
                if (point.getDistance() < 0.f)
                {
                    //Rueda - Plataforma
                    if
                        (
                            (object_a == p_component_wheel_01->rigid_body.get() && object_b == pc_platform->rigid_body.get()) ||
                            (object_b == p_component_wheel_01->rigid_body.get() && object_a == pc_platform->rigid_body.get())
                            )
                    {
                        pc_box_tank->rigid_body->activate(true);
                        platform_boolean = true;                           
                    }

                    //Tanque - Llave
                    if
                        (
                            (object_a == pc_box_tank->rigid_body.get() && object_b == pc_Key->rigid_body.get()) ||
                            (object_b == pc_box_tank->rigid_body.get() && object_a == pc_Key->rigid_body.get())
                            )
                    {
                        isDoorOpen = true;
                        pc_FarWall->rigid_body->activate(true);
                    }

                    //Cañon - Llave
                    if
                        (
                            (object_a == pc_chasis->rigid_body.get() && object_b == pc_Key->rigid_body.get()) ||
                            (object_b == pc_chasis->rigid_body.get() && object_a == pc_Key->rigid_body.get())
                            )
                    {
                        isDoorOpen = true;
                        pc_FarWall->rigid_body->activate(true);
                    }

                    //Bala - Puerta
                    if (
                        (object_a == pc_bullet->rigid_body.get() && object_b == pc_FarWall->rigid_body.get()) ||
                        (object_b == pc_bullet->rigid_body.get() && object_a == pc_FarWall->rigid_body.get())
                        )
                    {
                        pc_bullet->rigid_body->setAngularVelocity({ 0, 0, 0 });
                        pc_bullet->rigid_body->setLinearVelocity({ 0, 0, 0 });
                    }

                    //Bala - Bolo 1
                    if (
                        (object_a == pc_bullet->rigid_body.get() && object_b == pc_bolo_01->rigid_body.get()) ||
                        (object_b == pc_bullet->rigid_body.get() && object_a == pc_bolo_01->rigid_body.get())
                        )
                    {
                        pc_bullet->rigid_body->setAngularVelocity({ 0, 0, 0 });
                        pc_bullet->rigid_body->setLinearVelocity({ 0, 0, 0 });
                        pc_bolo_01->rigid_body->applyCentralForce({ 500, 0, 0 });
                    }

                    //Bala - Bolo 2
                    if (
                        (object_a == pc_bullet->rigid_body.get() && object_b == pc_bolo_02->rigid_body.get()) ||
                        (object_b == pc_bullet->rigid_body.get() && object_a == pc_bolo_02->rigid_body.get())
                        )
                    {
                        pc_bullet->rigid_body->setAngularVelocity({ 0, 0, 0 });
                        pc_bullet->rigid_body->setLinearVelocity({ 0, 0, 0 });
                        pc_bolo_02->rigid_body->applyCentralForce({ 500, 0, 0 });
                    }

                    //Bala - Bolo 3
                    if (
                        (object_a == pc_bullet->rigid_body.get() && object_b == pc_bolo_03->rigid_body.get()) ||
                        (object_b == pc_bullet->rigid_body.get() && object_a == pc_bolo_03->rigid_body.get())
                        )
                    {
                        pc_bullet->rigid_body->setAngularVelocity({ 0, 0, 0 });
                        pc_bullet->rigid_body->setLinearVelocity({ 0, 0, 0 });
                        pc_bolo_03->rigid_body->applyCentralForce({ 500, 0, 0 });
                    }

                    //Bala - Bolo 4
                    if (
                        (object_a == pc_bullet->rigid_body.get() && object_b == pc_bolo_04->rigid_body.get()) ||
                        (object_b == pc_bullet->rigid_body.get() && object_a == pc_bolo_04->rigid_body.get())
                        )
                    {
                        pc_bullet->rigid_body->setAngularVelocity({ 0, 0, 0 });
                        pc_bullet->rigid_body->setLinearVelocity({ 0, 0, 0 });
                        pc_bolo_04->rigid_body->applyCentralForce({ 500, 0, 0 });
                    }

                    //Rueda - terreno izquierdo
                    if (
                        (object_a == p_component_wheel_01->rigid_body.get() && object_b == pc_terrain_left->rigid_body.get()) ||
                        (object_b == p_component_wheel_01->rigid_body.get() && object_a == pc_terrain_left->rigid_body.get())
                        )
                    {
                        p_component_wheel_01->rigid_body->setGravity({ 0, 0, 0 });
                        p_component_wheel_02->rigid_body->setGravity({ 0, 0, 0 });
                        p_component_wheel_03->rigid_body->setGravity({ 0, 0, 0 });
                        p_component_wheel_04->rigid_body->setGravity({ 0, 0, 0 });
                        canPlay = true;
                    }
                }
            }
        }
    }
}
