
#if !defined(CURSOR_HPP)
#define CURSOR_HPP
#include "SpellCaster.hpp"
#include <GL/glut.h>
namespace vd {

// Klasa koja prati akcije zadate misem.
// Projektuje kursor na ekranu na ravan na kojoj se desava igra
// i omogucava bacanja trenutno odabrane magije

class Cursor {
public:
  Cursor(SpellCaster &spell_caster) : m_spell_caster(spell_caster) {}

  void set_on_screen_x(int x) { m_x_on_screen = x; }
  void set_on_screen_y(int y) { m_y_on_screen = y; }

  void init();
  
  void move(GLfloat camera_position_x, GLfloat camera_position_y, int center_x,
            int center_y);

  // Funkcije za bacanje spell-a. Pozivaju se klikom na dugme misa
  void cast_spell() { m_spell_caster.cast_active_spell(); }
  void cast_perma_spell() { m_spell_caster.cast_active_perma_spell(); }

  void draw();

  // (x,y) pozicija cursora na ekranu
  int get_on_screen_x() const { return m_x_on_screen; }
  int gey_on_screen_y() const { return m_y_on_screen; }

  // (x,y) pozicija cursora na ravni igre
  GLfloat get_x_on_plane() const { return m_x_on_plane; }
  GLfloat get_y_on_plane() const { return m_y_on_plane; }

private:
  int m_x_on_screen;
  int m_y_on_screen;
  GLfloat m_x_on_plane;
  GLfloat m_y_on_plane;
  GLuint draw_list;
  SpellCaster &m_spell_caster;
};

} // namespace vd

#endif // CURSOR_HPP
