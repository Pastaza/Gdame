#pragma once
#include "scene.h"
#include "movement.h"

class GameScene : public Scene
{
public:
    GameScene();
    void processInput() override;
    void update(float dt) override;
    void render(sf::RenderWindow& window) override;

private:
    sf::ConvexShape triangle;
    sf::ConvexShape square;
};
