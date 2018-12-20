#if !defined(SLOWSPELL_HPP)
#define SLOWSPELL_HPP
#include "GameVariables.hpp"
#include "Spell.hpp"
namespace vd{

class SlowSpell : public Spell {
    public:
        SlowSpell(GLfloat x = 0, GLfloat y=0, GLfloat z=0.1) : Spell(x,y,z,
        GameVariables::SLOW_SPELL_DURATION, 1.25) {
            m_color_rgb[0] = 0;
            m_color_rgb[1] = 0.3;
            m_color_rgb[2] = 0.8;
        }
        void draw() override;
        void update() override;
        void applay(Virus& v) override;
        void set_normal_spell() override { m_duration_ticks = GameVariables::SLOW_SPELL_DURATION; }
    
};


}

#endif // SLOWSPELL_HPP
