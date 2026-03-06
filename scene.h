#pragma once
#include <SFML/Graphics.hpp>

class Scene
{
public:
    virtual ~Scene() = default;
    virtual void processInput() = 0;
    virtual void update(float dt) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
};
