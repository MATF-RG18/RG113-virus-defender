
#if !defined(MATH_HPP)
#define MATH_HPP

#include<GL/glut.h>
#include<cmath>

namespace vd {

struct vec3 {
    GLfloat x,y,z;
};
class Math {
    public:
        static GLfloat distance(vec3 a, vec3 b) {
            return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z));
        }
        static GLfloat distance(GLfloat ax, GLfloat ay, GLfloat az, GLfloat bx, GLfloat by, GLfloat bz) {
            return sqrt( (ax-bx)*(ax-bx) + (ay-by)*(ay-by) + (az-bz)*(az-bz));
        }
        static vec3 normalized(vec3 a) {
            vec3 b;
            return b; // todo
        }      
};

}


#endif // MATH_HPP
