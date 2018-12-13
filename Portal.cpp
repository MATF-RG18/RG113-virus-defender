
#include "Portal.hpp"
#include<GL/glut.h>
namespace vd {
void Portal::draw() {
    glColor3f(0.1,1,0.1);
    glPushMatrix();
        glTranslatef(m_xyz[0], m_xyz[1], m_xyz[2]);
        glutSolidSphere(3, 30, 40);
    glPopMatrix();

}
void Portal::update() 
{
    
}

}




