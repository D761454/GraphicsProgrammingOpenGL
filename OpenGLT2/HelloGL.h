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
	float rotationx;
	float rotationy;

	struct point3D {
		float x;
		float y;
		float z;
	};

	struct colour {
		float r;
		float g;
		float b;
		float a;
	};

	struct polygon {
		int a;
		int b;
		int c;
		int d;
	};

	point3D* vertices = new point3D[8]{
		{-0.25f, 0.25f, 0.25f}, // ftl		0
		{-0.25f, -0.25f, 0.25f}, //fbl		1
		{0.25f, -0.25f, 0.25f}, // fbr		2
		{0.25f, 0.25f, 0.25f}, // ftr		3
		{-0.25f, 0.25f, -0.25f}, // btl		4
		{-0.25f, -0.25f, -0.25f}, // bbl	5
		{0.25f, -0.25f, -0.25f}, // bbr		6
		{0.25f, 0.25f, -0.25f} // btr		7
	}; // vertices
	colour* colours = new colour[6] {
		{1.0f, 1.0f, 1.0f, 1.0f},
		{1.0f, 0.0f, 0.0f, 1.0f},
		{0.0f, 1.0f, 0.0f, 1.0f},
		{0.0f, 0.0f, 1.0f, 1.0f},
		{1.0f, 1.0f, 0.0f, 1.0f},
		{0.0f, 1.0f, 1.0f, 1.0f}
	};
	polygon* indices = new polygon[6] {
		{0, 1, 2, 3}, // f
		{0, 4, 5, 1}, // l
		{3, 2, 6, 7}, // r
		{0, 3, 7, 4}, // t
		{1, 2, 6, 5}, // b
		{4, 5, 6, 7} // ba
	}; // faces

public:
	// constructor def
	HelloGL(int argc, char* argv[]);

	// destructor
	~HelloGL(void);

	void Display();

	void DrawPolygon(int a, int b, int c, int d);

	void DrawCube();

	void DrawTriangleAll();

	void DrawHexagon();

	void Draw3DCube();

	void DrawPentagon();

	void Keyboard(unsigned char key, int x, int y);

	void Mouse(int button, int state, int x, int y);

	void Motion(int x, int y);

	void Update();
};

