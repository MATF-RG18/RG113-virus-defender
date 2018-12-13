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
        // std::cerr << x << ' ' << y << ' ' << m_window.is_on_sides(x,y) << '\n';
        
    }
    void PassiveMouseMotionAction::set_camera_movment_direction(int x, int y) {
        
        // if (m_window.is_on_sides(x,y)) {
        //     x = x - m_window.get_center_x();
        //     y = y - m_window.get_center_y();
        //     constexpr GLfloat r_angle = 0.70710678118f;
        
        //     GLfloat xterm = r_angle*x;
        //     GLfloat yterm = r_angle*y;

        //     GLfloat nx = xterm+yterm;
        //     GLfloat ny = -xterm + yterm;
        //     GLfloat norm = sqrt(nx*nx +ny*ny) *2;
        //     nx /= norm;
        //     ny /= norm;
         
        //     m_camera.set_move_direction(nx, ny);
        //     // std::cerr << "(" << nx << ',' << ny << ')' << '\n';


        // } else {
        //     m_camera.stop_moving();
        // }
    }



}