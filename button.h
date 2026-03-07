#pragma once
#include "gameobject.h"

class Button : public GameObject
{
public:
    Button(float x, float y, float width, float height, sf::Color color, const std::string& labelText);
    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;
    bool isClicked(sf::RenderWindow& window);
private:
    sf::Font font;
    sf::Text* label;
    sf::RectangleShape shape;
};
