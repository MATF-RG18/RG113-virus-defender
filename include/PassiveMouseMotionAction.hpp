
#if !defined(MOUSE_MOTION_ACTION_HPP)
#define MOUSE_MOTION_ACTION_HPP

#include "Camera.hpp"
#include "Cursor.hpp"
#include "Window.hpp"
namespace vd {
/*
  Regisutrije pasivan pokret misa

*/
class PassiveMouseMotionAction {
public:
  PassiveMouseMotionAction(Cursor &cursor) : m_cursor(cursor) {}

  // Kada se mis pomeri na ekranu
  // poziva metode cursora da postavi
  // poziciju na ravni igre
  void on_move(int x, int y);

private:
  Cursor &m_cursor;
};
} // namespace vd
#endif // MOUSE_MOTION_ACTION_HPP
