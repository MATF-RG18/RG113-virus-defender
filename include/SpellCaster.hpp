
#if !defined(SPELLCASTER_HPP)
#define SPELLCASTER_HPP

#include "DamageSpell.hpp"
#include "GridController.hpp"
#include "SlowSpell.hpp"
#include <GL/glut.h>

namespace vd {

/*
  SpellCaster u zavisnosti od odabranog spell-a
  proverava da li ima dovoljno resursa da se taj spell baci
  i ako ima ubacuje ga u GridController koji
  dalje upravlja njime.
*/

class SpellCaster {

public:
  enum class Spells { DEFAULT = 0, SLOW = 1, DAMAGE = 2 };

  SpellCaster(GridController &grid)
      : m_active_spell(&m_slow_spell), m_grid(grid), m_indicator(Spells::SLOW) {
  }
  // Postavlja aktivni spell
  void set_active_spell(Spells spell) {
    m_indicator = spell;
    if (spell == Spells::SLOW)
      m_active_spell = &m_slow_spell;
    else if (spell == Spells::DAMAGE)
      m_active_spell = &m_damage_spell;
  }
  Spell &get_active_spell() const { return *m_active_spell; }

  void cast_active_spell() {
    // Postavlja se trajanje aktivnog spella
    m_active_spell->set_normal_spell();

    // Ako ima dovoljno mana da se baci slow spell
    // baci ga i oduzmi od ukupno mana koliko kosta spell.
    // Isto za Damage spell
    if (m_indicator == Spells::SLOW &&
        SlowSpell::MANA_WORTH <= GameVariables::MANA) {
      GameVariables::MANA -= SlowSpell::MANA_WORTH;
      m_grid.cast_spell(m_slow_spell);
    } else if (m_indicator == Spells::DAMAGE &&
               DamageSpell::MANA_WORTH <= GameVariables::MANA) {
      GameVariables::MANA -= DamageSpell::MANA_WORTH;
      m_grid.cast_spell(m_damage_spell);
    }
  }
  void cast_active_perma_spell() {
    // Ako ima dovoljno plazme da se baci aktivni spell
    // kao perma spell onda se baca. Ako ne
    // nista se nece desiti
    m_active_spell->set_perma_spell();
    if (m_indicator == Spells::SLOW &&
        SlowSpell::PLASMA_WORTH <= GameVariables::PLASMA) {
      GameVariables::PLASMA -= SlowSpell::PLASMA_WORTH;
      m_grid.cast_spell(m_slow_spell);
    } else if (m_indicator == Spells::DAMAGE &&
               DamageSpell::PLASMA_WORTH <= GameVariables::PLASMA) {
      GameVariables::PLASMA -= DamageSpell::PLASMA_WORTH;
      m_grid.cast_spell(m_damage_spell);
    }
  }
  void set_x(GLfloat x) { m_active_spell->set_x(x); }
  void set_y(GLfloat y) { m_active_spell->set_y(y); }

private:
  SlowSpell m_slow_spell;
  DamageSpell m_damage_spell;
  Spell *m_active_spell;
  GridController &m_grid;
  Spells m_indicator;
};

} // namespace vd

#endif // SPELLCASTER_HPP
