

#if !defined(CAMERA_HPP)
#define CAMERA_HPP
#include <GL/glut.h>
namespace vd {

// Klasa : Camera
// Kontrolise pomeranje i postavljanje kamera
// tako da uvek gleda na scenu sa iste visine.

class Camera {
public:
  Camera();
  void move(GLfloat x, GLfloat y);
  void setup();

  // Postavlja pravac u kome ce se kamera kretati
  // Kamera se krece u tom pravcu do je pritisnuto
  // neko od dugmica
  void set_move_direction(GLfloat x, GLfloat y) {
    m_move_direction[0] = x;
    m_move_direction[1] = y;
  }

  void stop_moving() {
    m_move_direction[0] = m_move_direction[1] = m_move_direction[2] = 0;
  }

  // Kada se pritisne neko od WASD 
  // kamera se krece u odgovarajucem pravcu
  // dokle god je to dugme pritisnuto
  // Prisitkom na neko od WASD modifikuje
  // se vektor pravca kretanja kamere
  // Kada kamera stoji vektor pravca je [0,0,0]

  void start_moving_north();
  void start_moving_east();
  void start_moving_west();
  void start_moving_south();


  // Odpustanjem nekod od dugmica WASD
  // oduzima se odgovarajuci vektor pravca od 
  // vektora kretanje kamere
  void stop_moving_north();
  void stop_moving_east();
  void stop_moving_west();
  void stop_moving_south();

  const GLfloat (&pointing_vector())[3] { return m_camera_pointing_vector; }
  const GLfloat (&position_point())[3] { return m_xyz_position; }
  const GLfloat (&eye_point())[3] { return m_xyz_eye; }

private:
  // Pozicija kakmere u prostoru
  GLfloat m_xyz_eye[3];

  // Tacka na koju kamera gleda
  GLfloat m_xyz_position[3];

  // Up vektor
  const GLfloat m_xyz_up[3] = {50, 50, 25};

  // Vektor pravca kretanja kamere. Inicjalno [0,0,0]
  GLfloat m_move_direction[3];

  // Vektor pod kojim kamera gleda na ravan
  const GLfloat m_camera_pointing_vector[3] = {15, 15, -20};

  // Visina kamere
  const GLfloat m_z_eye = 20;

  // Uvek gleda na z = 0
  const GLfloat m_z_position = 0;


  // Pomocna klasa koja definise
  // svaki od North(W), East(D), South(S), West(D)
  // vektora kretanja kamere koji se dodaju ili oduzimaju
  // u m_move_direction pritiskom ili odpustanjem 
  // tastera WASD
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
