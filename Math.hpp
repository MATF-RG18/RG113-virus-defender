
#if !defined(MATH_HPP)
#define MATH_HPP

#include <GL/glut.h>
#include <cmath>

namespace vd {

class Math {
public:
  static GLfloat distance(GLfloat ax, GLfloat ay, GLfloat az, GLfloat bx,
                          GLfloat by, GLfloat bz) {
    return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by) +
                (az - bz) * (az - bz));
  }
  static GLfloat distance(GLfloat ax, GLfloat ay, GLfloat bx, GLfloat by) {
    return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
  }
  constexpr static double PI = 3.14159265359;
};

} // namespace vd

#endif // MATH_HPP
