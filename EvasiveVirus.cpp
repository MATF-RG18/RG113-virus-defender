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

    }
}