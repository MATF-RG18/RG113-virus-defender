
#if !defined(GRIDCONTROLLER_HPP)
#define GRIDCONTROLLER_HPP


#include<memory>
#include "Virus.hpp"
#include "Spell.hpp"

#include<bitset>
namespace vd{

class GridController {
    public:
        
        void cast_spell(const Spell&);
        void update();
        void draw();
    private:
        static constexpr int MAX_VIRUSES = 500;
        static constexpr int MAX_ACTIVE_SPELLS = 40;

        // Optimize memory allocation
        std::bitset<MAX_VIRUSES> m_active_viruses;
        std::array<std::unique_ptr<Virus>, MAX_VIRUSES> m_viruses;

        // Optimize memory allocation
        std::bitset<MAX_ACTIVE_SPELLS> m_active_spells;
        std::array<std::unique_ptr<Spell>, MAX_ACTIVE_SPELLS> m_spells;

        void spawn_virus();

};

}


#endif // GRIDCONTROLLER_HPP
