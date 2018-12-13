#include "GridController.hpp"

namespace vd {

GridController::GridController()
{
    // m_strong_virus_factories.emplace_back(3, 34, 34, 0.1);
    // m_evasive_virus_factories.emplace_back(3, 15, 15, 0.1);
    m_fast_virus_factories.emplace_back(3, 42, 5, 0.1);
}

void GridController::applay_spells()
{

}
void GridController::update_viruses()
{
    m_strong_viruses.update();
    m_evasive_viruses.update();
    m_fast_viruses.update();

    for (auto &f: m_strong_viruses) {
        if (f.is_active() && f.colides_with(m_portal)) {
            m_portal.take_damage(f.get_hp());
            f.deactivate();
        }
    }
    for (auto &f: m_fast_viruses) {
        if (f.is_active() && f.colides_with(m_portal)) {
            m_portal.take_damage(f.get_hp());
            f.deactivate();
        }
    }
    for (auto &f: m_evasive_viruses) {
        if (f.is_active() && f.colides_with(m_portal)) {
            m_portal.take_damage(f.get_hp());
            f.deactivate();
        }
    }

}



void GridController::update_factories()
{
    for (auto& f : m_strong_virus_factories) {
        f.update();
    }
    for (auto& f : m_evasive_virus_factories) {
        f.update();
    }
    for (auto& f : m_fast_virus_factories) {
        f.update();
    }
    
    for (auto& f : m_strong_virus_factories) {
        if (f.ready())
            m_strong_viruses.insert(f.get());
    }
    for (auto& f : m_evasive_virus_factories) {
        if (f.ready())
            m_evasive_viruses.insert(f.get());
    }
    for (auto& f : m_fast_virus_factories) {
        if (f.ready())
            m_fast_viruses.insert(f.get());
    }
}



void GridController::update() {
    m_damage_spells.update();
    m_slow_spells.update();


    update_viruses();

    update_factories();
    m_portal.update();
}

void GridController::draw() {
    m_damage_spells.draw();
    m_slow_spells.draw();
    m_strong_viruses.draw();
    m_evasive_viruses.draw();
    m_fast_viruses.draw();
    m_portal.draw();
}


}