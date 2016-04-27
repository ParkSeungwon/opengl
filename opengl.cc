#include "opengl.h"
#include <functional>
using namespace std;

OpenGL::OpenGL(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow(title_.c_str());

}

void OpenGL::start()
{
	function<void(void)> f = bind(&OpenGL::RenderScene, this);
	glutDisplayFunc(&f);
	glutReshapeFunc(&OpenGL::ChangeSize);
	glutTimerFunc(timer_, TimerFunction, 1);
	SetupRC();
	glutMainLoop();
}

void OpenGL::RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glutSwapBuffers();//2 buffer need no flush
}

void OpenGL::ChangeSize(int w, int h)
{
	glViewport(0, 0, w, h);
}

void OpenGL::TimerFunction(int value)
{
}
