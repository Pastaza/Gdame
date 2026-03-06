#pragma once
#include <SFML/Graphics.hpp>
#include "scene.h"

class Engine
{
public:
    Engine();
    void run();
    void switchScene(Scene* newScene);

private:
    sf::RenderWindow window;
    sf::Clock gameClock;
    Scene* currentScene;};


