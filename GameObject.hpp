

#if !defined(GAMEOBJECT_HPP)
#define GAMEOBJECT_HPP
#include<iostream>
#include<GL/glut.h>
namespace vd {
class GameObject {
    public:
        GameObject() = default;
        GameObject(GLfloat x, GLfloat y, GLfloat z) : m_xyz{x,y,z} {};
        virtual void update() = 0;
        virtual void draw() = 0;
        virtual ~GameObject() = default;
        void activate() { m_active = true;}
        bool is_active() { return m_active; }
        void deactivate() { m_active = false; }
    protected:
        GLfloat m_xyz[3];
        
    private:
        bool m_active = false;
};

}

#endif // GAMEOBJECT_HPP
