#include <gl.h>
#include <glut.h>

float x1 = 0.0;
float y1 = 0.0;
float rsize = 25;
float xstep = 3.0;
float ystep = 3.0;
float windowWidth;
float windowHeight;

void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glRectf(x1, y1, x1 + rsize, y1 - rsize);
	glutSwapBuffers();//2 buffer need no flush
}

void TimerFunction(int value)
{
	if(x1 > windowWidth - rsize || x1 < -windowWidth) xstep = -xstep;
	if(y1 > windowHeight || y1 < -windowHeight + rsize) ystep = -ystep;
	x1 += xstep;
	y1 += ystep;

	if(x1 > windowWidth - rsize + xstep) x1 = windowWidth - rsize - 1;
	else if(x1 < -(windowWidth + xstep)) x1 = -windowWidth - 1;
	if(y1 > windowHeight + ystep) y1 = windowHeight - 1;
	else if(y1 < -(windowHeight + rsize + ystep)) y1 = -windowHeight + rsize - 1;

	glutPostRedisplay();
	glutTimerFunc(1, TimerFunction, 1);
}

void SetupRC()
{
	glClearColor(0.0, 0.0, 1.0, 1.0);
}

void ChangeSize(int w, int h)
{
	float aspectRatio;
	if(h == 0) h =1;
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	aspectRatio = (float)w/(float)h;
	if(w <= h) {
		windowWidth = 100;
		windowHeight = 100 / aspectRatio;
		glOrtho(-100.0, 100.0, -windowHeight, windowHeight, 1.0, -1.0);
	} else {
		windowWidth = 100 * aspectRatio;
		windowHeight = 100;
		glOrtho(-windowWidth, windowWidth, 100.0, 100.0, 1.0, -1.0);
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("Bounce");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutTimerFunc(333, TimerFunction, 1);
	SetupRC();
	glutMainLoop();
}

