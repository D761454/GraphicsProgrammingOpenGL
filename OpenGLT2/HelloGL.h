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

	point3D* vertices = new point3D[4]{
		{-0.5f, 0.5f, 0.0f},
		{-0.5f, -0.5f, 0.0f},
		{0.5f, -0.5f, 0.0f},
		{0.5f, 0.5f, 0.0f}
	}; // vertices
	colour* colours = new colour[1] {
		{1.0f, 1.0f, 1.0f, 1.0f}
	};
	polygon* indices = new polygon[1] {
		{0, 1, 2, 3}
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

