#include "SlowSpell.hpp"
#include<GL/glut.h>
namespace vd {

void draw_slow_spell(GLfloat x, GLfloat y, GLfloat z, 
GLfloat r, GLfloat g, GLfloat b, GLfloat radius)
{
    glColor3f(r, g, b);
    glLineWidth(3);
    glPushMatrix();
        glTranslatef(x, y, z);
        glScalef(radius, radius, 1);
        glBegin(GL_LINE_STRIP);
            glVertex3f(0,0,z);
            glVertex3f(1,0,z);
            glVertex3f(1,1,z);
            glVertex3f(0,1,z);
            glVertex3f(0,0,z);
        glEnd();

        glBegin(GL_LINE_STRIP);
            glVertex3f(0,0,z);
            glVertex3f(1,0,z);
            glVertex3f(0.5,1,z);
            glVertex3f(0,0,z);
        glEnd();

    glPopMatrix();
}

void SlowSpell::applay(Virus& v) 
{
    v.set_speed(v.get_speed() * 0.7);
}

void SlowSpell::draw()
{
    draw_slow_spell(m_xyz[0], m_xyz[1], m_xyz[2],
    m_color_rgb[0], m_color_rgb[1], m_color_rgb[2], m_radius);
}

void SlowSpell::update()
{
    if (!is_active())
        return;

    if (m_duration_ticks >= 0) {
        --m_duration_ticks;
    } else {
        deactivate();
    }
}

};