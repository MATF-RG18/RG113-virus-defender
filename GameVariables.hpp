

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

  // Dokle god je GAME_ON true poziva se on_timer callback
  // i igra tece
  static bool GAME_ON;

  // Trenutno stanje PLASME kojom se bacaju perma-spells
  static long long PLASMA;

  // Trenutno stanje HP portala
  static int PORTAL_HP;

  // Trenutno stanje MANA kojom se bacaju obicni spellovi
  static int MANA;

  static constexpr int MAX_MANA = 1000;

  // Broj mana koje se obnavljaju svakim tikom
  static constexpr GLfloat MANA_REFRESH_RATE = 10;


  static constexpr int INIT_WINDOW_HEIGHT = 768;
  static constexpr int INIT_WINDOW_WIDTH = 768;

  static constexpr long long INF_TIME_TICKS =
      std::numeric_limits<long long>::max();

  // PLASMA koja se dobije kada se ubije jedan virus
  static constexpr long long VIRUS_PLASMA_WORTH = 500;

  // Cena bacanja perma spell-a
  static constexpr long long PERMA_SPELL_WORTH = 1000;

  static constexpr int TICKS_PER_SEC = 60;

  static constexpr float GRID_X_SIZE = 50;
  static constexpr float GRID_Y_SIZE = 50;

  static constexpr float INIT_PORTAL_HP = 1500;
  static RandomReal rand_spawn_interval;
  static RandomReal rand_sleep_interval;
  static RandomReal rand_active_interval;
  static void update();
};

} // namespace vd

#endif // GAME_VARIABLES_HPP
