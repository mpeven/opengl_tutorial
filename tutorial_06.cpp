//Tutorial 6: Call Lists 2
// Compilation: g++ -framework OpenGL -lGLUT -w tutorial_06.cpp -o tut6

#include <GL/freeglut.h>
#include <stdio.h>
const int window_height = 640;
const int window_width = 640;

GLuint listID = 0;

void drawObject(){
	if (listID == 0){
		glPushMatrix();
		glRotatef(45.f, 0.f, 0.f, 1.f);
		glColor3f(1.f, 1.f, 1.f);

		glPushMatrix();
		glTranslatef(-1.f, 0.f, 0.f);
		glBegin(GL_TRIANGLES);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, 0.0f);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.f, 0.f, 0.f);
		glBegin(GL_TRIANGLES);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, 0.0f);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.f, -1.f, 0.f);
		glBegin(GL_TRIANGLES);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, 0.0f);
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.f, 0.f, 0.f);
		glBegin(GL_TRIANGLES);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, 0.0f);
		glEnd();
		glPopMatrix();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-2.2f, 0.f, 0.f);
		glRotatef(-60.f, 0.f, 0.f, 1.f);
		glColor3f(1.f, 0.f, 0.f);
		glBegin(GL_TRIANGLES);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, 0.0f);
		glEnd();
		glPopMatrix();
	}
	else{
		glCallList(listID);
	}
}

void setCallList()
{
	GLuint tempID = glGenLists(1);
	glNewList(tempID, GL_COMPILE);
	drawObject();
	glEndList();
	listID = tempID;
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
	glTranslatef(-3.5f, 0.f, 0.f);
	drawObject();
	glPopMatrix();
	// Node 0->0 End

	// Node 0->1 Begin
	glPushMatrix();
	glTranslatef(4.f, 0.f, 0.f);
	drawObject();
	glPopMatrix();
	// Node 0->1 End

	// Node 0->2 Begin
	glPushMatrix();
	glTranslatef(0.f, 3.f, 0.f);
	glCallList(listID);
	glPopMatrix();
	// Node 0->2 End

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
	glutCreateWindow("Call Lists 2");
	glutReshapeWindow(window_width, window_height);
	glutDisplayFunc(RenderLoop);
	glClearColor(0.f, 0.f, 0.f, 1.0);
	setCallList();
	glutMainLoop();
}

int main(int argc, char* argv[])
{
	InitializeGLUT(argc, argv);
	return 0;
}
