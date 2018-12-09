
#include "Portal.hpp"
#include<GL/glut.h>
namespace vd {
void Portal::draw() {
    glColor3f(0.1,1,0.1);
    glutSolidSphere(0.5, 10, 40);
}
void Portal::update() {

}

}




