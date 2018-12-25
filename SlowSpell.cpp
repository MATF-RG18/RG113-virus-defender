#include "SlowSpell.hpp"
#include <GL/glut.h>
namespace vd {
GLuint SlowSpell::m_draw_list;
Material SlowSpell::m_material;

SlowSpell::SlowSpell(GLfloat x, GLfloat y, GLfloat z)
    : Spell(x, y, z, GameVariables::SLOW_SPELL_DURATION, RADIUS) {

  // m_color_rgb[0] = 0;
  // m_color_rgb[1] = 0;
  // m_color_rgb[2] = 0.8;

  // m_material.set_ambient(0, 0, 1, 1);
  // m_material.set_diffuse(0, 0, 1, 1);
  // m_material.set_specular(0, 0, 0, 1);
  // m_material.set_shininess(20);
}
void SlowSpell::init() {
  m_material.set_ambient(0, 0, 1, 1);
  m_material.set_diffuse(0, 0, 1, 1);
  m_material.set_specular(0, 0, 0, 1);
  m_material.set_shininess(20);
  m_draw_list = glGenLists(1);
  glNewList(m_draw_list, GL_COMPILE);
  m_material.draw();

  glScalef(2 * RADIUS, 2 * RADIUS, 1);
  glBegin(GL_LINE_STRIP);
  glVertex3f(-0.5, -0.5, 0.02);
  glVertex3f(0.5, -0.5, 0.02);
  glVertex3f(0.5, 0.5, 0.02);
  glVertex3f(-0.5, 0.5, 0.02);
  glVertex3f(-0.5, -0.5, 0.02);
  glEnd();

  glBegin(GL_LINE_STRIP);
  glVertex3f(0.5, -0.5, 0.02);
  glVertex3f(0, 0.5, 0.02);
  glVertex3f(-0.5, -0.5, 0.02);
  glEnd();

  glEndList();
}
void SlowSpell::applay(Virus &v) { v.set_speed(v.get_speed() * 0.7); }

void SlowSpell::draw() {
  // glColor3f(m_color_rgb[0], m_color_rgb[1],m_color_rgb[2]);
  // m_material.draw();
  glLineWidth(3 + 2 * Math::cos(m_animation_param));
  glPushMatrix();
  glTranslatef(m_xyz[0], m_xyz[1], m_xyz[2]);
  glCallList(m_draw_list);
  glPopMatrix();
}

void SlowSpell::update() {
  if (!is_active())
    return;

  if (m_duration_ticks >= 0) {
    --m_duration_ticks;
    if (GameVariables::SLOW_SPELL_DURATION >= m_duration_ticks)
      m_animation_param += 20;
  } else {
    deactivate();
  }
  // m_animation_parameter += 40;
}

}; // namespace vd
