
#if !defined(FASTVIRUS_HPP)
#define FASTVIRUS_HPP
#include "Virus.hpp"
#include "MaterialProperties.hpp"
#include <GL/glut.h>
namespace vd {
class FastVirus : public Virus {
public:
  FastVirus(GLfloat x = 0, GLfloat y = 0, GLfloat z = RADIUS);
  void draw() override;
  void update() override;
  static void init();
  static constexpr GLfloat HP{400};
  static constexpr GLfloat RADIUS{0.2};
  static constexpr GLfloat SPEED{0.08};

private:
  static MaterialProperties m_material_prop;
  static GLuint m_draw_list;
  static Material m_material;

};
} // namespace vd

#endif // FASTVIRUS_HPP
