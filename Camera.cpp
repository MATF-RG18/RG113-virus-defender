#include "Camera.hpp"
#include<GL/glut.h>
namespace vd{

Camera::Camera() {
    m_xyz_eye[0] = 10;
    m_xyz_eye[1] = 10;
    m_xyz_eye[2] = m_z_eye;

    m_xyz_position[0] = m_xyz_eye[0] + 15;
    m_xyz_position[1] = m_xyz_eye[1] + 15;
    m_xyz_position[2] = m_z_position;

    // m_xyz_up[0] = m_xyz_position[0];
    // m_xyz_up[1] = m_xyz_position[1];
    // m_xyz_up[2] = m_z_position;
}

// void Camera::set_move_direction(GLfloat x, GLfloat y) {
//     // m_xyz_position[0] = m_xyz_eye[0] + x;
//     // m_xyz_position[1] = m_xyz_eye[1] + y;
    
//     // m_xyz_eye[0] += x;
//     // m_xyz_eye[1] += y;

//     // m_xyz_up[0] += x;
//     // m_xyz_up[1] += y;
// }

void Camera::setup() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    m_xyz_eye[0] += m_move_direction[0];
    m_xyz_eye[1] += m_move_direction[1];

    m_xyz_position[0] += m_move_direction[0];
    m_xyz_position[1] += m_move_direction[1];

    gluLookAt(m_xyz_eye[0],
            m_xyz_eye[1], 
            m_xyz_eye[2],
            m_xyz_position[0],
            m_xyz_position[1],
            m_xyz_position[2],
            50,50, 25);

}

}

