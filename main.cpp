#include <SFML/Graphics.hpp>
#include <optional> // Required for std::optional

int main()
{
    // SFML 3 uses sf::Vector2u for the size inside VideoMode
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Soon to be game engine");

    while (window.isOpen())
    {
        // pollEvent() now returns an optional; we check it in the while loop
        while (const std::optional event = window.pollEvent())
        {
            // Use .is<>() to check for specific event types
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear(sf::Color::Red);
        window.display();
    }

    return 0;
}
