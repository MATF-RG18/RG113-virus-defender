#include "PassiveMouseMotionAction.hpp"
#include<iostream>
#include<cmath>
#include<GL/glut.h>
namespace vd {

    void PassiveMouseMotionAction::on_move(int x, int y) {
        m_last_x = x;
        m_last_y = y;
        m_cursor.set_on_screen_x(x);
        m_cursor.set_on_screen_y(y);
        // std::cerr << x << ' ' << y << ' ' << m_window.is_on_sides(x,y) << '\n'
    }
}