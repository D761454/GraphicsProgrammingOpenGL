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

class Skybox : public SceneObject
{
private:
	Material* _material;
public:
	Skybox(Mesh* mesh, Texture2D* texture, Material* material, float x, float y, float z);
	~Skybox();

	void Draw();
	void Update(Camera* camera);
};

