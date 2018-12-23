#include "EvasiveVirus.hpp"
#include <GL/glut.h>

namespace vd {
EvasiveVirus::EvasiveVirus(GLfloat x, GLfloat y, GLfloat z)
      : Virus(x, y, z, HP, SPEED, RADIUS) {
    m_material.set_ambient(0.3,0.3,0.9,1);
    m_material.set_diffuse(0.1, 0.3, 0.9, 1);
    m_material.set_specular(0,0,0.3,1);
    m_material.set_shininess(30);
  }
void EvasiveVirus::draw() {
  m_material.draw();
  glPushMatrix();
    glTranslatef(m_xyz[0], m_xyz[1], m_xyz[2]);
    glutSolidSphere(RADIUS, 64, 64);
  glPopMatrix();
}
void EvasiveVirus::update() {
  Virus::update();
  m_speed = SPEED;
}
}  // namespace vd