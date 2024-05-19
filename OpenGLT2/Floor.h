#pragma once
#include <Windows.h> // Req
#include <gl/GL.h> // OpenGl
#include <gl/GLU.h> // OpenGL Utilities
#include "GL\freeglut.h" // freeglut library
#include "Structures.h"
#include "SceneObject.h"
#include "Constants.h"
#include <fstream>
#include <iostream>

class Floor : public SceneObject
{
private:
	Material* _material;
public:
	Floor(Mesh* mesh, Texture2D* texture, Material* material, float x, float y, float z);
	~Floor();

	void Draw();
	void Update(Camera* camera);
};

