#include "EvasiveVirus.hpp"
#include <GL/glut.h>

namespace vd {

GLuint EvasiveVirus::m_draw_list;
Material EvasiveVirus::m_material;

EvasiveVirus::EvasiveVirus(GLfloat x, GLfloat y, GLfloat z)
    : Virus(x, y, z, HP, SPEED, RADIUS) {}
// Inicijalizacija draw liste za cratnje EvasiveVirusa
// poziva se samo jednom u Game::init
void EvasiveVirus::init() {
  m_draw_list = glGenLists(1);
  m_material.set_ambient(0.3, 0.3, 0.9, 1);
  m_material.set_diffuse(0.1, 0.3, 0.9, 1);
  m_material.set_specular(0, 0, 0.3, 1);
  m_material.set_shininess(30);
  glNewList(m_draw_list, GL_COMPILE);
  m_material.draw();
  glutSolidSphere(RADIUS, 64, 64);
  glEndList();
}

void EvasiveVirus::draw() {
  glPushMatrix();
  glTranslatef(m_xyz[0], m_xyz[1], m_xyz[2]);
  glCallList(m_draw_list);
  glPopMatrix();
}

void EvasiveVirus::update() {
  Virus::update();
  m_speed = SPEED;
}
} // namespace vd