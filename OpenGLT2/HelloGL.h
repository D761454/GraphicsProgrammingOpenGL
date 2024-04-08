#pragma once
#include <Windows.h> // Req
//#include <gl/GL.h> // OpenGl
//#include <gl/GLU.h> // OpenGL Utilities
//#include "GL\freeglut.h" // freeglut library
#include "GLUTCallbacks.h"
#include <iostream>
#include <fstream>
#include "Structures.h"

using namespace std;

#define REFRESHRATE 16

class HelloGL
{
private:
	float rotationx;
	float rotationy;
	Camera* camera;

	static Vertex indexedVertices[];
	static Color indexedColors[];
	static GLushort indices[];

public:
	// constructor def
	HelloGL(int argc, char* argv[]);

	// destructor
	~HelloGL(void);

	void Display();

	void DrawIndexedCube();

	void DrawTriangleAll();

	void Keyboard(unsigned char key, int x, int y);

	void Mouse(int button, int state, int x, int y);

	void Motion(int x, int y);

	void Update();
};

