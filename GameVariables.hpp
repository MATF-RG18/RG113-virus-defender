

#if !defined(GAME_VARIABLES_HPP)
#define GAME_VARIABLES_HPP
#include<GL/glut.h>
#include<limits>
namespace vd {


class GameVariables {
    public:
        static long long PLASMA;
        static GLfloat PORTAL_HP;
        static long long MANA;

        static constexpr GLfloat MANA_REFRESH_RATE = 50;
        static constexpr long long VIRUS_PLASMA_WORTH = 100;
        static constexpr long long PERMA_SPELL_WORTH = 1000;
        static constexpr long long INF_TIME_TICKS = std::numeric_limits<long long>::max();
        static constexpr int SLOW_SPELL_DURATION = 360;
        static constexpr int DAMAGE_SPELL_DURATION = 120;
};

}

#endif // GAME_VARIABLES_HPP


