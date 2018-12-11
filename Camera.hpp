


#if !defined(CAMERA_HPP)
#define CAMERA_HPP
#include<GL/glut.h>
namespace vd{
    class Camera {
        public:
            Camera();
            void move(GLfloat x, GLfloat y);
            void setup();
            void move_n();
            void move_e();
            void move_w();
            void move_s();
            
            void stop_moving();

        private:
            GLfloat m_xyz_eye[3];
            GLfloat m_xyz_position[3];
            GLfloat m_xyz_up[3];
            const GLfloat m_z_eye = 20;
            const GLfloat m_z_position = 0;
            const GLfloat m_increment = 0.2;
            

    };
}

#endif // CAMERA_HPP
