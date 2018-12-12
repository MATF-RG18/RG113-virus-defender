
#if !defined(MOUSE_MOTION_ACTION_HPP)
#define MOUSE_MOTION_ACTION_HPP

#include "Camera.hpp"
#include "Window.hpp"
namespace vd {
class PassiveMouseMotionAction {
    public:
        PassiveMouseMotionAction(Camera &camera, Window& window) : m_camera(camera), m_window(window) {}

        void on_move(int x, int y);
        
    private:
        Camera& m_camera;
        Window& m_window;
        int m_last_x, m_last_y;

        void set_camera_movment_direction(int x, int y);
};
}
#endif // MOUSE_MOTION_ACTION_HPP
