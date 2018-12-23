#include "Material.hpp"


namespace vd {

    void Material::set_ambient(GLfloat r, GLfloat g, GLfloat b, GLfloat a){
        m_material_ambient[0] = r;
        m_material_ambient[1] = g;
        m_material_ambient[2] = b;
        m_material_ambient[3] = a;
    }
    void Material::set_diffuse(GLfloat r, GLfloat g, GLfloat b, GLfloat a){
        m_material_diffuse[0] = r;
        m_material_diffuse[1] = g;
        m_material_diffuse[2] = b;
        m_material_diffuse[3] = a;
    }
    void Material::set_specular(GLfloat r, GLfloat g, GLfloat b, GLfloat a){
        m_material_specular[0] = r;
        m_material_specular[1] = g;
        m_material_specular[2] = b;
        m_material_specular[3] = a;
    }
    void Material::set_side(GLenum side)
    {
        m_side = side;
    }
    void Material::set_shininess(GLfloat shininess)
    {
        m_material_shininess = shininess;
    }
    void Material::draw()
    {
        glMaterialfv(m_side, GL_AMBIENT, m_material_ambient);
        glMaterialfv(m_side, GL_DIFFUSE, m_material_diffuse);
        glMaterialfv(m_side, GL_SPECULAR, m_material_specular);
        glMaterialf(m_side, GL_SHININESS, m_material_shininess);
    }

}