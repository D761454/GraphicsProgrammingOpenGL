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
	//Mesh* _mesh;
	GLfloat _rotation;
	Vector3 _position;
	GLfloat _rotationSpeed = 1.0f;
	float _rotationAxis[3] = {0.0f, 0.0f, 0.0f};

	Material* _material;
public:
	RedCube(Mesh* mesh, Texture2D* texture, float x, float y, float z);
	~RedCube();

	void ApplyMaterial();

	void Draw();
	void Update();
};

