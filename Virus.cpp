#include "Virus.hpp"

#include <cmath>
namespace vd {

// Postavlja vektor kretanja u pravcu portala
void Virus::attack() {
  auto dx = 25 - m_xyz[0];
  auto dy = 25 - m_xyz[1];

  auto norm = sqrt(dx * dx + dy * dy);
  dx /= norm;
  dy /= norm;
  m_move_xyz[0] = dx;
  m_move_xyz[1] = dy;
}
void Virus::update() {
  if (m_hp <= 0) {
    deactivate();
    GameVariables::PLASMA += GameVariables::VIRUS_PLASMA_WORTH;
    return;
  }
  m_xyz[0] += m_move_xyz[0] * m_speed;
  m_xyz[1] += m_move_xyz[1] * m_speed;
}
}; // namespace vd