#include "GridController.hpp"
#include "GameVariables.hpp"

namespace vd {

GridController::GridController() {
  for (float x = 0; x < GameVariables::GRID_X_SIZE; x += 6) {
    m_strong_virus_factories.emplace_back(x, 0, StrongVirus::RADIUS);
    m_evasive_virus_factories.emplace_back(x + 0.1, 0.2, EvasiveVirus::RADIUS);
    m_fast_virus_factories.emplace_back(x + 0.5, 0.7, FastVirus::RADIUS);
  }

  for (float x = 0; x < GameVariables::GRID_X_SIZE; x += 6) {
    m_strong_virus_factories.emplace_back(x, 50, StrongVirus::RADIUS);
    m_evasive_virus_factories.emplace_back(x + 0.1, 50 - 0.2,
                                           EvasiveVirus::RADIUS);
    m_fast_virus_factories.emplace_back(x + 0.5, 50 - 0.7, FastVirus::RADIUS);
  }

  for (float y = 0; y < GameVariables::GRID_Y_SIZE; y += 6) {
    m_strong_virus_factories.emplace_back(0, y, StrongVirus::RADIUS);
    m_evasive_virus_factories.emplace_back(0.1, y, EvasiveVirus::RADIUS);
    m_fast_virus_factories.emplace_back(0.5, y, FastVirus::RADIUS);
  }

  for (float y = 0; y < GameVariables::GRID_X_SIZE; y += 6) {
    m_strong_virus_factories.emplace_back(50, y, StrongVirus::RADIUS);
    m_evasive_virus_factories.emplace_back(50 - 0.9, y, EvasiveVirus::RADIUS);
    m_fast_virus_factories.emplace_back(50 - 0.3, y, FastVirus::RADIUS);
  }

  m_strong_virus_factories.front().activate();
  m_strong_virus_factories.back().activate();

  m_evasive_virus_factories.front().activate();
  m_evasive_virus_factories.back().activate();

  m_fast_virus_factories.front().activate();
  m_fast_virus_factories.back().activate();
}


void GridController::applay_spells() {
  for (auto &s : m_damage_spells) {
    if (s.is_active()) {
      for (auto &v : m_strong_viruses) {
        if (v.is_active() && colides(s, v))
          s.applay(v);
      }
      for (auto &v : m_evasive_viruses) {
        if (v.is_active() && colides(s, v))
          s.applay(v);
      }
      for (auto &v : m_fast_viruses) {
        if (v.is_active() && colides(s, v))
          s.applay(v);
      }
    }
  }

  for (auto &s : m_slow_spells) {
    if (s.is_active()) {
      for (auto &v : m_strong_viruses) {
        if (v.is_active() && colides(s, v)) {
          s.applay(v);
        }
      }
      for (auto &v : m_fast_viruses) {
        if (v.is_active() && colides(s, v))
          s.applay(v);
      }
    }
  }
}
void GridController::update_viruses() {
  m_strong_viruses.update();
  m_evasive_viruses.update();
  m_fast_viruses.update();

  for (auto &f : m_strong_viruses) {
    if (f.is_active() && colides(f, m_portal)) {
      m_portal.take_damage(f.get_hp());
      f.deactivate();
    }
  }
  for (auto &f : m_fast_viruses) {
    if (f.is_active() && colides(f, m_portal)) {
      m_portal.take_damage(f.get_hp());
      f.deactivate();
    }
  }
  for (auto &f : m_evasive_viruses) {
    if (f.is_active() && colides(f, m_portal)) {
      m_portal.take_damage(f.get_hp());
      f.deactivate();
    }
  }
}

void GridController::update_factories() {
  for (auto &f : m_strong_virus_factories) {
    f.update();
  }
  for (auto &f : m_evasive_virus_factories) {
    f.update();
  }
  for (auto &f : m_fast_virus_factories) {
    f.update();
  }

  for (auto &f : m_strong_virus_factories) {
    if (f.ready())
      m_strong_viruses.insert(f.get());
  }
  for (auto &f : m_evasive_virus_factories) {
    if (f.ready())
      m_evasive_viruses.insert(f.get());
  }
  for (auto &f : m_fast_virus_factories) {
    if (f.ready())
      m_fast_viruses.insert(f.get());
  }
}
void GridController::update() {
  m_damage_spells.update();
  m_slow_spells.update();

  applay_spells();
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

} // namespace vd