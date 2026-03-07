#pragma once
#include <SFML/Graphics.hpp>

class Viewport3D
{
public:
    Viewport3D();
    void update(float dt);
    void render(sf::RenderWindow& window);

private:
    float angle = 0.f;
    sf::RenderTexture renderTexture;
};
