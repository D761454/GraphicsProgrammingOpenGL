#include "Cube.h"

Vertex Cube::indexedVertices[] = { // incompatible with TexCoords, need to separate vertices, modelling tools will do this for me
	1,1,1,		-1,1,1,
	-1,-1,1,	1,-1,1,
	1,-1,-1,	1,1,-1,
	-1,1,-1,	-1,-1,-1
};

Color Cube::indexedColors[] = {
	1,1,1,1,	1,1,0,1,
	1,0,0,1,	1,0,1,1,
	0,0,1,1,	0,1,1,1,
	0,1,0,1,	0,0,0,1
};

GLushort Cube::indices[] = {
	0,1,2,	2,3,0, // front
	0,3,4,	4,5,0, // right
	0,5,6,	6,1,0, // top
	1,6,7,	7,2,1, // left
	7,4,3,	3,2,7, // bottom
	4,7,6,	6,5,4 // back
};

Cube::Cube() {

}

Cube::~Cube() {

}

void Cube::Draw() {

}

void Cube::Update() {

}