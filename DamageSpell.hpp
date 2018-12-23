
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

private:
  constexpr static GLfloat m_damage_per_tick{10};
};

} // namespace vd

#endif // DAMAGESPELL_HPP
