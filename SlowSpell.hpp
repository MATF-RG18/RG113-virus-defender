#if !defined(SLOWSPELL_HPP)
#define SLOWSPELL_HPP
#include "GameVariables.hpp"
#include "MaterialProperties.hpp"
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
  static void init();

private:
  static GLuint m_draw_list;
  static Material m_material;
  static constexpr GLfloat RADIUS = 1.25;
};

} // namespace vd

#endif // SLOWSPELL_HPP
