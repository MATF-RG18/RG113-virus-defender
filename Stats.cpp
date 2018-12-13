#include "Stats.hpp"
#include "GameVariables.hpp"
#include<GL/freeglut.h>
namespace vd {

    void Stats::update() {

        m_mana_string = std::to_string(GameVariables::MANA);
        m_plasma_string = std::to_string(GameVariables::PLASMA);
        m_portal_hp_string = std::to_string(GameVariables::PORTAL_HP);
    }
    void Stats::draw() {
       
    }
}