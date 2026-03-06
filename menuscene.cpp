#include "menuscene.h"
#include "gamescene.h"
MenuScene::MenuScene(Engine* engine) : engine(engine)
{
    background.setSize(sf::Vector2f(800, 600));
    background.setFillColor(sf::Color::Blue);
}

void MenuScene::processInput()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
    engine->switchScene(new GameScene());
}

void MenuScene::update(float dt)
{

}

void MenuScene::render(sf::RenderWindow& window)
{
    window.draw(background);
}
