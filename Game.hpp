#ifndef GAME_HPP
#define GAME_HPP

#include<vector>
#include "Virus.hpp"
#include "Portal.hpp"
#include "Camera.hpp"
#include "KeyboardAction.hpp"
#include "PassiveMouseMotionAction.hpp"
#include "Window.hpp"
#include "Cursor.hpp"
#include "SpellCaster.hpp"
#include "StrongVirus.hpp"
#include "SlowSpell.hpp"
#include "Timer.hpp"
#include "MouseAction.hpp"
#include "GameVariables.hpp"
#include "Stats.hpp"
namespace vd{
class Game {
public:
    Game();
    void init();
    
    void update();
    void draw();
    
    void test() { std::cerr << "hello world";}
    int get_msec_timer_update() const { return m_msec_update;}
    int get_timer_id() const { return m_timer_id; }
    Timer& timer() { return m_timer; }
    Window& window() { return m_window; }
    KeyboardAction& keyboard() { return m_keyboard_action; }
    PassiveMouseMotionAction& passive_mouse() { return m_passive_mouse_motion_action; }
    MouseAction& mouse_action() { return m_mouse_action; }
    bool not_over() { return GameVariables::PORTAL_HP > 0; }

private:
    const int m_msec_update = 13;
    const int m_timer_id = 1;
    GridController m_grid_controller;
    Window& m_window {GameVariables::window};
    Camera m_camera;
    SpellCaster m_spell_caster;
    KeyboardAction m_keyboard_action;
    Cursor m_cursor;
    Timer m_timer{13, 1};
    PassiveMouseMotionAction m_passive_mouse_motion_action;
    MouseAction m_mouse_action;
    Stats stats;
  
    
};
}


#endif //GAME_HPP
