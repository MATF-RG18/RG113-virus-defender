#include<cstdlib>
#include <GL/glut.h>

#include "Game.hpp"

static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_display(void);
static void on_timer(int value);
static void on_passive_mouse_motion(int x, int y);
vd::Game game;


int main(int argc, char **argv)
{
    // Initialize glut
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    // Initialize window
    glutInitWindowSize(900, 900);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);

    // Initialize callback functions
    glutKeyboardFunc(on_keyboard);
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);
    glutTimerFunc(game.get_msec_timer_update(), on_timer, game.get_timer_id());
    glutPassiveMotionFunc(on_passive_mouse_motion);
    glClearColor(0, 0, 0, 0);
   

    glutMainLoop();

    return 0;
}

static void on_timer(int value)
{
    game.update();
    glutPostRedisplay();
    glutTimerFunc(game.get_msec_timer_update(), on_timer, game.get_timer_id());
    
}

static void on_keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:
        exit(0);
        break;
    default:
        game.set_keyboard_input(key, x, y);
    }
}

static void on_passive_mouse_motion(int x, int y)
{
    game.set_passive_mouse_motion_input(x,y);
}

static void on_reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30, (float) width / height, 1, 100);
}

static void on_display(void)
{
    game.draw();
    
}
