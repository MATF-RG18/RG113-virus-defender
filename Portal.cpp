
#include "Portal.hpp"
#include <GL/glut.h>
#include "Math.hpp"
namespace vd {
void Portal::draw() {
  m_material.draw();
  glPushMatrix();
    glTranslatef(m_xyz[0], m_xyz[1], m_xyz[2]);
    glutSolidSphere(3, 30, 40);
  glPopMatrix();
}
Portal::Portal()
{
  m_xyz[0] = m_xyz[1] = 25; 
  m_material.set_ambient(0.1, 0.1, 0.4, 1);
  m_material.set_diffuse(0.1, 0.1, 0.4, 1);
  m_material.set_specular(0,0,1,1);
  m_material.set_shininess(30);


}
void Portal::update() 
{
  m_animation_parameter += 2;
  
  // m_xyz[2] = 0.5 * sin((double)m_animation_parameter / 180);
}

}  // namespace vd
