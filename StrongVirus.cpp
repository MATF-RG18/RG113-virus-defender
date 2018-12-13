#include "StrongVirus.hpp"
#include<GL/glut.h>


namespace vd{
    void StrongVirus::draw() {
        glColor3f(m_color_rgb[0],m_color_rgb[1],m_color_rgb[2]);
        glPushMatrix();
            glTranslatef(m_xyz[0], m_xyz[1], m_xyz[2]);
            glutSolidSphere(m_radius_size, 20, 40);
        glPopMatrix();
    }
    void StrongVirus::update() {
        if (m_hp <= 0) {
            deactivate();
            return;
        }
        
        m_xyz[0] += m_move_xyz[0] * m_speed;
        m_xyz[1] += m_move_xyz[1] * m_speed;
        m_speed = SPEED;
    }
}