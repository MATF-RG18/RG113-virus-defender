
#if !defined(DAMAGESPELL_HPP)
#define DAMAGESPELL_HPP


#include "Spell.hpp"
namespace vd{

class DamageSpell : public Spell {
    public:
        DamageSpell(GLfloat x = 0, GLfloat y=0, GLfloat z=0.1) : Spell(x,y,z,
        3500, 1.8) {
            m_color_rgb[0] = 1;
            m_color_rgb[1] = 0.3;
            m_color_rgb[2] = 0;
        }
        void draw() override;
        void update() override;
};

}


#endif // DAMAGESPELL_HPP
