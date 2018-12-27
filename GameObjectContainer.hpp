
#if !defined(GAMEOBJECTCONTAINER_HPP)
#define GAMEOBJECTCONTAINER_HPP

#include <iostream>
#include <vector>
namespace vd {

/*
Template klasa koja se koristi u GridController.
GameObjectContainer poziva osnovne metode
draw i update za sve aktivne tipove objekata
u igri.
*/

template <typename T, size_t N> class GameObjectContainer {
public:
  using iterator = typename std::vector<T>::iterator;
  GameObjectContainer() : m_objects(N) {}
  void update();
  void draw();

  // Druge klase pozivaju insert kada ubacuju
  // novi spell ili virus na grid

  void insert(const T &object);
  iterator begin() { return m_objects.begin(); }
  iterator end() { return m_objects.end(); }

private:
  std::vector<T> m_objects;
};

template <typename T, size_t N> void GameObjectContainer<T, N>::update() {
  for (auto &o : m_objects) {
    if (o.is_active()) {
      o.update();
    }
  }
}

/*
  Ubacivanje novog objekta u Container
*/

template <typename T, size_t N>
void GameObjectContainer<T, N>::insert(const T &object) {
  for (auto &o : m_objects) {
    if (!o.is_active()) {
      o = object;
      o.activate();
      return;
    }
  }
}
template <typename T, size_t N> void GameObjectContainer<T, N>::draw() {

  for (auto &o : m_objects) {
    if (o.is_active()) {
      o.draw();
    }
  }
}

} // namespace vd
#endif // GAMEOBJECTCONTAINER_HPP
