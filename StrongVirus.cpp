#include "StrongVirus.hpp"
#include <GL/glut.h>

namespace vd {
  StrongVirus::StrongVirus(GLfloat x, GLfloat y, GLfloat z)
      : Virus(x, y, z, HP, SPEED, RADIUS) 
  {
    m_material.set_ambient(0.8,0.3,0.3,1);
    m_material.set_diffuse(1, 0.3, 0.1, 1);
    m_material.set_specular(0.3,0,0,1);
    m_material.set_shininess(10);
  }

void StrongVirus::draw() {
  // glColor3f(m_color_rgb[0], m_color_rgb[1], m_color_rgb[2]);
  m_material.draw();
  glPushMatrix();
    glTranslatef(m_xyz[0], m_xyz[1], m_xyz[2]);
    glutSolidSphere(RADIUS, 64, 64);
  glPopMatrix();
}
void StrongVirus::update() {
  Virus::update();
  m_speed = SPEED;
}
}  // namespace vd