
#if !defined(MOUSE_MOTION_ACTION_HPP)
#define MOUSE_MOTION_ACTION_HPP

#include "Camera.hpp"
#include "Cursor.hpp"
#include "Window.hpp"
namespace vd {
class PassiveMouseMotionAction {
public:
  PassiveMouseMotionAction(Camera &camera, Window &window, Cursor &cursor)
      : m_camera(camera), m_window(window), m_cursor(cursor) {}

  void on_move(int x, int y);

private:
  Camera &m_camera;
  Window &m_window;
  Cursor &m_cursor;

  void set_camera_movment_direction(int x, int y);
};
} // namespace vd
#endif // MOUSE_MOTION_ACTION_HPP
