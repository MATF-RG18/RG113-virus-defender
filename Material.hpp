
#if !defined(MATERIAL_HPP)
#define MATERIAL_HPP

#include <GL/glut.h>

namespace vd {

    class Material {
        
        public:
            void set_ambient(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
            void set_diffuse(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
            void set_specular(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
            void set_shininess(GLfloat shininess);
            void set_side(GLenum side);
            void draw();

            GLfloat* get_ambient() { return m_material_ambient; }
            GLfloat* get_diffuse() { return m_material_diffuse; }
            GLfloat* get_specular() { return m_material_specular; }
            GLfloat get_shininess() { return m_material_shininess; }

        private:
            GLfloat m_material_ambient[4] = {0};
            GLfloat m_material_diffuse[4] = {0};
            GLfloat m_material_specular[4] = {0};
            GLfloat m_material_shininess {0};
            GLenum m_side {GL_FRONT};
    };
}


#endif // MATERIAL_HPP
