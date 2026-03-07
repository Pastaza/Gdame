#pragma once
#include "scene.h"
#include "inputmanager.h"

class Engine;

class EditorScene : public Scene
{
  public:
    EditorScene(Engine* engine, InputManager* inputManager);
    void processInput(sf::RenderWindow& window) override;
    void update(float dt) override;
    void render(sf::RenderWindow& window) override;
  private:
    sf::ConvexShape objectsList;
    sf::ConvexShape minipulationBar;
    sf::ConvexShape propertiesTab;
    sf::ConvexShape fileExplorer;
    sf::ConvexShape viewScene;
};
