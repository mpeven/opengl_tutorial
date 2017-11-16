//Tutorial 10: Depth Test
// Compilation: g++ -framework OpenGL -lGLUT -w tutorial_10.cpp -o tut10.out

#include <GL/freeglut.h>
#include <stdio.h>
const int window_height = 640;
const int window_width = 640;

void DrawUnitTriangle(){
	glBegin(GL_TRIANGLES);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glEnd();
}

void RenderLoop()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.f, 1.f, 0.01f, 30.f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//glEnable(GL_DEPTH_TEST); //Keep only visible surfaces -> Rendering order is not important.

	glPushMatrix();
	glTranslatef(0.f, 0.f, -2.f);
	glColor3f(1.0, 0.0, 0.0);
	DrawUnitTriangle();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-0.5f, -0.25f, -4.f);
	glColor3f(0.0, 1.0, 0.0);
	DrawUnitTriangle();
	glPopMatrix();

	//glDisable(GL_DEPTH_TEST);

	glutSwapBuffers();
}

void Initialize(int argc, char* argv[])
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Depth Test");

	glutReshapeWindow(window_width, window_height);
	glutDisplayFunc(RenderLoop);
	glClearColor(0.f, 0.f, 0.f, 1.0);

	glutMainLoop();
}

int main(int argc, char* argv[])
{
	Initialize(argc, argv);
	return 0;
}
