#include "SlowSpell.hpp"
#include<GL/glut.h>
namespace vd {


void SlowSpell::applay(Virus& v) 
{
    v.set_speed(v.get_speed() * 0.7);
}

void SlowSpell::draw()
{
    glColor3f(m_color_rgb[0], m_color_rgb[1], m_color_rgb[2]);
    glLineWidth(3);
    glPushMatrix();
        glTranslatef(m_xyz[0], m_xyz[1], m_xyz[2]);
        glScalef(2*m_radius, 2*m_radius, 1);
        glBegin(GL_LINE_STRIP);
            glVertex3f(-0.5,-0.5, m_xyz[2]);
            glVertex3f(0.5,-0.5,m_xyz[2]);
            glVertex3f(0.5,0.5,m_xyz[2]);
            glVertex3f(-0.5,0.5,m_xyz[2]);
            glVertex3f(-0.5,-0.5,m_xyz[2]);
        glEnd();

        glBegin(GL_LINE_STRIP);
            glVertex3f(0.5,-0.5,m_xyz[2]);
            glVertex3f(0, 0.5,m_xyz[2]);
            glVertex3f(-0.5,-0.5,m_xyz[2]);
        glEnd();

    glPopMatrix();
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