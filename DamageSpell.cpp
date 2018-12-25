#include "DamageSpell.hpp"
#include <GL/glut.h>

namespace vd {

DamageSpell::DamageSpell(GLfloat x, GLfloat y, GLfloat z)
    : Spell(x, y, z, GameVariables::DAMAGE_SPELL_DURATION, 1.25) {

  m_material.set_ambient(1, 0, 0, 1);
  m_material.set_diffuse(1, 0, 0, 1);
  m_material.set_specular(0, 0, 0, 1);
  m_material.set_shininess(20);
}

void DamageSpell::draw() {

  m_material.draw();
  glLineWidth(4);
  glPushMatrix();
  glTranslatef(m_xyz[0], m_xyz[1], m_xyz[2]);
  glScalef(2 * m_radius, 2 * m_radius, 1);
  glBegin(GL_LINE_STRIP);
  glVertex3f(-0.5, -0.5, m_xyz[2]);
  glVertex3f(0.5, -0.5, m_xyz[2]);
  glVertex3f(0.5, 0.5, m_xyz[2]);
  glVertex3f(-0.5, 0.5, m_xyz[2]);
  glVertex3f(-0.5, -0.5, m_xyz[2]);
  glEnd();

  glBegin(GL_LINE_STRIP);
  glVertex3f(0, -0.5, m_xyz[2]);
  glVertex3f(0.5, 0, m_xyz[2]);
  glVertex3f(0, 0.5, m_xyz[2]);
  glVertex3f(-0.5, 0, m_xyz[2]);
  glVertex3f(0, -0.5, m_xyz[2]);
  glEnd();

  glPopMatrix();
}
void DamageSpell::applay(Virus &v) { v.set_hp(v.get_hp() - m_damage_per_tick); }

void DamageSpell::update() {
  if (!is_active())
    return;

  if (m_duration_ticks >= 0) {
    --m_duration_ticks;
  } else {
    deactivate();
  }

}

} // namespace vd