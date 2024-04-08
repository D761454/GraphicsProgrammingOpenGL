#pragma once
#include <Windows.h> // Req
#include <gl/GL.h> // OpenGl
#include <gl/GLU.h> // OpenGL Utilities
#include "GL\freeglut.h" // freeglut library
#include "Structures.h"

class Cube
{
private:
	static Vertex indexedVertices[];
	static Color indexedColors[];
	static GLushort indices[];

	GLfloat _rotation;
	Vector3 _position;
	GLfloat _rotationSpeed = 1.0f;;

public:
	Cube(float x, float y, float z);
	~Cube();

	void Draw();
	void Update();
};

