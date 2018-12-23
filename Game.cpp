#include "Game.hpp"
#include <GL/glut.h>
#include <iostream>
#include "StrongVirus.hpp"

namespace vd {


// void draw_clip_planes()
// {
  
//   constexpr static double clip_plane0[4] = {1,0,0,0};
//   constexpr static double clip_plane1[4] = {0,1,0,0};
//   constexpr static double clip_plane2[4] = {-1,0,0,GameVariables::GRID_X_SIZE};
//   constexpr static double clip_plane3[4] = {0,-1,0,GameVariables::GRID_Y_SIZE};

//   glClipPlane(GL_CLIP_PLANE0, clip_plane0);
//   glClipPlane(GL_CLIP_PLANE1, clip_plane1);
//   glClipPlane(GL_CLIP_PLANE2, clip_plane2);
//   glClipPlane(GL_CLIP_PLANE3, clip_plane3);
//   glEnable(GL_CLIP_PLANE0);
//   // glEnable(GL_CLIP_PLANE1);
//   // glEnable(GL_CLIP_PLANE2);
//   // glEnable(GL_CLIP_PLANE3);


// }

Game::Game()
    : m_camera(),
      m_spell_caster(m_grid_controller),
      m_keyboard_action(m_camera, m_spell_caster),
      m_cursor(m_spell_caster),
      m_passive_mouse_motion_action(m_camera, m_window, m_cursor),
      m_mouse_action(m_cursor) {
        

      }

void Game::init() 
{ 
  m_cursor.init(); 
  m_main_light.enable();  
  // draw_clip_planes();


}

void Game::update() {
  m_grid_controller.update();
  stats.update();
  GameVariables::update();
}

void Game::draw() {
  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

  m_camera.setup();

  m_main_light.draw();

  m_cursor.move(m_camera.position_point()[0], m_camera.position_point()[1],
                m_window.get_center_x(), m_window.get_center_y());

  m_cursor.draw();

  // glColor3f(3.0, 3.0, 3.0);
  // glBegin(GL_POLYGON);
  // glVertex3f(0, 0, 0);
  // glVertex3f(0, 50, 0);
  // glVertex3f(50, 50, 0);
  // glVertex3f(50, 0, 0);
  // glEnd();
  m_plane.draw();
  m_grid_controller.draw();
  stats.draw();
  
  glutSwapBuffers();
}

}  // namespace vd