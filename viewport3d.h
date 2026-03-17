#pragma once
#include <SFML/Graphics.hpp>
#include <GL/glew.h>

class Viewport3D
{
public:
    Viewport3D();
    void update(float dt, sf::RenderWindow& window);
    void render(sf::RenderWindow& window);

private:
    // Where is the Mouse located
    GLdouble screenX = 0, screenY = 0, screenZ = 0;
    sf::Vector2i lastMousePos;
    //Is dragging
    bool leftDown = false;
    bool draggingScaleX = false;
    int dragStartMouseX = 0;
    float dragStartScaleX = 1.0f;
    bool draggingScaleY = false;
    int dragStartMouseY = 0;
    float dragStartScaleY = 1.0f;
    sf::FloatRect yHandleRectWindow;
    sf::FloatRect xHandleRectWindow;
    // Camera orbit & pan
    float cameraYaw   =   0.f;
    float cameraPitch =  20.f;
    float cameraPanX  =   0.f;
    float cameraPanY  =   0.f;
    // Position Variable
    float translationX = 0.0f;
    float translationY = 0.0f;
    float translationZ = -10.0f;
    // Rotation Variable
    float rotationX = 0.5f;
    float rotationY = 0.0f;
    float rotationZ = 0.0f;
    //Scale Variable
    float scaleX = 1.0f;
    float scaleY = 1.0f;
    float scaleZ = 1.0f;
    //Angle
    float angle = 0.f;
    sf::RenderTexture renderTexture;
};
