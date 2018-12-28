#include "Game.hpp"
#include "StrongVirus.hpp"
#include <GL/glut.h>
#include <iostream>

namespace vd {

Game::Game()
    : m_camera(), m_spell_caster(m_grid_controller),
      m_keyboard_action(m_camera, m_spell_caster), m_cursor(m_spell_caster),
      m_passive_mouse_motion_action(m_cursor), m_mouse_action(m_cursor) {}

// Inicijliazuje sve potrebne klase
// Poziva se pre glutMainLoop
void Game::init() {
  m_cursor.init();
  m_main_light.enable();
  m_main_light.draw();
  m_plane.init();
  StrongVirus::init();
  EvasiveVirus::init();
  FastVirus::init();
  SlowSpell::init();
  DamageSpell::init();
}
// Poziva se u on_timer callback funkciji.
// Azurira sve podatke svih aktivinih objekata u igri
void Game::update() {
  m_grid_controller.update();
  stats.update();
  GameVariables::update();
}

// Crta sve aktivne objekte u igri
void Game::draw() {
  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
  // Postavi kameru
  m_camera.setup();

  // Pomeri kursor na ravni
  m_cursor.move(m_camera.position_point()[0], m_camera.position_point()[1],
                m_window.get_center_x(), m_window.get_center_y());

  // Nacratj kursor
  m_cursor.draw();

  // Nacrtaj plane
  m_plane.draw();

  // U grid controller se nalaze svi GameObject koji su aktivni.
  // To ukljucuje viruse i spell-ove. Grid controller ih crta u ravni
  m_grid_controller.draw();

  stats.draw();

  glutSwapBuffers();
}

} // namespace vd