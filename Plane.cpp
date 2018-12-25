#include "Plane.hpp"
#include <cmath>

namespace vd {

Plane::Plane() {
  m_material.set_ambient(0.3, 0.3, 0.2, 1);
  m_material.set_diffuse(0.4, 0.4, 0.8, 1);
  m_material.set_specular(0.1, 0.1, 0.3, 1);
  m_material.set_shininess(10);
  m_material.set_side(GL_FRONT);

  glShadeModel(GL_FLAT);
}

void Plane::init() {
  m_draw_list = glGenLists(1);
  glNewList(m_draw_list, GL_COMPILE);
  m_material.draw();
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
  glEndList();
}
void Plane::draw() {
  glCallList(m_draw_list);
}

}; // namespace vd