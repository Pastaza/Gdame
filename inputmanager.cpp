#include "inputmanager.h"

bool InputManager::isHeld(sf::Keyboard::Key key)
{
    return sf::Keyboard::isKeyPressed(key);
}
