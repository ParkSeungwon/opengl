#include <gl.h>
#include <glut.h>
#include <iostream>
using namespace std;

void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glutSolidTeapot(100);
	glFlush();
}

void SetupRC()
{
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Simple");
	glutDisplayFunc(RenderScene);
	SetupRC();
	cout << glGetString(GL_EXTENSIONS);
	glutMainLoop();
}

