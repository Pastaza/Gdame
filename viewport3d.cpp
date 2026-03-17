#include "viewport3d.h"
#include <GL/glew.h>
#include <SFML/OpenGL.hpp>
#include <cmath>
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#include <OpenGL/glu.h>
#pragma clang diagnostic pop

Viewport3D::Viewport3D()
{
    sf::ContextSettings settings;
    settings.depthBits = 24;
    (void)renderTexture.resize({440, 395}, settings);
}

void Viewport3D::update(float dt, sf::RenderWindow& window)
{
    (void)dt;

    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    leftDown = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
    bool rightDown  = sf::Mouse::isButtonPressed(sf::Mouse::Button::Right);
    bool middleDown = sf::Mouse::isButtonPressed(sf::Mouse::Button::Middle);

    sf::FloatRect viewportRect(sf::Vector2f(175.f, 55.f), sf::Vector2f(440.f, 395.f));
    bool insideViewport = viewportRect.contains(sf::Vector2f((float)mousePos.x, (float)mousePos.y));

    int dx = mousePos.x - lastMousePos.x;
    int dy = mousePos.y - lastMousePos.y;

    // --- RIGHT CLICK: Orbit camera ---
    if (rightDown && insideViewport)
    {
        cameraYaw   += dx * 0.4f;
        cameraPitch += dy * 0.4f;
        if (cameraPitch >  89.f) cameraPitch =  89.f;
        if (cameraPitch < -89.f) cameraPitch = -89.f;
    }

    // --- MIDDLE CLICK: Pan camera ---
    if (middleDown && insideViewport)
    {
        cameraPanX += dx * 0.02f;
        cameraPanY -= dy * 0.02f;
    }

    // --- LEFT CLICK: Scale gizmo drag ---
    if (leftDown)
    {
        if (!draggingScaleX && xHandleRectWindow.contains(sf::Vector2f((float)mousePos.x, (float)mousePos.y)))
        {
            draggingScaleX = true;
            dragStartMouseX = mousePos.x;
            dragStartScaleX = scaleX;
        }
        if (!draggingScaleY && yHandleRectWindow.contains(sf::Vector2f((float)mousePos.x, (float)mousePos.y)))
        {
            draggingScaleY = true;
            dragStartMouseY = mousePos.y;
            dragStartScaleY = scaleY;
        }
        if (draggingScaleX)
        {
            const float speed    = 0.01f;
            const float minScale = 0.05f;
            scaleX = std::max(minScale, dragStartScaleX + (mousePos.x - dragStartMouseX) * speed);
        }
        if (draggingScaleY)
        {
            const float speed    = 0.01f;
            const float minScale = 0.05f;
            scaleY = std::max(minScale, dragStartScaleY - (mousePos.y - dragStartMouseY) * speed);
        }
    }
    else
    {
        draggingScaleX = false;
        draggingScaleY = false;
    }

    lastMousePos = mousePos;
}

