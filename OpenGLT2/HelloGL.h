#pragma once
#include <Windows.h> // Req
#include <gl/GL.h> // OpenGl
#include <gl/GLU.h> // OpenGL Utilities
#include "GL\freeglut.h" // freeglut library
#include "GLUTCallbacks.h"

class HelloGL
{
public:
	// constructor def
	HelloGL(int argc, char* argv[]);

	// destructor
	~HelloGL(void);

	void Display();

	void DrawPolygon();

	void DrawTriangle1();
	void DrawTriangle2();
	void DrawTriangle3();
	void DrawTriangle4();
	void DrawTriangle5();
	void DrawTriangle6();

	void DrawTriangleAll();
};

