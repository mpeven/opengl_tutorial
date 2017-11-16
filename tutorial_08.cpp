//Tutorial 8: Shading
// Compilation: g++ -framework OpenGL -lGLUT -w tutorial_08.cpp -o tut8.out
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

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	GLfloat light_diffuse_color[4] = { 1.f, 1.f, 1.f, 1.f };
	GLfloat light_position[4] = { 0.f, 0.f, 1.f, 0.f };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse_color);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	GLfloat material_diffuse_color[4] = { 1.f, 1.f, 1.f, 1.f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_diffuse_color);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(0.f, 0.f, -10.f);
	glScalef(4.f, 4.f, 4.f);

	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);
	// glShadeModel(GL_FLAT);
	glBegin(GL_TRIANGLES);
	glNormal3f(0.f, 0.f, -1.f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glNormal3f(1.f, -1.f, 1.f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glNormal3f(0.f, 0.f, 1.f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glEnd();

	glPopMatrix();

	glDisable(GL_LIGHTING);

	// GLfloat m[16];
	// glGetFloatv(GL_PROJECTION_MATRIX, m);
	// printf("\n Projection Matrix : \n");
	// for (int i = 0; i < 4; i++)	printf(" %f %f %f %f \n", m[i], m[4 + i], m[8 + i], m[12 + i]);

	// glGetFloatv(GL_MODELVIEW_MATRIX, m);
	// printf("\n Model View Matrix : \n");
	// for (int i = 0; i < 4; i++)	printf(" %f %f %f %f \n", m[i], m[4 + i], m[8 + i], m[12 + i]);

	glutSwapBuffers();
}

void InitializeGLUT(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Shading");
	glutReshapeWindow(window_width, window_height);
	glutDisplayFunc(RenderLoop);
	glClearColor(0.f, 0.f, 0.f, 1.0);

	glutMainLoop();
}

int main(int argc, char* argv[])
{
	InitializeGLUT(argc, argv);
	return 0;
}
