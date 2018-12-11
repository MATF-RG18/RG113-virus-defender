
#if !defined(MOUSE_MOTION_ACTION_HPP)
#define MOUSE_MOTION_ACTION_HPP

#include "Camera.hpp"

namespace vd {
class PassiveMouseMotionAction {
    public:
        PassiveMouseMotionAction(Camera &camera) : m_camera(camera) {}

        void operator()(int x, int y);
        
    private:
        Camera& m_camera;
};
}
#endif // MOUSE_MOTION_ACTION_HPP
