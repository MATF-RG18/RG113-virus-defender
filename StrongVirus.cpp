#include "StrongVirus.hpp"
#include <GL/glut.h>

namespace vd {

GLuint StrongVirus::m_draw_list;
Material StrongVirus::m_material;

StrongVirus::StrongVirus(GLfloat x, GLfloat y, GLfloat z)
    : Virus(x, y, z, HP, SPEED, RADIUS) {


}

void StrongVirus::init()
{
  m_material.set_ambient(0.8, 0.3, 0.3, 1);
  m_material.set_diffuse(1, 0.3, 0.1, 1);
  m_material.set_specular(0.3, 0, 0, 1);
  m_material.set_shininess(10);
  m_draw_list = glGenLists(1);
  glNewList(m_draw_list, GL_COMPILE);
  m_material.draw();
  glutSolidSphere(RADIUS, 64, 64);
  glEndList();
}


void StrongVirus::draw() {
  // glColor3f(m_color_rgb[0], m_color_rgb[1], m_color_rgb[2]);
  glPushMatrix();
  glTranslatef(m_xyz[0], m_xyz[1], m_xyz[2]);
  glCallList(m_draw_list);
  glPopMatrix();
}
void StrongVirus::update() {
  Virus::update();
  m_speed = SPEED;
}
} // namespace vd