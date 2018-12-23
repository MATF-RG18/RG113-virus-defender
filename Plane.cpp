#include "Plane.hpp"
#include<cmath>

namespace vd {

    Plane::Plane()
    {
        m_material.set_ambient(0.9,0.9,0.9,1);
        m_material.set_diffuse(0,0,0.1,1);
        m_material.set_specular(0,0,0,0);
        m_material.set_shininess(1);
        m_material.set_side(GL_FRONT);
        
        // m_draw_list = glGenLists(1);

        // glNewList(m_draw_list, GL_COMPILE);
        //     for (float y = 0; y < 50; y += 0.5) {
        //         glBegin(GL_TRIANGLE_STRIP);
        //         for (float x = 0; x < 50; x += 0.5) {
        //             glNormal3f(0,0,1);
        //             glVertex3f(x,y,0);

        //             glNormal3f(0,0,1);
        //             glVertex3f(x, y + 0.5, 0);
        //         }
        //         glEnd();
        //     }
        // glEndList();
        
        glShadeModel(GL_FLAT);
    }
    void Plane::draw()
    {
        m_material.draw();
        // glCallList(m_draw_list);
        // glBegin(GL_POLYGON);
        // glVertex3f(0, 0, 0);
        // glVertex3f(0, 50, 0);
        // glVertex3f(50, 50, 0);
        // glVertex3f(50, 0, 0);
        // glEnd();
        for (float y = 0; y < 50; y += 0.5) {
            glBegin(GL_TRIANGLE_STRIP);
            for (float x = 0; x < 50; x += 0.5) {
                glNormal3f(0,0,1);
                glVertex3f(x,y,0);

                glNormal3f(0,0,1);
                glVertex3f(x, y + 0.5, 0);
            }
            glEnd();
        }
    }

};