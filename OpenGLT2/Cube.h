#pragma once
#include <Windows.h> // Req
#include <gl/GL.h> // OpenGl
#include <gl/GLU.h> // OpenGL Utilities
#include "GL\freeglut.h" // freeglut library
#include "Structures.h"
#include <fstream>
#include <iostream>

class Cube
{
private:
	Mesh* _mesh;

	GLfloat _rotation;
	Vector3 _position;
	GLfloat _rotationSpeed = 1.0f;
	float _rotationAxis[3] = {0.0f, 0.0f, 0.0f};

public:
	Cube(Mesh* mesh, float x, float y, float z);
	~Cube();

	void Draw();
	void Update();

	static bool Load(char* path);
};

