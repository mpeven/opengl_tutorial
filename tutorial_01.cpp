// Tutorial 1: Hello World!
// Compilation: g++ -lGLUT tutorial_01.cpp -o tut1.out
// (-lGLUT so linker will link the executable to the compiled GLUT binary)

#include <GL/freeglut.h> // Need the include directories for header files

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
