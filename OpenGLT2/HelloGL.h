#pragma once
#include <Windows.h> // Req
#include <gl/GL.h> // OpenGl
#include <gl/GLU.h> // OpenGL Utilities
#include "GL\freeglut.h" // freeglut library
#include "GLUTCallbacks.h"

#define REFRESHRATE 16

struct Vector3 {
	float x, y, z;
};

struct Camera {
	Vector3 eye, center, up;
};

class HelloGL
{
private:
	float rotationx;
	float rotationy;
	Camera* camera;

	// temp s
	struct point3D {
		float x, y, z;
	};

	struct colour {
		float r, g, b, a;
	};

	struct polygon {
		int a, b, c, d;
	};

	point3D* vertices = new point3D[8]{
		{-0.25f, 0.25f, -4.0f}, // ftl		0
		{-0.25f, -0.25f, -4.0f}, //fbl		1
		{0.25f, -0.25f, -4.0f}, // fbr		2
		{0.25f, 0.25f, -4.0f}, // ftr		3
		{-0.25f, 0.25f, -5.0f}, // btl		4
		{-0.25f, -0.25f, -5.0f}, // bbl	5
		{0.25f, -0.25f, -5.0f}, // bbr		6
		{0.25f, 0.25f, -5.0f} // btr		7
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
	// temp e

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

