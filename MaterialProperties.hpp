
#if !defined(MATERIALPROPERTIES_HPP)
#define MATERIALPROPERTIES_HPP

#include<GL/glut.h>

class MaterialProperties
{
public:
  void set_ambient(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
  void set_diffuse(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
  void set_specular(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
  void set_shininess(GLfloat shininess);
private:
  GLfloat m_material_ambient[4] = {0};
  GLfloat m_material_diffuse[4] = {0};
  GLfloat m_material_specular[4] = {0};
  GLfloat m_material_shininess{0};
  GLenum m_side{GL_FRONT};
};

#endif // MATERIALPROPERTIES_HPP
