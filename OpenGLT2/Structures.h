#pragma once
#include <Windows.h> // Req
#include <gl/GL.h> // OpenGl
#include <gl/GLU.h> // OpenGL Utilities
#include "GL\freeglut.h" // freeglut library


struct Vector3 {
	float x, y, z;
};

struct Vector4 {
	float x, y, z, w;
};

struct Lighting {
	Vector4 ambient, diffuse, specular;
};

struct Material {
	Vector4 ambient, diffuse, specular;
	GLfloat shininess;
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