#if !defined(SLOWSPELL_HPP)
#define SLOWSPELL_HPP
#include "GameVariables.hpp"
#include "Spell.hpp"
namespace vd {

class SlowSpell : public Spell {
public:
  SlowSpell(GLfloat x = 0, GLfloat y = 0, GLfloat z = 0.01);
     
  void draw() override;
  void update() override;
  void applay(Virus &v) override;
  void set_normal_spell() override {
    m_duration_ticks = GameVariables::SLOW_SPELL_DURATION;
  }
};

} // namespace vd

#endif // SLOWSPELL_HPP
