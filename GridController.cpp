#include "GridController.hpp"

namespace vd {

GridController::GridController() 
{

}


void GridController::update() {
    m_damage_spells.update();
    m_slow_spells.update();
}

void GridController::draw() {
    m_damage_spells.draw();
    m_slow_spells.draw();
}


}