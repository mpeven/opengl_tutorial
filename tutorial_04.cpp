//Tutorial 4: Transformation Stack
// Compilation: g++ -framework OpenGL -lGLUT -w tutorial_04.cpp -o tut4.out

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

	GLfloat m[16];
	glGetFloatv(GL_PROJECTION_MATRIX, m);
	printf("\n Projection Matrix : \n");
	for (int i = 0; i < 4; i++)	printf(" %f %f %f %f \n", m[i], m[4 + i], m[8 + i], m[12 + i]);

	glMatrixMode(GL_MODELVIEW);

	// Node 0 Begin
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(0.f, 0.f, -10.f);

		// Node 0->0 Begin
		glPushMatrix();
		glTranslatef(2.f, 0.f, 0.f);
		glRotatef(45.f, 0.f, 0.f, 1.f);
		glColor3f(1.f, 1.f, 1.f);

			// Node 0->0->0 Begin
			glPushMatrix();
			glTranslatef(-1.f, 0.f,0.f);
			DrawUnitTriangle();
			glPopMatrix();
			// Node 0->0->0 End

			// Node 0->0->1 Begin
			glPushMatrix();
			glTranslatef(0.f, 0.f, 0.f);
			DrawUnitTriangle();
			glPopMatrix();
			// Node 0->0->1 End

			// Node 0->0->2 Begin
			glPushMatrix();
			glTranslatef(-1.f,-1.f, 0.f);
			DrawUnitTriangle();
			glPopMatrix();
			// Node 0->0->2 End

			// Node 0->0->3 Begin
			glPushMatrix();
			glTranslatef(-1.f,0.f, 0.f);
			DrawUnitTriangle();
			glPopMatrix();
			// Node 0->0->3 End

		glPopMatrix();
		// Node 0->0 End

		// Node 0->1 Begin
		glPushMatrix();
		glTranslatef(-3.f, 0.f, 0.f);
		glRotatef(-60.f, 0.f, 0.f, 1.f);
		glColor3f(1.f, 0.f, 0.f);
		DrawUnitTriangle();
		glPopMatrix();
		// Node 0->1 End

	glPopMatrix();
	// Node 0 End

	glGetFloatv(GL_MODELVIEW_MATRIX, m);
	printf("\n Model View Matrix : \n");
	for (int i = 0; i < 4; i++)	printf(" %f %f %f %f \n", m[i], m[4 + i], m[8 + i], m[12 + i]);

	glutSwapBuffers();
}

void InitializeGLUT(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Transformation Stack");
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
