#include "DamageSpell.hpp"
#include "Math.hpp"
#include <GL/glut.h>
namespace vd {
GLuint DamageSpell::m_draw_list;
Material DamageSpell::m_material;

DamageSpell::DamageSpell(GLfloat x, GLfloat y, GLfloat z)
    : Spell(x, y, z, GameVariables::DAMAGE_SPELL_DURATION, RADIUS) {
  m_animation_param = 0;
}
// Inicira draw listu kojom se crta DamageSpell
// poziva se jednom samo Game::init()

void DamageSpell::init() {
  m_material.set_ambient(1, 0, 0, 1);
  m_material.set_diffuse(1, 0, 0, 1);
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
  glVertex3f(0, -0.5, 0.02);
  glVertex3f(0.5, 0, 0.02);
  glVertex3f(0, 0.5, 0.02);
  glVertex3f(-0.5, 0, 0.02);
  glVertex3f(0, -0.5, 0.02);
  glEnd();

  glEndList();
}
// Crta DamageSpell na ravni
void DamageSpell::draw() {

  // Podesavanjem debljine linije pravi se animacija
  glLineWidth(3 + 2 * Math::cos(m_animation_param));

  glPushMatrix();
  glTranslatef(m_xyz[0], m_xyz[1], m_xyz[2]);
  glCallList(m_draw_list);
  glPopMatrix();
}

void DamageSpell::applay(Virus &v) { v.set_hp(v.get_hp() - m_damage_per_tick); }

void DamageSpell::update() {
  if (!is_active())
    return;

  // Kada istekne trajanje spella on se deaktivira
  if (m_duration_ticks >= 0) {
    --m_duration_ticks;

    // Ukoliko je postavljeno trajanje spell-a na inf tikova
    // to znaci da je u pitanju perma spell i on se ne animira
    if (GameVariables::DAMAGE_SPELL_DURATION >= m_duration_ticks)
      m_animation_param += 20;

  } else {
    deactivate();
  }
}

} // namespace vd