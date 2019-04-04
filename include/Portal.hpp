
#if !defined(PORTAL_HPP)
#define PORTAL_HPP
#include "GameObject.hpp"
#include "GameVariables.hpp"
#include "Material.hpp"
namespace vd {
/*
  Klasa koja predstavlja portal
  koji se nalazi na sredni ravni i kojeg
  virusi napadaju
*/
class Portal : public GameObject {
public:
  Portal();
  void draw() override;
  void update() override;

  void take_damage(GLfloat damage) {
    GameVariables::PORTAL_HP -= damage;
    if (GameVariables::PORTAL_HP <= 0) {
      GameVariables::GAME_ON = false;
    }
  }
  GLfloat get_radius() const { return m_radius; }
  static void init();

private:
  GLfloat m_radius = 3;
  int m_animation_parameter = 0;
  Material m_material;
};

} // namespace vd

#endif // PORTAL_HPP
