

#if !defined(CAMERA_HPP)
#define CAMERA_HPP
#include <GL/glut.h>
namespace vd {

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
    m_move_direction[0] = m_move_direction[1] = m_move_direction[2] = 0;
  }

  void start_moving_north();
  void start_moving_east();
  void start_moving_west();
  void start_moving_south();

  void stop_moving_north();
  void stop_moving_east();
  void stop_moving_west();
  void stop_moving_south();

  const GLfloat (&pointing_vector())[3] { return m_camera_pointing_vector; }
  const GLfloat (&position_point())[3] { return m_xyz_position; }
  const GLfloat (&eye_point())[3] { return m_xyz_eye; }

private:
  GLfloat m_xyz_eye[3];
  GLfloat m_xyz_position[3];
  GLfloat m_xyz_up[3];
  GLfloat m_move_direction[3];

  const GLfloat m_camera_pointing_vector[3] = {15, 15, -20};

  const GLfloat m_z_eye = 20;
  const GLfloat m_z_position = 0;

  struct MovmentVectors {
  private:
    constexpr static GLfloat m_sqrt2by2 = {0.70710678118f};
    constexpr static GLfloat m_div_factor = 2.5;

  public:
    constexpr static GLfloat north[2] = {m_sqrt2by2 / m_div_factor,
                                         m_sqrt2by2 / m_div_factor};
    constexpr static GLfloat south[2] = {-m_sqrt2by2 / m_div_factor,
                                         -m_sqrt2by2 / m_div_factor};
    constexpr static GLfloat west[2] = {-m_sqrt2by2 / m_div_factor,
                                        m_sqrt2by2 / m_div_factor};
    constexpr static GLfloat east[2] = {m_sqrt2by2 / m_div_factor,
                                        -m_sqrt2by2 / m_div_factor};
  };
};
} // namespace vd

#endif // CAMERA_HPP
