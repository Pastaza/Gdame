#include "viewport3d.h"
#include <GL/glew.h>
#include <SFML/OpenGL.hpp>
#include <cmath>

Viewport3D::Viewport3D()
{
  sf::ContextSettings settings;
  settings.depthBits = 24;
  renderTexture.resize({440, 395}, settings);
  
}

void Viewport3D::update(float dt)
{
  angle += 0.5f;
}

void Viewport3D::render(sf::RenderWindow& window)
{
    renderTexture.setActive(true);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glViewport(0, 0, 440, 395);
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float fov = 45.0f * 3.14159f / 180.0f;
    float aspect = 440.f / 395.f;
    float near = 0.1f, far = 100.f;
    float top = near * tan(fov / 2);
    float right = top * aspect;
    glFrustum(-right, right, -top, top, near, far);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.f, 0.f, -10.f);
    glRotatef(angle, 1.f, 1.f, 0.f);

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

    renderTexture.display();

    window.setActive(true);
    window.resetGLStates();

    sf::Sprite sprite(renderTexture.getTexture());
    sprite.setPosition({175.f, 55.f});
    window.draw(sprite);
}
