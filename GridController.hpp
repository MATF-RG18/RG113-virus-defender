
#if !defined(GRIDCONTROLLER_HPP)
#define GRIDCONTROLLER_HPP

#include "DamageSpell.hpp"
#include "EvasiveVirus.hpp"
#include "FastVirus.hpp"
#include "GameObjectContainer.hpp"
#include "Portal.hpp"
#include "SlowSpell.hpp"
#include "Spell.hpp"
#include "StrongVirus.hpp"
#include "Virus.hpp"
#include "VirusFactory.hpp"
#include <memory>
#include <random>
namespace vd {

class GridController {

public:
  GridController();
  void cast_spell(const SlowSpell &spell) { m_slow_spells.insert(spell); }
  void cast_spell(const DamageSpell &spell) { m_damage_spells.insert(spell); }
  void update();
  void draw();
  void init();

private:
  static constexpr int MAX_VIRUSES = 150;
  static constexpr int MAX_ACTIVE_SPELLS = 200;

  GameObjectContainer<SlowSpell, MAX_ACTIVE_SPELLS> m_slow_spells;
  GameObjectContainer<DamageSpell, MAX_ACTIVE_SPELLS> m_damage_spells;
  GameObjectContainer<StrongVirus, MAX_VIRUSES> m_strong_viruses;
  GameObjectContainer<FastVirus, MAX_VIRUSES> m_fast_viruses;
  GameObjectContainer<EvasiveVirus, MAX_VIRUSES> m_evasive_viruses;

  std::vector<VirusFactory<StrongVirus>> m_strong_virus_factories;
  std::vector<VirusFactory<EvasiveVirus>> m_evasive_virus_factories;
  std::vector<VirusFactory<FastVirus>> m_fast_virus_factories;

  Portal m_portal;

  void update_factories();
  void applay_spells();
  void update_viruses();
  void update_collisions();

  bool colides(const Virus &v, const Portal &p) {
    return Math::distance(v.get_x(), v.get_y(), v.get_z(), p.get_x(), p.get_y(),
                          p.get_z()) < p.get_radius();
  }
  bool colides(const Spell &s, const Virus &v) {
    return v.get_x() > (s.get_x() - s.get_radius()) &&
           v.get_x() < (s.get_x() + s.get_radius()) &&
           v.get_y() > (s.get_y() - s.get_radius()) &&
           v.get_y() < (s.get_y() + s.get_radius());
  }
};

} // namespace vd

#endif // GRIDCONTROLLER_HPP
