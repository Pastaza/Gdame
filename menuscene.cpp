#include "menuscene.h"
#include "engine.h"
#include "gamescene.h"

MenuScene::MenuScene(Engine* engine, InputManager* inputManager) 
    : engine(engine), inputManager(inputManager),
      playButton(300, 250, 200, 60, sf::Color::Green, "Play")
{
    background.setSize(sf::Vector2f(800, 600));
    background.setFillColor(sf::Color::Blue);
}

void MenuScene::processInput(sf::RenderWindow& window)
{
    if (playButton.isClicked(window))
        engine->switchScene(new GameScene(&engine->inputManager));
}

void MenuScene::update(float dt, sf::RenderWindow& window)
{
(void)window;
}

void MenuScene::render(sf::RenderWindow& window)
{
    window.draw(background);
    playButton.draw(window);
}
