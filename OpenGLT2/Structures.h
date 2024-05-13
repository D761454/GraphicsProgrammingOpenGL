#pragma once
#include <Windows.h> // Req
#include <gl/GL.h> // OpenGl
#include <gl/GLU.h> // OpenGL Utilities
#include "GL\freeglut.h" // freeglut library

class SceneObject;

struct TextPos {
	float x, y;
};

struct Vector3 {
	float x, y, z;
};

struct Vector4 {
	float x, y, z, w;
	Vector4(float x, float y, float z, float w) {
		this->x = x; this->y = y; this->z = z; this->w = w;
	}
	Vector4() {
		x = 0; y = 0; z = 0; w = 0;
	}
};

struct Lighting {
	Vector4 ambient, diffuse, specular;
};

struct Material {
	Vector4 ambient, diffuse, specular;
	GLfloat shininess;
	Material(Vector4 ambient, Vector4 diffuse, Vector4 specular, GLfloat shininess) {
		this->ambient = ambient, this->diffuse = diffuse, this->specular = specular;
		this->shininess = shininess;
	}
	Material() {
		ambient = Vector4(); diffuse = Vector4(); specular = Vector4(); shininess = 0.0f;
	}
};

struct Camera {
	Vector3 eye, center, up;
	float pitch, yaw;
	float angleX, angleY;
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
	Vector3* Normals;
	GLushort* Indices;
	int VertexCount, NormalCount, IndexCount, TexCoordCount;
	TexCoord* TexCoords;
};

struct BasicMesh{
	Vertex* Vertices;
	Color* Colors;
	GLushort* Indices;
	int VertexCount, ColorCount, IndexCount;
};

struct ListNode {
	SceneObject* data = nullptr;
	ListNode* next = nullptr;
};

struct TreeNode {
	SceneObject* data = nullptr;
	TreeNode* right = nullptr;
	TreeNode* left = nullptr;
};