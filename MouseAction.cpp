#include "MouseAction.hpp"
#include<iostream>

namespace vd {


void MouseAction::on_left_click_down(int x, int y) {
    m_cursor.cast_spell();
}

}