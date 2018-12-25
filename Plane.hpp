
#if !defined(PLANE_HPP)
#define PLANE_HPP

#include "Material.hpp"
namespace vd {

class Plane {
public:
  Plane();
  void init();
  void draw();

private:
  Material m_material;
  GLuint m_draw_list;
};
} // namespace vd

#endif // PLANE_HPP
