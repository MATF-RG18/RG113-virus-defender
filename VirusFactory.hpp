
#if !defined(VIRUSFACTORY_HPP)
#define VIRUSFACTORY_HPP
#include "GameObject.hpp"
#include "GameVariables.hpp"
#include "GridController.hpp"
#include "Portal.hpp"
#include "RandomReal.hpp"
#include <GL/glut.h>
#include <vector>
namespace vd {

template <typename T> class VirusFactory : public GameObject {
public:
  using iterator = std::vector<T>;
  VirusFactory(GLfloat x, GLfloat y, GLfloat z)
      : GameObject(x, y, z),
        m_spawn_interval(GameVariables::rand_spawn_interval()),
        m_update_tick(GameVariables::TICKS_PER_SEC * m_spawn_interval),
        m_remaning_spawn_ticks(m_update_tick),
        m_active_interval(GameVariables::rand_active_interval() *
                          GameVariables::TICKS_PER_SEC),
        m_remaning_active(m_active_interval),
        m_sleep_interval(GameVariables::rand_sleep_interval() *
                         GameVariables::TICKS_PER_SEC),
        m_remaning_sleep(m_sleep_interval), m_virus(x, y, z) {}
  bool ready() const { return m_remaning_spawn_ticks <= 0; }

  void update() override;
  T get() {
    m_remaning_spawn_ticks = m_update_tick;
    return m_virus;
  }
  void draw() override {}

private:
  // How many ticks does it take to generate all viruses
  GLfloat m_spawn_interval;

  const int m_update_tick;
  int m_remaning_spawn_ticks;

  const int m_active_interval;
  int m_remaning_active;

  const int m_sleep_interval;
  int m_remaning_sleep;

  T m_virus;
};

template <typename T> void VirusFactory<T>::update() {
  if (is_active()) {
    if (m_remaning_spawn_ticks >= 0) {
      --m_remaning_spawn_ticks;
    } else {
      m_remaning_spawn_ticks = m_update_tick;
    }

    --m_remaning_active;
    if (m_remaning_active <= 0) {
      m_remaning_sleep = m_sleep_interval;
      deactivate();
    }
  } else {
    if (m_remaning_sleep >= 0) {
      --m_remaning_sleep;
    } else {
      m_remaning_active = m_active_interval;
      activate();
    }
  }
}

} // namespace vd

#endif // VIRUSFACTORY_HPP
