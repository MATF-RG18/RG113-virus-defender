
#if !defined(SPELLCASTER_HPP)
#define SPELLCASTER_HPP

#include "SlowSpell.hpp"
#include "DamageSpell.hpp"
#include<GL/glut.h>

namespace vd {

class SpellCaster {

    public:
        enum class Spells {
            DEFAULT = 0, SLOW = 1, DAMAGE = 2
        };
        SpellCaster() : m_active_spell(&m_slow_spell){}
        void set_active_spell(Spells spell) { 
            if (spell == Spells::SLOW)
                m_active_spell = &m_slow_spell;
            else if (spell == Spells::DAMAGE)
                m_active_spell = &m_damage_spell;
        }
        Spell& get_active_spell() const { return *m_active_spell; }

        void set_x(GLfloat x) {m_active_spell->set_x(x); }
        void set_y(GLfloat y) {m_active_spell->set_y(y); }
    private:
        SlowSpell m_slow_spell;
        DamageSpell m_damage_spell;
        Spell* m_active_spell;
};



}


#endif // SPELLCASTER_HPP
