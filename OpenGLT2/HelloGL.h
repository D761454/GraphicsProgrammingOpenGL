#pragma once
#include <Windows.h> // Req
#include <gl/GL.h> // OpenGl
#include <gl/GLU.h> // OpenGL Utilities
#include "GL\freeglut.h" // freeglut library
#include "GLUTCallbacks.h"
#include <iostream>
#include <fstream>
#include "Structures.h"
#include "RedCube.h"
#include "StaticObject.h"
#include "MeshLoader.h"
#include "SceneObject.h"
#include <string>
#include "LinkedList.h"

#define _USE_MATH_DEFINES
#include <math.h> // pi
#include "Constants.h"

using namespace std;

#define REFRESHRATE 16

class HelloGL
{
private:
	Camera* camera;

	LinkedList* list = new LinkedList;
	ListNode* head = nullptr;

	Vector4* _lightPosition;
	Lighting* _lightData;

	float fps = 0.0f;
	float deltaTime = 0.0f;
	int currentTime = 0;
	int lastTime = 0;
	//int frames = 0;
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

	void DrawString(const char* text, TextPos* position, Color* color);

	Vector3 Normalize(Vector3 one, Vector3 two);
	Vector3 Normalize(Vector3 one);
	Vector3 CrossProduct(Vector3 one, Vector3 two);
	Vector3 Multiply(Vector3 vector, float scalar);
	Vector3 Add(Vector3 one, Vector3 two);
	Vector3 Subtract(Vector3 one, Vector3 two);
	Vector3 CamLook(Camera* camera);
};

