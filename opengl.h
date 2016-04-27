#pragma once
#include <gl.h>
#include <glut.h>
#include <string>

class OpenGL
{
public:
	OpenGL(int argc, char** argv);
	void start();

	//setter, getter
	void title(std::string title) {title_ = title;}
	std::string title() {return title_;}
	void timer(int i) {timer_ = i;}
	int timer() {return timer_;}
	
protected:
	virtual void ChangeSize(int w, int h);
	virtual	void RenderScene();
	virtual void TimerFunction(int value);
	virtual void SetupRC();

private:
	std::string title_ = "title";
	int timer_ = 10;
};

