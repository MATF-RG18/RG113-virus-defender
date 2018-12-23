

#if !defined(GAME_VARIABLES_HPP)
#define GAME_VARIABLES_HPP
#include "RandomReal.hpp"
#include "Window.hpp"
#include <GL/glut.h>
#include <limits>
namespace vd {

class GameVariables {
public:
  static Window window;

  static bool GAME_ON;

  static long long PLASMA;

  static int PORTAL_HP;

  static int MANA;
  static constexpr int MAX_MANA = 1000;
  static constexpr GLfloat MANA_REFRESH_RATE = 50;

  static constexpr int INIT_WINDOW_HEIGHT = 768;
  static constexpr int INIT_WINDOW_WIDTH = 768;

  static constexpr long long INF_TIME_TICKS =
      std::numeric_limits<long long>::max();

  static constexpr long long VIRUS_PLASMA_WORTH = 500;
  static constexpr long long PERMA_SPELL_WORTH = 1000;

  static constexpr int SLOW_SPELL_DURATION = 250;
  static constexpr int DAMAGE_SPELL_DURATION = 125;

  static constexpr int SPELL_MANA_WORTH = 200;
  static constexpr int TICKS_PER_SEC = 60;

  static constexpr float GRID_X_SIZE = 50;
  static constexpr float GRID_Y_SIZE = 50;

  static constexpr float INIT_PORTAL_HP = 5000;
  static RandomReal rand_spawn_interval;
  static RandomReal rand_sleep_interval;
  static RandomReal rand_active_interval;
  static void update();
};

} // namespace vd

#endif // GAME_VARIABLES_HPP
