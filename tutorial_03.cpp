// Tutorial 3: Model View and Projection Matrices
// Compilation: g++ -framework OpenGL -lGLUT -w tutorial_03.cpp -o tut3.out

#include <GL/freeglut.h>
#include <stdio.h>
const int window_height = 640;
const int window_width = 640;

void RenderLoop()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.f, 1.f, 0.01f, 30.f);

	GLfloat m[16];
	glGetFloatv(GL_PROJECTION_MATRIX, m);
	printf("\n Projection Matrix : \n");
	for (int i = 0; i < 4; i++)	printf(" %f %f %f %f \n", m[i], m[4 + i], m[8 + i], m[12 + i]);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0.f, 0.f, 1.f,
			  0.f, 0.f, -1.f,
			  0.f, 1.f, 0.f); //Default camera configuration : camera is in the origin and looking in the -z direction.
	//gluLookAt(1.f, 0.f, 1.f, 1.f, 0.f, 0.f, 0.f, 1.f, 0.f);

	//glRotatef(90, 0.f, 0.f, 1.f);
	//glTranslatef(4.f, 0.f, -10.f);


	glGetFloatv(GL_MODELVIEW_MATRIX, m);
	printf("\n Model View Matrix : \n");
	for (int i = 0; i < 4; i++)	printf(" %f %f %f %f \n", m[i], m[4 + i], m[8 + i], m[12 + i]);


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
	glutCreateWindow("Transformation Matrices");
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
