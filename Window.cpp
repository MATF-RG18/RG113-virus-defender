#include "Window.hpp"


namespace vd {

    bool Window::is_on_sides(int x, int y) const {
        return !(x > m_x_region_size && x < m_width - m_x_region_size
        && y > m_y_region_size && y < m_height - m_y_region_size);
    }

}