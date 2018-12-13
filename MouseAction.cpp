#include "MouseAction.hpp"
#include<iostream>

namespace vd {


void MouseAction::on_left_click_down(int, int) {
    m_cursor.cast_spell();
}

}