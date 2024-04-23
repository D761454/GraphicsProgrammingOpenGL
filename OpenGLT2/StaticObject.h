#pragma once
#include <Windows.h> // Req
#include <gl/GL.h> // OpenGl
#include <gl/GLU.h> // OpenGL Utilities
#include "GL\freeglut.h" // freeglut library
#include "Structures.h"
#include "SceneObject.h"
#include <fstream>
#include <iostream>

class StaticObject : public SceneObject
{
private:
	GLfloat _rotation;
	Vector3 _position;
public:
	StaticObject(Mesh* mesh, float x, float y, float z);
	~StaticObject();

	void Draw();
	void Update();
};

