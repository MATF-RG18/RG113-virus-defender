#if !defined(SLOWSPELL_HPP)
#define SLOWSPELL_HPP

#include "Spell.hpp"
namespace vd{

class SlowSpell : public Spell {
    public:
        SlowSpell(GLfloat x = 0, GLfloat y=0, GLfloat z=0.1) : Spell(x,y,z,
        360, 2.5) {
            m_color_rgb[0] = 0;
            m_color_rgb[1] = 0.3;
            m_color_rgb[2] = 0.8;
        }
        void draw() override;
        void update() override;
    
};

void draw_slow_spell(GLfloat x, GLfloat y, GLfloat z, 
GLfloat r, GLfloat g, GLfloat b, GLfloat radius);


}

#endif // SLOWSPELL_HPP
