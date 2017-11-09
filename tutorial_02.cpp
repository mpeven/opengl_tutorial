// Tutorial 2: First Rendering
// Compilation: g++ -framework OpenGL -lGLUT tutorial_02.cpp -o tut2.out

#include <GL/freeglut.h>
#include <stdio.h>
const int window_height = 480;
const int window_width = 640;

void RenderLoop()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLfloat m[16];
    glGetFloatv(GL_MODELVIEW_MATRIX, m);
    printf("\n Model View Matrix : \n");
    for (int i = 0; i < 4; i++) printf(" %f %f %f %f \n", m[i], m[4 + i], m[8 + i], m[12 +i]);

    glGetFloatv(GL_PROJECTION_MATRIX, m);
    printf("\n Projection Matrix : \n");
    for (int i = 0; i < 4; i++) printf(" %f %f %f %f \n", m[i], m[4 + i], m[8 + i], m[12 + i]);

    glBegin(GL_TRIANGLES);
    glColor3f(1.f, 0.f, 0.f);
    glVertex3f(0.0f, 0.0f, -1.0f);
    glColor3f(0.f, 1.f, 0.f);
    glVertex3f(1.0f, 0.0f, -1.0f);
    glColor3f(0.f, 0.f, 1.f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glEnd();

    glutSwapBuffers();
}

void InitializeGLUT(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("First Rendering");
    glutReshapeWindow(window_width, window_height);
    glutDisplayFunc(RenderLoop);
    glClearColor(0.f,0.f,0.f,1.0);
    glutMainLoop();
}

int main(int argc, char* argv[])
{
    InitializeGLUT(argc, argv);
    return 0;
}
