#include "EditorScene.h"
#include "engine.h"

EditorScene::EditorScene(Engine* engine, InputManager* inputManager)
{
  minipulationBar.setPointCount(4);
    minipulationBar.setPoint(0, sf::Vector2f(0, 0));
    minipulationBar.setPoint(1, sf::Vector2f(800, 0));
    minipulationBar.setPoint(2, sf::Vector2f(800, 55));
    minipulationBar.setPoint(3, sf::Vector2f(0, 55));
    minipulationBar.setFillColor(sf::Color::Black);
    minipulationBar.setOutlineColor(sf::Color::Black);
    minipulationBar.setOutlineThickness(0);


  objectsList.setPointCount(4);
    objectsList.setPoint(0, sf::Vector2f(0, 55));
    objectsList.setPoint(1, sf::Vector2f(175, 55));
    objectsList.setPoint(2, sf::Vector2f(175, 450));
    objectsList.setPoint(3, sf::Vector2f(0, 450));
    objectsList.setFillColor(sf::Color::Red);
    objectsList.setOutlineColor(sf::Color::Red);
    objectsList.setOutlineThickness(0);

  propertiesTab.setPointCount(4);
    propertiesTab.setPoint(0, sf::Vector2f(800, 55));
    propertiesTab.setPoint(1, sf::Vector2f(615, 55));
    propertiesTab.setPoint(2, sf::Vector2f(615, 450));
    propertiesTab.setPoint(3, sf::Vector2f(800, 450));
    propertiesTab.setFillColor(sf::Color::Green);
    propertiesTab.setOutlineColor(sf::Color::Green);
    propertiesTab.setOutlineThickness(0);

  fileExplorer.setPointCount(4);
    fileExplorer.setPoint(0, sf::Vector2f(0, 450));
    fileExplorer.setPoint(1, sf::Vector2f(0, 600));
    fileExplorer.setPoint(2, sf::Vector2f(800, 600));
    fileExplorer.setPoint(3, sf::Vector2f(800, 450));
    fileExplorer.setFillColor(sf::Color::Blue);
    fileExplorer.setOutlineColor(sf::Color::Blue);
    fileExplorer.setOutlineThickness(0);

  viewScene.setPointCount(4);
    viewScene.setPoint(0, sf::Vector2f(175, 55));
    viewScene.setPoint(1, sf::Vector2f(175, 450));
    viewScene.setPoint(2, sf::Vector2f(615, 450));
    viewScene.setPoint(3, sf::Vector2f(615, 55));
    viewScene.setFillColor(sf::Color::Yellow);
    viewScene.setOutlineColor(sf::Color::Yellow);
    viewScene.setOutlineThickness(0);

}


void EditorScene::processInput(sf::RenderWindow& window)
{
   
}

void EditorScene::update(float dt)
{

}

void EditorScene::render(sf::RenderWindow& window)
{
  window.draw(viewScene);
  window.draw(fileExplorer);
  window.draw(objectsList);
  window.draw(propertiesTab);
  window.draw(minipulationBar);
}
