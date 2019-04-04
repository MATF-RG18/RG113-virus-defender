#if !defined(SLOWSPELL_HPP)
#define SLOWSPELL_HPP
#include "GameVariables.hpp"

#include "Spell.hpp"
namespace vd {
/*
  Spell koji usporava viruse kada se
  nadju u njemu
*/
class SlowSpell : public Spell {
public:
  SlowSpell(GLfloat x = 0, GLfloat y = 0, GLfloat z = 0.01);

  void draw() override;
  void update() override;

  void applay(Virus &v) override;
  void set_normal_spell() override { m_duration_ticks = TICK_DURATION; }
  static void init();
  static constexpr int PLASMA_WORTH = 250;
  static constexpr int MANA_WORTH = 50;

private:
  static GLuint m_draw_list;
  static Material m_material;
  static constexpr GLfloat RADIUS = 1.25;
  static constexpr int TICK_DURATION = 250;
};

} // namespace vd

#endif // SLOWSPELL_HPP
