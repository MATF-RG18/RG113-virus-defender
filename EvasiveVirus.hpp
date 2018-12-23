
#if !defined(EVASIVEVIRUS_HPP)
#define EVASIVEVIRUS_HPP

#include "Virus.hpp"

namespace vd {
class EvasiveVirus : public Virus {
public:
  EvasiveVirus(GLfloat x = 0, GLfloat y = 0, GLfloat z = RADIUS);
     
  void draw() override;
  void update() override;

  static constexpr GLfloat HP{100};
  static constexpr GLfloat RADIUS{0.2};
  static constexpr GLfloat SPEED{0.01};

private:
};
} // namespace vd

#endif // EVASIVEVIRUS_HPP
