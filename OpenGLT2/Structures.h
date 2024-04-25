#pragma once
#include <Windows.h> // Req
#include <gl/GL.h> // OpenGl
#include <gl/GLU.h> // OpenGL Utilities
#include "GL\freeglut.h" // freeglut library


struct Vector3 {
	float x, y, z;
};

struct Camera {
	Vector3 eye, center, up;
	float angleX, angleY, radius;
};

struct Color {
	GLfloat r, g, b;
};

struct Vertex {
	GLfloat x, y, z;
};

struct TexCoord {
	GLfloat u, v;
};

struct Mesh {
	Vertex* Vertices;
	Color* Colors;
	GLushort* Indices;
	int VertexCount, ColorCount, IndexCount, TexCoordCount;
	TexCoord* TexCoords;
};