void Viewport3D::render(sf::RenderWindow& window)
{
    (void)renderTexture.setActive(true);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glViewport(0, 0, 440, 395);
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float fov    = 45.0f * 3.14159f / 180.0f;
    float aspect = 440.f / 395.f;
    float nearP  = 0.1f, farP = 100.f;
    float top    = nearP * tan(fov / 2);
    float right  = top * aspect;
    glFrustum(-right, right, -top, top, nearP, farP);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(cameraPanX, cameraPanY, translationZ);
    glRotatef(cameraPitch, 1.f, 0.f, 0.f);
    glRotatef(cameraYaw,   0.f, 1.f, 0.f);

    glScalef(scaleX, scaleY, scaleZ);

    glBegin(GL_QUADS);
    glColor3f(1,0,0); glVertex3f(-1,-1, 1);
    glColor3f(1,0,0); glVertex3f( 1,-1, 1);
    glColor3f(1,0,0); glVertex3f( 1, 1, 1);
    glColor3f(1,0,0); glVertex3f(-1, 1, 1);
    glColor3f(0,1,0); glVertex3f(-1,-1,-1);
    glColor3f(0,1,0); glVertex3f(-1, 1,-1);
    glColor3f(0,1,0); glVertex3f( 1, 1,-1);
    glColor3f(0,1,0); glVertex3f( 1,-1,-1);
    glColor3f(0,0,1); glVertex3f(-1, 1,-1);
    glColor3f(0,0,1); glVertex3f(-1, 1, 1);
    glColor3f(0,0,1); glVertex3f( 1, 1, 1);
    glColor3f(0,0,1); glVertex3f( 1, 1,-1);
    glColor3f(1,1,0); glVertex3f(-1,-1,-1);
    glColor3f(1,1,0); glVertex3f( 1,-1,-1);
    glColor3f(1,1,0); glVertex3f( 1,-1, 1);
    glColor3f(1,1,0); glVertex3f(-1,-1, 1);
    glColor3f(1,0,1); glVertex3f( 1,-1,-1);
    glColor3f(1,0,1); glVertex3f( 1, 1,-1);
    glColor3f(1,0,1); glVertex3f( 1, 1, 1);
    glColor3f(1,0,1); glVertex3f( 1,-1, 1);
    glColor3f(0,1,1); glVertex3f(-1,-1,-1);
    glColor3f(0,1,1); glVertex3f(-1,-1, 1);
    glColor3f(0,1,1); glVertex3f(-1, 1, 1);
    glColor3f(0,1,1); glVertex3f(-1, 1,-1);
    glEnd();

    GLdouble modelview[16], projection[16];
    GLint viewport[4];
    glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
    glGetDoublev(GL_PROJECTION_MATRIX, projection);
    glGetIntegerv(GL_VIEWPORT, viewport);

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
    gluProject(1.0 * scaleX, 0.0, 0.0, modelview, projection, viewport, &screenX, &screenY, &screenZ);
    screenY = 395.0 - screenY;

    GLdouble originSX, originSY, originSZ;
    gluProject(0.0, 0.0, 0.0, modelview, projection, viewport, &originSX, &originSY, &originSZ);
#pragma clang diagnostic pop
    originSY = 395.0 - originSY;

    // Draw X axis line
    sf::Vertex axisLineX[2];
    axisLineX[0] = {sf::Vector2f((float)originSX, (float)originSY), sf::Color::Red};
    axisLineX[1] = {sf::Vector2f((float)screenX + 17.f, (float)screenY + 54.f), sf::Color::Red};
    renderTexture.draw(axisLineX, 2, sf::PrimitiveType::Lines);

    // Draw Y axis line
    sf::Vertex axisLineY[2];
    axisLineY[0] = {sf::Vector2f((float)originSX, (float)originSY), sf::Color::Green};
    axisLineY[1] = {sf::Vector2f((float)screenX + 17.f, (float)screenY + 20.f), sf::Color::Green};
    renderTexture.draw(axisLineY, 2, sf::PrimitiveType::Lines);

    // Handle positions
    float handleSize = 14.f;
    float border     = 3.f;

    float handlexX = (float)screenX + 10.f;
    float handlexY = (float)screenY + 47.f;
    float handleyX = (float)screenX + 10.f;
    float handleyY = (float)screenY + 10.f;  // well separated from X handle

    // X handle border
    sf::RectangleShape xHandleBorder;
    xHandleBorder.setSize({handleSize + border * 2, handleSize + border * 2});
    xHandleBorder.setFillColor(sf::Color::Black);
    xHandleBorder.setPosition({handlexX - border, handlexY - border});
    renderTexture.draw(xHandleBorder);

    // Y handle border
    sf::RectangleShape yHandleBorder;
    yHandleBorder.setSize({handleSize + border * 2, handleSize + border * 2});
    yHandleBorder.setFillColor(sf::Color::Black);
    yHandleBorder.setPosition({handleyX - border, handleyY - border});
    renderTexture.draw(yHandleBorder);

    // X handle
    sf::RectangleShape xHandle;
    xHandle.setSize({handleSize, handleSize});
    xHandle.setFillColor(draggingScaleX ? sf::Color::Yellow : sf::Color::Red);
    xHandle.setPosition({handlexX, handlexY});
    renderTexture.draw(xHandle);

    // Y handle
    sf::RectangleShape yHandle;
    yHandle.setSize({handleSize, handleSize});
    yHandle.setFillColor(draggingScaleY ? sf::Color::Yellow : sf::Color::Green);
    yHandle.setPosition({handleyX, handleyY});
    renderTexture.draw(yHandle);

    // Store rects in window coords for hit-testing
    const sf::Vector2f spritePos(175.f, 55.f);
    xHandleRectWindow = sf::FloatRect(
        spritePos + xHandle.getPosition(),
        xHandle.getSize()
    );
    yHandleRectWindow = sf::FloatRect(
        spritePos + yHandle.getPosition(),
        yHandle.getSize()
    );

    renderTexture.display();

    (void)window.setActive(true);
    window.resetGLStates();

    sf::Sprite sprite(renderTexture.getTexture());
    sprite.setPosition(spritePos);
    window.draw(sprite);
}
