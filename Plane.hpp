
#if !defined(PLANE_HPP)
#define PLANE_HPP

#include "Material.hpp"
namespace vd {
/*
  Ravan na kojoj se desava igra.
  Plane samo sadrzi metode za crtanje date ravni.
  Sve akcije se odvijaju u GridController klasi

*/
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
