#pragma once
#include <gl/GL.h> // OpenGl
#include <gl/GLU.h> // OpenGL Utilities
#include "GL\freeglut.h" // freeglut library


struct Vector3 {
	float x, y, z;
};

struct Camera {
	Vector3 eye, center, up;
};

struct Color {
	GLfloat r, g, b;
};

struct Vertex {
	GLfloat x, y, z;
};