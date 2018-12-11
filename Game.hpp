#ifndef GAME_HPP
#define GAME_HPP

#include<vector>
#include "Virus.hpp"
#include "Portal.hpp"
#include "Camera.hpp"
#include "KeyboardAction.hpp"
#include "PassiveMouseMotionAction.hpp"
#include "Window.hpp"
namespace vd{
class Game {
public:
    Game();
    void init();
    void update();
    void draw();
    void set_keyboard_input(unsigned char key, int x, int y);
    void set_passive_mouse_motion_input(int x, int y);
    int get_msec_timer_update() const { return m_msec_update;}
    int get_timer_id() const { return m_timer_id; }
    Window& window() { return m_window; }
private:
    const int m_msec_update = 11;
    const int m_timer_id = 1;
    Window m_window{1024, 768};
    Camera m_camera;
    KeyboardAction m_keyboard_action;
    PassiveMouseMotionAction m_passive_mouse_motion_action;
    
};
}


#endif //GAME_HPP
