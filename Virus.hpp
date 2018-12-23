

#if !defined(VIRUS_HPP)
#define VIRUS_HPP

#include "GameObject.hpp"
#include "Math.hpp"
#include "Portal.hpp"
#include "Material.hpp"
namespace vd {
class Virus : public GameObject {
public:
  Virus(GLfloat x, GLfloat y, GLfloat z) : GameObject(x, y, z) { attack(); }

  GLfloat get_hp() const { return m_hp; }
  GLfloat get_speed() const { return m_speed; }

  void set_hp(GLfloat hp) { m_hp = hp; }
  void set_speed(GLfloat speed) { m_speed = speed; }
  void set_color(GLfloat r, GLfloat g, GLfloat b) {
    m_color_rgb[0] = r;
    m_color_rgb[1] = g;
    m_color_rgb[2] = b;
  }
  void attack();
  void reset_speed() { m_speed = 1; }
  void update() override;

protected:
  GLfloat m_hp;
  GLfloat m_speed;
  GLfloat m_radius_size;
  GLfloat m_move_xyz[3];
  GLfloat m_color_rgb[3];
  Virus(GLfloat x, GLfloat y, GLfloat z, GLfloat hp, GLfloat speed,
        GLfloat radius_size)
      : GameObject(x, y, z), m_hp(hp), m_speed(speed),
        m_radius_size(radius_size) {
    attack();
  }
  Material m_material;
};
} // namespace vd

#endif // VIRUS_HPP
