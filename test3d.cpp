#include <SFML/Graphics.hpp>
#include <GL/glew.h>
#include <SFML/OpenGL.hpp>
#include <cmath>

int main()
{
    sf::ContextSettings settings;
    settings.depthBits = 24;
    sf::RenderWindow window(sf::VideoMode({800, 600}), "3D Test", sf::State::Windowed, settings);

    glewInit();
    glEnable(GL_DEPTH_TEST);

    float angle = 0.f;

    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
            if (event->is<sf::Event::Closed>()) window.close();

        angle += 0.5f;

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        float fov = 45.0f * 3.14159f / 180.0f;
        float aspect = 800.f / 600.f;
        float near = 0.1f, far = 100.f;
        float top = near * tan(fov / 2);
        float right = top * aspect;
        glFrustum(-right, right, -top, top, near, far);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.f, 0.f, -20.f);
        glRotatef(angle, 1.f, 1.f, 1.f);

        glBegin(GL_QUADS);
            // Front
            glColor3f(1,0,0); glVertex3f(-1,-1, 1);
            glColor3f(1,0,0); glVertex3f( 1,-1, 1);
            glColor3f(1,0,0); glVertex3f( 1, 1, 1);
            glColor3f(1,0,0); glVertex3f(-1, 1, 1);
            // Back
            glColor3f(0,1,0); glVertex3f(-1,-1,-1);
            glColor3f(0,1,0); glVertex3f(-1, 1,-1);
            glColor3f(0,1,0); glVertex3f( 1, 1,-1);
            glColor3f(0,1,0); glVertex3f( 1,-1,-1);
            // Top
            glColor3f(0,0,1); glVertex3f(-1, 1,-1);
            glColor3f(0,0,1); glVertex3f(-1, 1, 1);
            glColor3f(0,0,1); glVertex3f( 1, 1, 1);
            glColor3f(0,0,1); glVertex3f( 1, 1,-1);
            // Bottom
            glColor3f(1,1,0); glVertex3f(-1,-1,-1);
            glColor3f(1,1,0); glVertex3f( 1,-1,-1);
            glColor3f(1,1,0); glVertex3f( 1,-1, 1);
            glColor3f(1,1,0); glVertex3f(-1,-1, 1);
            // Right
            glColor3f(1,0,1); glVertex3f( 1,-1,-1);
            glColor3f(1,0,1); glVertex3f( 1, 1,-1);
            glColor3f(1,0,1); glVertex3f( 1, 1, 1);
            glColor3f(1,0,1); glVertex3f( 1,-1, 1);
            // Left
            glColor3f(0,1,1); glVertex3f(-1,-1,-1);
            glColor3f(0,1,1); glVertex3f(-1,-1, 1);
            glColor3f(0,1,1); glVertex3f(-1, 1, 1);
            glColor3f(0,1,1); glVertex3f(-1, 1,-1);
        glEnd();

        window.display();
    }
    return 0;
}
