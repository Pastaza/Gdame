#include "button.h"

Button::Button(float x, float y, float width, float height, sf::Color color, const std::string& labelText)
{
    shape.setPosition({x, y});
    shape.setSize({width, height});
    shape.setFillColor(color);

    font.openFromFile("/System/Library/Fonts/Helvetica.ttc");
    label = new sf::Text(font, labelText, 30);
    label->setFillColor(sf::Color::White);

    float textX = x + (width - label->getLocalBounds().size.x) / 2;
    float textY = y + (height - label->getLocalBounds().size.y) / 2 - label->getLocalBounds().position.y;
    label->setPosition({textX, textY});
}

void Button::update(float dt)
{
}

void Button::draw(sf::RenderWindow& window)
{
    window.draw(shape);
    window.draw(*label);
}

bool Button::isClicked(sf::RenderWindow& window)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
        return shape.getGlobalBounds().contains(mousePos);
    }
    return false;
}
