#pragma once
#include "scene.h"
#include "engine.h"
class MenuScene : public Scene
{
public:
    MenuScene(Engine* engine, InputManager* inputManager);
    void processInput() override;
    void update(float dt) override;
    void render(sf::RenderWindow& window) override;
private:
    sf::RectangleShape background;
    Engine* engine;
    InputManager* inputManager;
};
