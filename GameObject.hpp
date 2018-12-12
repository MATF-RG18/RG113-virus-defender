

#if !defined(GAMEOBJECT_HPP)
#define GAMEOBJECT_HPP
#include<GL/glut.h>
namespace vd {
class GameObject {
    public:
        GameObject() = default;
        GameObject(GLfloat x, GLfloat y, GLfloat z) : m_xyz{x,y,z} {};
        virtual void update() = 0;
        virtual void draw() = 0;
        virtual ~GameObject() = default;
    protected:
        GLfloat m_xyz[3];
};

}

#endif // GAMEOBJECT_HPP
