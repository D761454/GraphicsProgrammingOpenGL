#pragma once
#include <Windows.h> // Req
#include <gl/GL.h> // OpenGl
#include <gl/GLU.h> // OpenGL Utilities
#include "GL\freeglut.h" // freeglut library
#include "GLUTCallbacks.h"
#include <iostream>
#include <fstream>
#include "Structures.h"
#include "Cube.h"
#include "StaticObject.h"
#include "MeshLoader.h"
#include "SceneObject.h"
#include "Teapot.h"

#include "Constants.h"

using namespace std;

#define REFRESHRATE 16

class HelloGL
{
private:
	Camera* camera;

	SceneObject* objects[10];

	Teapot* teapot;

	Vector4* _lightPosition;
	Lighting* _lightData;
public:
	// constructor def
	HelloGL(int argc, char* argv[]);

	void InitObjects();
	void InitGL(int argc, char* argv[]);

	void InitLighting();

	// destructor
	~HelloGL(void);

	void Display();

	void Keyboard(unsigned char key, int x, int y);

	void Mouse(int button, int state, int x, int y);

	void Motion(int x, int y);

	void Update();
};

