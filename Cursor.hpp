
#if !defined(CURSOR_HPP)
#define CURSOR_HPP
#include "SpellCaster.hpp"
#include<GL/glut.h>
namespace vd {

class Cursor {
    public:
        Cursor(SpellCaster& spell_caster) 
        : m_spell_caster(spell_caster) {}
        void set_on_screen_x(int x) {
            m_x_on_screen = x;
        }
        void set_on_screen_y(int y) {
            m_y_on_screen = y;
        }
        void init();
        void move(GLfloat camera_position_x, GLfloat camera_position_y,
            int center_x, int center_y);
        
        void cast_spell() {
            m_spell_caster.cast_active_spell();
        }
        void cast_perma_spell() {
            m_spell_caster.cast_active_perma_spell();
        }
        void draw();
        int get_on_screen_x() const { return m_x_on_screen; }
        int gey_on_screen_y() const { return m_y_on_screen; }
    
        GLfloat get_x_on_plane() const { return m_x_on_plane; }
        GLfloat get_y_on_plane() const { return m_y_on_plane; }
    
    private:
        int m_x_on_screen;
        int m_y_on_screen;
        GLfloat m_x_on_plane;
        GLfloat m_y_on_plane;
        GLuint draw_list;
        SpellCaster& m_spell_caster;
        
};

}


#endif // CURSOR_HPP
