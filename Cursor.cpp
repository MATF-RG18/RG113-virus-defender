#include "Cursor.hpp"
#include<iostream>
#include<cmath>
#include<GL/glut.h>
namespace vd {


void Cursor::move(GLfloat camera_position_x, GLfloat camera_position_y, int center_x,
        int center_y)
        {
            GLfloat dx = m_x_on_screen - center_x;
            GLfloat dy = m_y_on_screen - center_y;

            constexpr GLfloat r_angle = 0.70710678118f;
            
            GLfloat xterm = r_angle*dx;
            GLfloat yterm = r_angle*dy;

            dx = xterm+yterm;
            dy = -xterm + yterm;
        
            dx /= 40;
            dy /= 40;
            m_x_on_plane = camera_position_x + dx;
            m_y_on_plane = camera_position_y + dy;
            
            m_spell_caster.set_x(m_x_on_plane);
            m_spell_caster.set_y(m_y_on_plane);
            // std::cerr << m_x_on_plane << ' ' << m_y_on_plane << '\n';
        }
void Cursor::draw() 
    {
       
        // std::cerr << dx << ' ' << dy << '\n';
        // glPushMatrix();
        //     glColor3f(0,1,0);
        //     glTranslatef(m_x_on_plane, m_y_on_plane, 1);
        //     glCallList(draw_list);
        // glPopMatrix();
        m_spell_caster.get_active_spell().draw();
    }

void Cursor::init() {
    draw_list = glGenLists(1);
    glNewList (draw_list, GL_COMPILE);
        glColor3f (1.0, 0.0, 0.0);
        glutSolidSphere(1, 10, 20);
    glEndList ();
}
}