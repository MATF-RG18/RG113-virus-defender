#include "Stats.hpp"
#include "GameVariables.hpp"
#include <GL/freeglut.h>
namespace vd {

void Stats::update() {
  m_mana_string = std::to_string(GameVariables::MANA);
  m_plasma_string = std::to_string(GameVariables::PLASMA);
  m_portal_hp_string = std::to_string(GameVariables::PORTAL_HP);
}
void Stats::draw() {

  int current_width = glutGet(GLUT_WINDOW_WIDTH);
  int current_height = glutGet(GLUT_WINDOW_HEIGHT);
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();
  glDisable(GL_LIGHTING);
  // glDisable(GL_LIGHT0);
  gluOrtho2D(0.0, current_width, current_height, 0.0);

  glRasterPos2i(current_width - current_width * 0.5,
                current_height - current_height * 0.9);

  glColor3f(0.2, 1, 0.2);
  for (auto c : m_portal_hp_string)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);

  glRasterPos2i(current_width - current_width * 0.7,
                current_height - current_height * 0.9);
  for (auto c : m_mana_string)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);

  glRasterPos2i(current_width - current_width * 0.3,
                current_height - current_height * 0.9);
  for (auto c : m_plasma_string)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);

  glEnable(GL_LIGHTING);
  // glEnable(GL_LIGHT0);
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glPopMatrix();
  glutPostRedisplay();
}
} // namespace vd