#include <SFML/Graphics.hpp> //Used to create the window
#include <optional> // optional huh?
#include <vector> //Very Vectory!

int main()
{
    // SFML 3 uses sf::Vector2u for the size inside VideoMode
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Soon to be game engine");
   

    //Trying to add a square
    sf::ConvexShape square;
    square.setPointCount(4);

    //Setting points of square
    square.setPoint(0, sf::Vector2f(150, 100));
    square.setPoint(1, sf::Vector2f(150, 500));
    square.setPoint(2, sf::Vector2f(650, 500));
    square.setPoint(3, sf::Vector2f(650, 100));

    // Style of square
    square.setFillColor(sf::Color::Green);
    square.setOutlineColor(sf::Color::Black);
    square.setOutlineThickness(4);

    // Creating triangle in ConvexShape
    sf::ConvexShape triangle;
    triangle.setPointCount(3);

    // Setting the Points
    triangle.setPoint(0, sf::Vector2f(400, 100));
    triangle.setPoint(1, sf::Vector2f(150, 500));
    triangle.setPoint(2, sf::Vector2f(650, 500));

    //Style
    triangle.setFillColor(sf::Color::Red);
    triangle.setOutlineColor(sf::Color::Black);
    triangle.setOutlineThickness(4);

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

        window.clear(sf::Color::White);
        window.draw(square);
        window.draw(triangle);
        window.display();
    }

    return 0;
}
