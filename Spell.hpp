
#if !defined(SPELLS_HPP)
#define SPELLS_HPP

#include "EvasiveVirus.hpp"
#include "FastVirus.hpp"
#include "GameObject.hpp"
#include "Material.hpp"
#include "StrongVirus.hpp"
#include "Virus.hpp"
#include <GL/glut.h>
namespace vd {

class Spell : public GameObject {
public:
  Spell(GLfloat x, GLfloat y, GLfloat z, long long duration_ticks,
        GLfloat radius)
      : GameObject(x, y, z), m_duration_ticks(duration_ticks),
        m_radius(radius) {
    m_xyz[2] = 0.02;
  }

  long long get_duration_ticks() const { return m_duration_ticks; }
  void set_x(GLfloat x) { m_xyz[0] = x; }
  void set_y(GLfloat y) { m_xyz[1] = y; }
  void set_z(GLfloat z) { m_xyz[2] = z; }

  GLfloat get_x() const { return m_xyz[0]; }
  GLfloat get_y() const { return m_xyz[1]; }
  GLfloat get_z() const { return m_xyz[2]; }
  GLfloat get_radius() const { return m_radius; }
  virtual void applay(Virus &v) = 0;
  virtual void set_normal_spell() = 0;
  void set_perma_spell() { m_duration_ticks = GameVariables::INF_TIME_TICKS; }

protected:
  long long m_duration_ticks;
  GLfloat m_radius;
  GLfloat m_color_rgb[3];
  Material m_material;
};

} // namespace vd

#endif // SPELLS_HPP
