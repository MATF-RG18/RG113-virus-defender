#include "FastVirus.hpp"
#include<GL/glut.h>


namespace vd{
    void FastVirus::draw() {
        glColor3f(0,1,0);
        glPushMatrix();
            glTranslatef(m_xyz[0], m_xyz[1], m_xyz[2]);
            glutSolidSphere(0.1, 5, 20);
        glPopMatrix();
    }
    void FastVirus::update() {
        if (m_hp <= 0) {
            deactivate();
            return;
        }
        
        m_xyz[0] += m_move_xyz[0] * m_speed;
        m_xyz[1] += m_move_xyz[1] * m_speed;
        m_speed = SPEED;
        
    }
}