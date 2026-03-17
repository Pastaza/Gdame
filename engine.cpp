#include "engine.h"
#include "gamescene.h"
#include "EditorScene.h"

Engine::Engine() : window(sf::VideoMode({800, 600}), "Soon to be game engine")
{
    window.setVisible(true);
    window.requestFocus();
    currentScene = new EditorScene(this, &inputManager);
}

void Engine::run()
{
    while (window.isOpen())
    {
        float dt = gameClock.restart().asSeconds();

        // INPUT
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        currentScene->processInput(window);

        // UPDATE
        currentScene->update(dt, window);

        // RENDER
        window.clear(sf::Color::White);
        currentScene->render(window);
        window.display();
    }
}

void Engine::switchScene(Scene* newScene)
{
    delete currentScene;
    currentScene = newScene;
}
