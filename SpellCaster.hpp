
#if !defined(SPELLCASTER_HPP)
#define SPELLCASTER_HPP

#include "SlowSpell.hpp"
#include "DamageSpell.hpp"
#include "GridController.hpp"
#include<GL/glut.h>

namespace vd {

class SpellCaster {

    public:
        enum class Spells {
            DEFAULT = 0, SLOW = 1, DAMAGE = 2
        };
        
        SpellCaster(GridController& grid) : m_active_spell(&m_slow_spell), m_grid(grid), m_indicator(Spells::SLOW){}
        void set_active_spell(Spells spell) { 
            m_indicator = spell;
            if (spell == Spells::SLOW)
                m_active_spell = &m_slow_spell;
            else if (spell == Spells::DAMAGE)
                m_active_spell = &m_damage_spell;
        }
        Spell& get_active_spell() const { return *m_active_spell; }

        void cast_active_spell() {
            if (GameVariables::MANA >= GameVariables::SPELL_MANA_WORTH) {
                m_active_spell->set_normal_spell();
                if (m_indicator == Spells::SLOW) {
                    m_grid.cast_spell(m_slow_spell);
                } else if (m_indicator == Spells::DAMAGE) {
                    m_grid.cast_spell(m_damage_spell);
                }
                GameVariables::MANA -= GameVariables::SPELL_MANA_WORTH;
            }
            
        }
        void cast_active_perma_spell() {
            if (GameVariables::PERMA_SPELL_WORTH <= GameVariables::PLASMA
                && GameVariables::MANA >= GameVariables::SPELL_MANA_WORTH) {
                m_active_spell->set_perma_spell();
                GameVariables::PLASMA -= GameVariables::PERMA_SPELL_WORTH;
                if (m_indicator == Spells::SLOW) {
                    m_grid.cast_spell(m_slow_spell);
                } else if (m_indicator == Spells::DAMAGE) {
                    m_grid.cast_spell(m_damage_spell);
                }
                GameVariables::MANA -= GameVariables::SPELL_MANA_WORTH;                
            }
            
        }
        void set_x(GLfloat x) {m_active_spell->set_x(x); }
        void set_y(GLfloat y) {m_active_spell->set_y(y); }
    private:
        SlowSpell m_slow_spell;
        DamageSpell m_damage_spell;
        Spell* m_active_spell;
        GridController& m_grid;
        Spells m_indicator;
};



}


#endif // SPELLCASTER_HPP
