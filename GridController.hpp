
#if !defined(GRIDCONTROLLER_HPP)
#define GRIDCONTROLLER_HPP


#include<memory>
#include "Virus.hpp"
#include "Spell.hpp"
#include "GameObjectContainer.hpp"
#include "SlowSpell.hpp"
#include "DamageSpell.hpp"
#include "VirusFactory.hpp"
#include "StrongVirus.hpp"
#include "EvasiveVirus.hpp"
#include "FastVirus.hpp"
#include<bitset>
namespace vd{

class GridController {
    public:
        GridController();
        void cast_spell(const SlowSpell& spell) {
            m_slow_spells.insert(spell);
        }
        void cast_spell(const DamageSpell& spell) {
            m_damage_spells.insert(spell);
        }
        void update();
        void draw();
    private:
        static constexpr int MAX_VIRUSES = 500;
        static constexpr int MAX_ACTIVE_SPELLS = 40;
        
        GameObjectContainer<SlowSpell, MAX_ACTIVE_SPELLS> m_slow_spells;
        GameObjectContainer<DamageSpell, MAX_ACTIVE_SPELLS> m_damage_spells;
        GameObjectContainer<StrongVirus, MAX_VIRUSES> m_strong_viruses;
        GameObjectContainer<FastVirus, MAX_VIRUSES> m_fast_viruses;
        GameObjectContainer<EvasiveVirus, MAX_VIRUSES> m_evasive_viruses;
       
        std::vector<VirusFactory<StrongVirus>> m_strong_virus_factories;
        std::vector<VirusFactory<EvasiveVirus>> m_evasive_virus_factories;
        std::vector<VirusFactory<FastVirus>> m_fast_virus_factories;
        
        void update_factories();

};

}


#endif // GRIDCONTROLLER_HPP
