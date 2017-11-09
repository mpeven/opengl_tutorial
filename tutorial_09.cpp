//Tutorial 9: Texture

#include <GL/freeglut.h>
#include <stdio.h>
const int window_height = 640;
const int window_width = 640;

GLuint checkeboardTextureHandle;

void GenerateCheckerboardPattern(int blockSide, int repetitions, unsigned char * pattern){
	int textureSide = blockSide * repetitions;
	for (int i = 0; i < textureSide; i++)for (int j = 0; j < textureSide; j++){
		int pi = i / blockSide;
		int pj = j / blockSide;
		for (int c = 0; c < 3; c++) pattern[3 * (i*textureSide + j) + c] = ((pi + pj) % 2 == 0) ? 255 : 0;
	}
}

void SetupTexture(GLuint & textureHandle, int width, int height, unsigned char * pattern){
	glGenTextures(1, &textureHandle);
	glBindTexture(GL_TEXTURE_2D, textureHandle);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, (GLvoid*)&pattern[0]);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void RenderLoop()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.f, 1.f, 0.01f, 30.f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.f, 0.f, -10.f);
	glScalef(4.f, 4.f, 4.f);


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, checkeboardTextureHandle);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);


	glBegin(GL_TRIANGLES);
	glTexCoord2d(0, 0);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glTexCoord2d(1, 0);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glTexCoord2d(1, 1);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glEnd();

	glDisable(GL_TEXTURE_2D);

	glutSwapBuffers();
}

void Initialize(int argc, char* argv[])
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Texture");

	glutReshapeWindow(window_width, window_height);
	glutDisplayFunc(RenderLoop);
	glClearColor(0.f, 0.f, 0.f, 1.0);

	int repetitions = 12;
	int blockSide = 20;
	int textureSide = blockSide*repetitions;
	unsigned char * checkerboarPattern = new unsigned char[textureSide*textureSide * 3];
	GenerateCheckerboardPattern(blockSide, repetitions, checkerboarPattern);
	SetupTexture(checkeboardTextureHandle, textureSide, textureSide, checkerboarPattern);
	delete checkerboarPattern;

	glutMainLoop();
}

int main(int argc, char* argv[])
{
	Initialize(argc, argv);
	return 0;
}
