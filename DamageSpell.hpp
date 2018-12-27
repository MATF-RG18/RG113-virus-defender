
#if !defined(DAMAGESPELL_HPP)
#define DAMAGESPELL_HPP

#include "Spell.hpp"
#include "Virus.hpp"
namespace vd {

class DamageSpell : public Spell {
public:
  DamageSpell(GLfloat x = 0, GLfloat y = 0, GLfloat z = 0.01);
  void draw() override;
  void update() override;
  void applay(Virus &v) override;
  void set_normal_spell() override {
    m_duration_ticks = GameVariables::DAMAGE_SPELL_DURATION;
  }
  static void init();

  static constexpr int PLASMA_WORTH = 500;
  static constexpr int MANA_WORTH = 100;

private:
  constexpr static GLfloat m_damage_per_tick{10};
  constexpr static GLfloat RADIUS = 1.25;
  static GLuint m_draw_list;
  static Material m_material;
};

} // namespace vd

#endif // DAMAGESPELL_HPP
