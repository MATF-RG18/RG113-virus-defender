#include "PassiveMouseMotionAction.hpp"
#include <GL/glut.h>
#include <cmath>
#include <iostream>
namespace vd {

void PassiveMouseMotionAction::on_move(int x, int y) {
  m_cursor.set_on_screen_x(x);
  m_cursor.set_on_screen_y(y);
  
}
} // namespace vd