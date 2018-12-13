#include "Virus.hpp"

#include<cmath>
namespace vd {

void Virus::attack() {
    auto dx = 25 - m_xyz[0];
    auto dy = 25 - m_xyz[1];

    auto norm = sqrt(dx*dx + dy*dy);
    dx /= norm;
    dy /= norm;
    m_move_xyz[0] = dx;
    m_move_xyz[1] = dy;
}

};