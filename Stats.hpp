
#if !defined(STATS_HPP)
#define STATS_HPP
#include<string>

namespace vd {
class Stats {

    public:
        void update();
        void draw();
    private:
        std::string m_plasma_string{10};
        std::string m_mana_string{20};
        std::string m_portal_hp_string{10};
};
}



#endif // STATS_HPP
