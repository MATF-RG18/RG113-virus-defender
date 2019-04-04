
#if !defined(MATH_HPP)
#define MATH_HPP

#include <GL/glut.h>
#include <array>
#include <cmath>
namespace vd {
/*
  Pomocna math klasa za matematicka izracunavanja

*/
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

  static GLfloat sin(int deg) { return m_sin[deg % 360]; }
  static GLfloat cos(int deg) { return m_cos[deg % 360]; }

private:
  // Tabelirana sin i cos funkcije u stepenima
  const static std::array<GLfloat, 360> m_sin;
  const static std::array<GLfloat, 360> m_cos;
};

} // namespace vd

#endif // MATH_HPP
