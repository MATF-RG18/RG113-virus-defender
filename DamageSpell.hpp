
#if !defined(DAMAGESPELL_HPP)
#define DAMAGESPELL_HPP

#include "Virus.hpp"
#include "Spell.hpp"
namespace vd{

class DamageSpell : public Spell {
    public:
        DamageSpell(GLfloat x = 0, GLfloat y=0, GLfloat z=0) : Spell(x,y,z,
        GameVariables::DAMAGE_SPELL_DURATION, 1.25) {
            m_color_rgb[0] = 1;
            m_color_rgb[1] = 0.3;
            m_color_rgb[2] = 0;
        }
        void draw() override;
        void update() override;
        void applay(Virus &v) override;
        void set_normal_spell() override { m_duration_ticks = GameVariables::DAMAGE_SPELL_DURATION; }
    private:
        constexpr static GLfloat m_damage_per_tick{ 25};
};


}


#endif // DAMAGESPELL_HPP
