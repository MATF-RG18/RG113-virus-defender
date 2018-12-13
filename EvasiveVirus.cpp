#include "EvasiveVirus.hpp"
#include<GL/glut.h>


namespace vd{
    void EvasiveVirus::draw() {

        glColor3f(0,0,1);
        glPushMatrix();
            glTranslatef(m_xyz[0], m_xyz[1], m_xyz[2]);
            glutSolidSphere(0.2, 5, 20);
        glPopMatrix();
    }
    void EvasiveVirus::update() {
        if (m_hp <= 0) {
            deactivate();
            return;
        }
       
        m_xyz[0] += m_move_xyz[0] * m_speed;
        m_xyz[1] += m_move_xyz[1] * m_speed;
        m_speed = SPEED;

    }
}