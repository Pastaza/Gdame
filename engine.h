#pragma once
#include <SFML/Graphics.hpp>
#include "scene.h"
#include "inputmanager.h"

class Engine
{
public:
    Engine();
    void run();
    void switchScene(Scene* newScene);
    InputManager inputManager;

private:
    sf::RenderWindow window;
    sf::Clock gameClock;
    Scene* currentScene;};


