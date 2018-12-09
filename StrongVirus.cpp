#include "StrongVirus.hpp"
#include<GL/glut.h>


namespace vd{
    void StrongVirus::draw() {
        m_xyz[0] = -2;
        m_xyz[1] = -2;
        m_xyz[2] = 0;
        glColor3f(1,0,0);
        glPushMatrix();
            glTranslatef(m_xyz[0], m_xyz[1], m_xyz[2]);
            glutSolidSphere(0.3, 5, 20);
        glPopMatrix();
    }
    void StrongVirus::update() {

    }
}