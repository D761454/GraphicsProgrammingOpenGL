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

struct Color {
	GLfloat r, g, b, a;
};

struct Vertex {
	GLfloat x, y, z;
};

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

	void DrawPolygon(int a, int b, int c, int d);

	void DrawIndexedCube();

	void DrawCubeArray();

	void DrawTriangleAll();

	void Keyboard(unsigned char key, int x, int y);

	void Mouse(int button, int state, int x, int y);

	void Motion(int x, int y);

	void Update();
};

