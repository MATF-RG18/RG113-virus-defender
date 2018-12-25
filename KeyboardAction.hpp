
#if !defined(KEYBOARD_ACTION_HPP)
#define KEYBOARD_ACTION_HPP

#include "Camera.hpp"
#include "SpellCaster.hpp"
#include <functional>
namespace vd {
class KeyboardAction {
public:
  KeyboardAction(Camera &camera, SpellCaster &spell_caster)
      : m_camera(camera), m_spell_caster(spell_caster) {}
  void key_down(unsigned key, int x, int y);
  void key_up(unsigned key, int x, int y);

private:
  Camera &m_camera;
  SpellCaster &m_spell_caster;
  void on_1_down(int x, int y);
  void on_2_down(int x, int y);

  void on_w_down(int x, int y);
  void on_a_down(int x, int y);
  void on_s_down(int x, int y);
  void on_d_down(int x, int y);

  void on_w_up(int x, int y);
  void on_a_up(int x, int y);
  void on_s_up(int x, int y);
  void on_d_up(int x, int y);
};
} // namespace vd

#endif // KEYBOARD_ACTION_HPP
