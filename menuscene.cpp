#include "menuscene.h"
#include "gamescene.h"
MenuScene::MenuScene(Engine* engine, InputManager* inputManager) : engine(engine), inputManager(inputManager)
{
    background.setSize(sf::Vector2f(800, 600));
    background.setFillColor(sf::Color::Blue);
}

void MenuScene::processInput()
{
    if (inputManager->isHeld(sf::Keyboard::Key::Enter))
        engine->switchScene(new GameScene(&engine->inputManager));
}

void MenuScene::update(float dt)
{

}

void MenuScene::render(sf::RenderWindow& window)
{
    window.draw(background);
}
