
#if !defined(CURSOR_HPP)
#define CURSOR_HPP

#include<GL/glut.h>
namespace vd {

class Cursor {
    public:
        void set_on_screen_x(int x) {
            m_x_on_screen = x;
        }
        void set_on_screen_y(int y) {
            m_y_on_screen = y;
        }
        void init();
        void move(GLfloat camera_position_x, GLfloat camera_position_y,
            int center_x, int center_y);
        
        void draw();
        int get_on_screen_x() const { return m_x_on_screen; }
        int gey_on_screen_y() const { return m_y_on_screen; }
    
    private:
        int m_x_on_screen;
        int m_y_on_screen;
        GLfloat m_x_on_plane;
        GLfloat m_y_on_plane;
        GLuint draw_list;
};

}


#endif // CURSOR_HPP
