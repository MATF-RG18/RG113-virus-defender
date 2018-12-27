#include "FastVirus.hpp"
#include <GL/glut.h>

namespace vd {
GLuint FastVirus::m_draw_list;
Material FastVirus::m_material;

FastVirus::FastVirus(GLfloat x, GLfloat y, GLfloat z)
    : Virus(x, y, z, HP, SPEED, RADIUS) {}

// Inicijalizacija draw liste za cratnje FastVirus
// poziva se samo jednom u Game::init

void FastVirus::init() {
  m_draw_list = glGenLists(1);
  m_material.set_ambient(0.3, 0.9, 0.3, 1);
  m_material.set_diffuse(0.1, 0.9, 0.1, 1);
  m_material.set_specular(0, 0.3, 0, 1);
  m_material.set_shininess(30);
  glNewList(m_draw_list, GL_COMPILE);
  m_material.draw();
  glutSolidSphere(RADIUS, 20, 20);
  glEndList();
}

void FastVirus::draw() {
  glPushMatrix();
  glTranslatef(m_xyz[0], m_xyz[1], m_xyz[2]);
  glCallList(m_draw_list);
  glPopMatrix();
}

 // nakon svakog update-a vracamo virusu m_speed na pocetnu vrednost
  // Nakon sto se pozove update za sve viruse u GridController
  // poziva se applay spell za sve viruse koji se nalaze u 
  // range-u spella. 
  // Ovako se eliminse potreba da se proverava kada je virus izasao
  // iz range spell-a jer ce se brzina vratiti na pocetnu
void FastVirus::update() {
  Virus::update();
  m_speed = SPEED;
}
} // namespace vd