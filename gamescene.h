#pragma once
#include "scene.h"
#include "inputmanager.h"
class GameScene : public Scene
{
public:
    GameScene(InputManager* inputManager);
    void processInput() override;
    void update(float dt) override;
    void render(sf::RenderWindow& window) override;
private:
    sf::ConvexShape triangle;
    sf::ConvexShape square;
    InputManager* inputManager;
};
