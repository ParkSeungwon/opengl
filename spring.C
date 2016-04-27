#include "OpenGL.h"
#include <cmath>
class Spring : public OpenGL
{
public:

protected:
	void SetupRC()
	{
		glClearColor(1.0, 1.0, 1.0, 1.0);
		glColor3f(0.0, 1.0, 0.0);
	}

	void RenderScene()
	{
		float x, y, z, angle;
		glClear(GL_COLOR_BUFFER_BIT);
		glPushMatrix();
	//	glRotatef(xRot, 1.0, 0.0, 0.0);
	//	glRotatef(yRot, 0.0, 1.0, 0.0);
		
		glBegin(GL_POINTS);
		z = -50.0;
		for(angle = 0.0; angle <= (2.0 * M_PI) * 3.0; angle += 0.1) {
			x = 50.0 * sin(angle);
			y = 50.0 * cos(angle);
			glVertex3f(x, y, z);
			z += 0.5;
		}
		glEnd();

		glPopMatrix();
		glFlush();
	}
};


int main(int argc, char** argv)
{
	Spring sp(argc, argv);
}

