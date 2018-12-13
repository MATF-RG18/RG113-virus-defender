#include "MouseAction.hpp"
#include<iostream>

namespace vd {


void MouseAction::on_left_click_down() {
    m_cursor.cast_spell();
}
void MouseAction::on_right_click_down() {
    m_cursor.cast_perma_spell();
}

}