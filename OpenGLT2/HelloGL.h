#pragma once
#include <Windows.h> // Req
#include <gl/GL.h> // OpenGl
#include <gl/GLU.h> // OpenGL Utilities
#include "GL\freeglut.h" // freeglut library
#include "GLUTCallbacks.h"

#define REFRESHRATE 16

class HelloGL
{
private:
	float rotation;

	struct point3D;

	struct colour;

	struct polygon;

	point3D* vertices;
	colour* colours;
	polygon* indices;

public:
	// constructor def
	HelloGL(int argc, char* argv[]);

	// destructor
	~HelloGL(void);

	void Display();

	void DrawPolygon(int a, int b, int c, int d);

	void DrawTriangleBase(float x1, float y1, float x2, float y2, float x3, float y3, float r, float g, float b, float a);

	void DrawTriangle1();
	void DrawTriangle2();
	void DrawTriangle3();
	void DrawTriangle4();
	void DrawTriangle5();
	void DrawTriangle6();

	void DrawTriangleAll();

	void DrawHexagon();

	void Draw3DCube();

	void DrawPentagon();

	void Keyboard(unsigned char key, int x, int y);

	void Mouse(int button, int state, int x, int y);

	void Motion(int x, int y);

	void Update();
};

