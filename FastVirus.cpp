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

    }
}