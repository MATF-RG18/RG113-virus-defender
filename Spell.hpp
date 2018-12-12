
#if !defined(SPELLS_HPP)
#define SPELLS_HPP

#include "Virus.hpp"
#include "StrongVirus.hpp"
#include "EvasiveVirus.hpp"
#include "FastVirus.hpp"
#include "GameObject.hpp"
#include<GL/glut.h>
namespace vd{

class Spell : public GameObject {
    public:
        Spell(GLfloat x, GLfloat y, GLfloat z,
        int duration_ticks, GLfloat radius) : GameObject(x,y,z),
        m_duration_ticks(duration_ticks), m_radius(radius) {}
        int get_duration_ticks() const { return m_duration_ticks; }
        void set_x(GLfloat x) { m_xyz[0] = x; }
        void set_y(GLfloat y) { m_xyz[1] = y; }
        void set_z(GLfloat z) { m_xyz[2] = z; } 
    protected:
        int m_duration_ticks;
        GLfloat m_radius;
        GLfloat m_color_rgb[3];
};

}



#endif // SPELLS_HPP
