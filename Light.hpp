
#if !defined(LIGHT_HPP)
#define LIGHT_HPP

#include <GL/glut.h>

namespace vd {

/*
  Wrapper klasa oko openGL API-a za upravaljnje svetlom

*/

class Light {
public:
  Light(GLenum light_id) : m_light_id(light_id) {}
  void set_ambient(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
  void set_diffuse(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
  void set_specular(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
  void set_id(GLenum id);
  void draw();
  void enable();
  void disable();

private:
  // Inicijalno postavljena na parametre jedinog postojeceg svetla.
  GLfloat m_light_ambient[4] = {0.7, 0.7, 0.7, 1};
  GLfloat m_light_diffuse[4] = {0.7, 0.7, 0.7, 1};
  GLfloat m_light_specular[4] = {0.7, 0.7, 0.7, 1};
  GLfloat m_light_position[4] = {30, 30, 30, 1};
  GLenum m_light_id;
};
} // namespace vd
#endif // LIGHT_HPP
