#pragma once
#include <Windows.h> // Req
#include <gl/GL.h> // OpenGl
#include <gl/GLU.h> // OpenGL Utilities
#include "GL\freeglut.h" // freeglut library
#include "Structures.h"
#include "Texture2D.h"
#include "SceneObject.h"
#include <fstream>
#include <iostream>

class RedCube : public SceneObject
{
private:
	GLfloat _rotationSpeed = 1.0f;

	Material* _material;

	bool _selected = false;
public:
	RedCube(Mesh* mesh, Texture2D* texture, float x, float y, float z);
	~RedCube();

	void ApplyMaterial();

	void Draw();
	void Update();

	void Selected(bool selected) { _selected = selected; };
};

