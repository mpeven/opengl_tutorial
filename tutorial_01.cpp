//Tutorial 1: Hello World!

// Compile command:
// g++ -framework GLUT tutorial_01.cpp -o tut1.out

#include <GL/freeglut.h>

const int window_height = 640;
const int window_width = 640;

void RenderLoop()
{
    //Nothing for now !
}

void InitializeGLUT(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Hello World!");
    glutReshapeWindow(window_width, window_height);
    glutDisplayFunc(RenderLoop);
    glutMainLoop();
}

int main(int argc, char* argv[])
{
    InitializeGLUT(argc, argv);
    return 0;
}
