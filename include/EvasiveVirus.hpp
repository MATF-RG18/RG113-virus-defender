
#if !defined(EVASIVEVIRUS_HPP)
#define EVASIVEVIRUS_HPP

#include "Virus.hpp"
namespace vd {
class EvasiveVirus : public Virus {
public:
  EvasiveVirus(GLfloat x = 0, GLfloat y = 0, GLfloat z = RADIUS);

  void draw() override;
  void update() override;

  static void init();
  static constexpr GLfloat HP{500};
  static constexpr GLfloat RADIUS{0.2};
  static constexpr GLfloat SPEED{0.07};

private:
  static GLuint m_draw_list;
  static Material m_material;
};
} // namespace vd

#endif // EVASIVEVIRUS_HPP
