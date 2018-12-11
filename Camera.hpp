


#if !defined(CAMERA_HPP)
#define CAMERA_HPP
#include<GL/glut.h>
namespace vd{
    class Camera {
        public:
            Camera();
            void move(GLfloat x, GLfloat y);
            void setup();
            void set_move_direction(GLfloat x, GLfloat y) {
                m_move_direction[0] = x;
                m_move_direction[1] = y;
            }

            void stop_moving() { 
                m_move_direction[0] 
                = m_move_direction[1] 
                = m_move_direction[2] = 0;
            }

        private:
            GLfloat m_xyz_eye[3];
            GLfloat m_xyz_position[3];
            GLfloat m_xyz_up[3];
            GLfloat m_move_direction[3];
            const GLfloat m_z_eye = 20;
            const GLfloat m_z_position = 0;
            const GLfloat m_increment = 0.2;
            

    };
}

#endif // CAMERA_HPP
