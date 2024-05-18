#pragma once
#include <Windows.h> // Req
#include <gl/GL.h> // OpenGl
#include <gl/GLU.h> // OpenGL Utilities
#include "GL\freeglut.h" // freeglut library
#include "Structures.h"
#include "Texture2D.h"
#include "SceneObject.h"
#include "Constants.h"
#include <fstream>
#include <iostream>

class VoxelObject : public SceneObject
{
private:
	GLfloat _rotationSpeed = 1.0f;

	Material* _materialArray[Materials];
	Material* _material;
	Material* _materialBase;
public:
	VoxelObject(Mesh* mesh, Texture2D* texture, Material* material[Materials], int mat, float x, float y, float z);
	~VoxelObject();

	void ApplyMaterial();

	void Draw();
	void Update();
};

