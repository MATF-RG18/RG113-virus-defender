

#if !defined(GAME_VARIABLES_HPP)
#define GAME_VARIABLES_HPP
#include<GL/glut.h>
#include<limits>
#include "Window.hpp"
namespace vd {


class GameVariables {
    public:
        static Window window;

        static long long PLASMA;

        static GLfloat PORTAL_HP;

        static int MANA;
        static constexpr int MAX_MANA = 1000;
        static constexpr GLfloat MANA_REFRESH_RATE = 10;

        static constexpr int INIT_WINDOW_HEIGHT = 768;
        static constexpr int INIT_WINDOW_WIDTH = 768;
        
        static constexpr long long INF_TIME_TICKS = std::numeric_limits<long long>::max();
        
        static constexpr long long VIRUS_PLASMA_WORTH = 100;
        static constexpr long long PERMA_SPELL_WORTH = 300;
        
        static constexpr int SLOW_SPELL_DURATION = 360;
        static constexpr int DAMAGE_SPELL_DURATION = 120;

        static constexpr int SPELL_MANA_WORTH = 500;
    
        static void update();
};

}

#endif // GAME_VARIABLES_HPP


