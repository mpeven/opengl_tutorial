//Tutorial 7: Lighting
// Compilation: g++ -framework OpenGL -lGLUT -w tutorial_07.cpp -o tut7.out

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

	glPushMatrix();
	glTranslatef(0.f, 4.f, 0.f);
	glRotatef(0.f, 1.f, 0.f, 0.f);
	DrawUnitTriangle();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.f, 2.f, 0.f);
	glRotatef(15.f, 1.f, 0.f, 0.f);
	DrawUnitTriangle();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.f, 0.f, 0.f);
	glRotatef(30.f, 1.f, 0.f, 0.f);
	DrawUnitTriangle();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.f, -1.f, 0.f);
	glRotatef(45.f, 1.f, 0.f, 0.f);
	DrawUnitTriangle();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.f, -2.f, 0.f);
	glRotatef(60.f, 1.f, 0.f, 0.f);
	DrawUnitTriangle();
	glPopMatrix();


	glPopMatrix();

	glDisable(GL_LIGHTING);
	glutSwapBuffers();
}

void InitializeGLUT(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Lighting");
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
