#include "DamageSpell.hpp"
#include<GL/glut.h>


namespace vd {

void DamageSpell::draw()
{
    glColor3f(m_color_rgb[0], m_color_rgb[1], m_color_rgb[2]);
    glLineWidth(3);
    glPushMatrix();
        glTranslatef(m_xyz[0], m_xyz[1], m_xyz[2]);
        glScalef(m_radius, m_radius, 1);
        glBegin(GL_LINE_STRIP);
            glVertex3f(0,0,m_xyz[2]);
            glVertex3f(1,0,m_xyz[2]);
            glVertex3f(1,1,m_xyz[2]);
            glVertex3f(0,1,m_xyz[2]);
            glVertex3f(0,0,m_xyz[2]);
        glEnd();

        glBegin(GL_LINE_STRIP);
            glVertex3f(0.5,0,m_xyz[2]);
            glVertex3f(1,0.5,m_xyz[2]);
            glVertex3f(0.5,1,m_xyz[2]);
            glVertex3f(0,0.5,m_xyz[2]);
            glVertex3f(0.5,0,m_xyz[2]);
        glEnd();

    glPopMatrix();
}
void DamageSpell::applay(Virus &v)
{
    v.set_hp(v.get_hp() - m_damage_per_tick);
}

void DamageSpell::update()
{
    if (!is_active())
        return;

    if (m_duration_ticks >= 0) {
        --m_duration_ticks;
    }
    else {
        deactivate();
    }
}



}