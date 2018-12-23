#include "Light.hpp"


namespace vd {

    void Light::draw() 
    {
        glLightfv(m_light_id, GL_POSITION, m_light_position);
        glLightfv(m_light_id, GL_AMBIENT, m_light_ambient);
        glLightfv(m_light_id, GL_DIFFUSE, m_light_diffuse);
        glLightfv(m_light_id, GL_SPECULAR, m_light_specular);
    }

    void Light::set_ambient(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
    {
        m_light_ambient[0] = r;
        m_light_ambient[1] = g;
        m_light_ambient[2] = b;
        m_light_ambient[3] = a;
    }
    void Light::set_diffuse(GLfloat r, GLfloat g, GLfloat b, GLfloat a){
        m_light_diffuse[0] = r;
        m_light_diffuse[1] = g;
        m_light_diffuse[2] = b;
        m_light_diffuse[3] = a;
    }
    void Light::set_specular(GLfloat r, GLfloat g, GLfloat b, GLfloat a){
        m_light_specular[0] = r;
        m_light_specular[1] = g;
        m_light_specular[2] = b;
        
        m_light_specular[3] = a;
    }
    void Light::set_id(GLenum id)
    {
        m_light_id = id;
    }
    void Light::enable()
    {
        glEnable(m_light_id);    
    }
    void Light::disable()
    {
        glDisable(m_light_id);    
    }
}