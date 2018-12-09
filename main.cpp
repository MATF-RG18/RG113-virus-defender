#include<cstdlib>
#include <GL/glut.h>
#include<vector>
#include<memory>
#include "Portal.hpp"
#include "Virus.hpp"
#include "EvasiveVirus.hpp"
#include "StrongVirus.hpp"
#include "FastVirus.hpp"
static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_display(void);

vd::Portal p;
std::vector<std::unique_ptr<vd::Virus>> viruses;
int main(int argc, char **argv)
{
    // Initialize glut
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    // Initialize window
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);

    // Initialize callback functions
    glutKeyboardFunc(on_keyboard);
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);

    glClearColor(0, 0, 0, 0);

    viruses.push_back(std::make_unique<vd::EvasiveVirus>());
    viruses.push_back(std::make_unique<vd::StrongVirus>());
    viruses.push_back(std::make_unique<vd::FastVirus>());
   
   
    glutMainLoop();

    return 0;
}

static void on_keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:
        exit(0);
        break;
    }
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
    glClear(GL_COLOR_BUFFER_BIT);

    // Set up camera
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(10, 10, 10, 0, 0, 0, 0, 0, 1);

    // Draw white wired plane
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
        for (GLfloat i = -3; i <= 3; i += 0.2) {
            glVertex3f(i, 3, 0); glVertex3f(i, -3, 0);
            glVertex3f(3, i, 0); glVertex3f(-3, i, 0);
        }
    glEnd();
    p.draw();

    for (auto& p: viruses) {
        p->draw();
    }
    glutSwapBuffers();
}
