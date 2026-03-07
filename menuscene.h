#pragma once
#include "scene.h"
#include "inputmanager.h"
#include "button.h"

class Engine;

class MenuScene : public Scene
{
public:
    MenuScene(Engine* engine, InputManager* inputManager);
    void processInput(sf::RenderWindow& window) override;
    void update(float dt) override;
    void render(sf::RenderWindow& window) override;

private:
    Engine* engine;
    InputManager* inputManager;
    sf::RectangleShape background;
    Button playButton;
};
