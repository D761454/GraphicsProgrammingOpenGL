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
};

