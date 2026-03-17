#include "gamescene.h"

GameScene::GameScene(InputManager* inputManager) : inputManager(inputManager)
{
    square.setPointCount(4);
    square.setPoint(0, sf::Vector2f(150, 100));
    square.setPoint(1, sf::Vector2f(150, 500));
    square.setPoint(2, sf::Vector2f(650, 500));
    square.setPoint(3, sf::Vector2f(650, 100));
    square.setFillColor(sf::Color::Green);
    square.setOutlineColor(sf::Color::Black);
    square.setOutlineThickness(4);

    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(400, 100));
    triangle.setPoint(1, sf::Vector2f(150, 500));
    triangle.setPoint(2, sf::Vector2f(650, 500));
    triangle.setFillColor(sf::Color::Red);
    triangle.setOutlineColor(sf::Color::Black);
    triangle.setOutlineThickness(4);
}

void GameScene::processInput(sf::RenderWindow& window)
{
}

void GameScene::update(float dt, sf::RenderWindow& window)
{
(void)window;
    float movementSpeed = 200.f;

    if (inputManager->isHeld(sf::Keyboard::Key::Left))
        triangle.move({-movementSpeed * dt, 0.f});

    if (inputManager->isHeld(sf::Keyboard::Key::Right))
        triangle.move({movementSpeed * dt, 0.f});
}

void GameScene::render(sf::RenderWindow& window)
{
    window.draw(square);
    window.draw(triangle);
}
