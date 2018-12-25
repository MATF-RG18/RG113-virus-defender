#include "KeyboardAction.hpp"
#include <iostream>
namespace vd {

void KeyboardAction::key_down(unsigned key, int x, int y) {
  switch (key) {
  case '1':
    on_1_down(x, y);
    break;
  case '2':
    on_2_down(x, y);
    break;
  case 'w':
    on_w_down(x, y);
    break;
  case 'a':
    on_a_down(x, y);
    break;
  case 's':
    on_s_down(x, y);
    break;
  case 'd':
    on_d_down(x, y);
    break;
  }
}
void KeyboardAction::key_up(unsigned key, int x, int y) {
  switch (key) {

  case 'w':
    on_w_up(x, y);
    break;
  case 'a':
    on_a_up(x, y);
    break;
  case 's':
    on_s_up(x, y);
    break;
  case 'd':
    on_d_up(x, y);
    break;
  }
}

void KeyboardAction::on_1_down(int, int) {
  m_spell_caster.set_active_spell(SpellCaster::Spells::SLOW);
}
void KeyboardAction::on_2_down(int, int) {
  m_spell_caster.set_active_spell(SpellCaster::Spells::DAMAGE);
}

void KeyboardAction::on_w_down(int, int) { m_camera.start_moving_north(); }
void KeyboardAction::on_a_down(int, int) { m_camera.start_moving_west(); }
void KeyboardAction::on_s_down(int, int) { m_camera.start_moving_south(); }
void KeyboardAction::on_d_down(int, int) { m_camera.start_moving_east(); }

void KeyboardAction::on_w_up(int, int) { m_camera.stop_moving_north(); }
void KeyboardAction::on_a_up(int, int) { m_camera.stop_moving_west(); }
void KeyboardAction::on_s_up(int, int) { m_camera.stop_moving_south(); }
void KeyboardAction::on_d_up(int, int) { m_camera.stop_moving_east(); }

} // namespace vd