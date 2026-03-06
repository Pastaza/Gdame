#include "movement.h"

void handleMovement(sf::ConvexShape& shape, float dt) 
{
 // Movement Speed of triangle
        float movementSpeed = 2.f;

        // Movement of triangle
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
          shape.move({-movementSpeed, 0.f});
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
          shape.move({movementSpeed, 0.f});
        } 
} 
