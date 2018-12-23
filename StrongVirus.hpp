
#if !defined(STRONGVIRUS_HPP)
#define STRONGVIRUS_HPP

#include "Virus.hpp"

namespace vd {
class StrongVirus : public Virus {
public:
  StrongVirus(GLfloat x = 0, GLfloat y = 0, GLfloat z = RADIUS);
     
  void draw() override;
  void update() override;

  static constexpr GLfloat HP{1000};
  static constexpr GLfloat RADIUS{0.3};
  static constexpr GLfloat SPEED{0.02};

private:
};
} // namespace vd

#endif // STRONGVIRUS_HPP
