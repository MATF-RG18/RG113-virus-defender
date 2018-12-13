#include "Game.hpp"
#include <GL/glut.h>
#include "StrongVirus.hpp"
#include<iostream>
namespace vd {

    Game::Game() : m_camera(), m_spell_caster(m_grid_controller), m_keyboard_action(m_camera, m_spell_caster),
    m_cursor(m_spell_caster),
    m_passive_mouse_motion_action(m_camera, m_window, m_cursor),
    m_mouse_action(m_cursor) {
        
    }

    void Game::init() {
        m_cursor.init();
    }

    void Game::update() {
        m_grid_controller.update();
    }

    void Game::draw() {
        glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);

        m_camera.setup();

        m_cursor.move(m_camera.position_point()[0], m_camera.position_point()[1],
            m_window.get_center_x(),m_window.get_center_y());
        
        m_cursor.draw();

        glColor3f(3.0, 3.0, 3.0);
        glBegin(GL_POLYGON);
            glVertex3f(0,0,0);
            glVertex3f(0,50,0);
            glVertex3f(50, 50, 0);
            glVertex3f(50, 0, 0);
        glEnd();

 

        
        m_grid_controller.draw();
        glutSwapBuffers();

    }


}