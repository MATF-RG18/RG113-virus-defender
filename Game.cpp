#include "Game.hpp"
#include <GL/glut.h>
#include<iostream>
namespace vd {

    Game::Game() : m_camera(), m_keyboard_action(m_camera),
    m_mouse_motion_action(m_camera) {
        
    }

    void Game::init() {

    }

    void Game::update() {
        // std::cerr << 1;
    }
    void Game::set_keyboard_input(unsigned char key, int x, int y) {
        m_keyboard_action(key, x, y);
    }

    void Game::set_passive_mouse_motion_input(int x, int y) {
        m_mouse_motion_action(x,y);
    }

    void Game::draw() {
        glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
        // Set up camera
        // glMatrixMode(GL_MODELVIEW);
        // glLoadIdentity();
        // gluLookAt(10, 10, 10, 0, 0, 0, 0, 0, 1);
        m_camera.setup();
        // Draw white wired plane
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
            for (GLfloat i = 0; i <= 50; i += 0.5) {
                glVertex3f(i, 0, 0); glVertex3f(i, 50, 0);
                glVertex3f(0, i, 0); glVertex3f(50, i, 0);
            }
        glEnd();

        glPushMatrix();
            glColor3f(1,1,0);
            glTranslatef(20, 20, 2);
            glutSolidSphere(2, 10, 30);
        glPopMatrix();

        glPushMatrix();
            glColor3f(1,0,0);
            glTranslatef(10, 40, 2);
            glutSolidSphere(2, 10, 30);
        glPopMatrix();

        glPushMatrix();
            glColor3f(0,0,1);
            glTranslatef(25, 25, 2);
            glutSolidTeapot(4);
        glPopMatrix();
        glutSwapBuffers();

    }


}