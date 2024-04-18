#include "Teapot.h"

Vertex* Teapot::indexedVertices = nullptr;

Color* Teapot::indexedColors = nullptr;

GLushort* Teapot::indices = nullptr;

int Teapot::numVertices = 0;
int Teapot::numColors = 0;
int Teapot::numIndices = 0;

Teapot::Teapot(float x, float y, float z) {
	_rotation = 0.0f;
	_rotationSpeed = (rand() % 2) + 1;
	_rotationAxis[rand() % 3] = 1.0f;
	_position.x = x;
	_position.y = y;
	_position.z = z;
}

Teapot::~Teapot() {
	delete[] indexedVertices;
	indexedVertices = nullptr;
	delete[] indexedColors;
	indexedColors = nullptr;
	delete[] indices;
	indices = nullptr;
}

void Teapot::Draw() {
	if (indexedVertices != nullptr && indexedColors != nullptr && indices != nullptr) {
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, indexedVertices);
		glColorPointer(3, GL_FLOAT, 0, indexedColors);

		glPushMatrix();
		glTranslatef(_position.x, _position.y, _position.z);
		glRotatef(_rotation, _rotationAxis[0], _rotationAxis[1], _rotationAxis[2]);
		glDrawElements(GL_TRIANGLES, numIndices, GL_UNSIGNED_SHORT, indices); // ni = 36
		glPopMatrix();

		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
	}
}

bool Teapot::Load(char* path) {
	std::ifstream inFile;
	inFile.open(path);
	if (!inFile.good()) {
		std::cerr << "Can't open text file " << path << std::endl;
		return false;
	}

	int numVertices = 0, numIndices = 0;
	std::string data;

	// 
	while (!inFile.eof()) {
		inFile >> data;
		if (data == "v") {
			numVertices++;
		}
		else if (data == "f") {
			numIndices+=3;
		}
	}
	indexedVertices = new Vertex[numVertices];
	indices = new GLushort[numIndices];

	std::cout << numVertices << " " << numIndices << std::endl;

	inFile.clear();
	inFile.seekg(0, inFile.beg);

	for (int i = 0; i < numVertices; i++)
	{
		inFile >> data; // just captures irrelevenat line starters
		inFile >> indexedVertices[i].x;
		inFile >> indexedVertices[i].y;
		inFile >> indexedVertices[i].z;
		std::cout << indexedVertices[i].x << " " << indexedVertices[i].y << " " << indexedVertices[i].z << std::endl;
	}

	for (int i = 0; i < numIndices; i+=3) { // error : only outputting 52685 repeatedly
		inFile >> data; // just captures irrelevenat line starters
		inFile >> indices[i];
		inFile >> indices[i+1];
		inFile >> indices[i+2];
		std::cout << indices[i] << " " << indices[i+1] << " " << indices[i+2] << std::endl;
	}

	// temporary
	indexedColors = new Color[8];
	indexedColors[0] = { 1,1,1 };
	indexedColors[1] = { 1,1,0 };
	indexedColors[2] = { 1,0,0 };
	indexedColors[3] = { 1,0,1 };
	indexedColors[4] = { 0,0,1 };
	indexedColors[5] = { 0,1,1 };
	indexedColors[6] = { 0,1,0 };
	indexedColors[7] = { 0,0,0 };


	inFile.close();

	return true;
}

void Teapot::Update() {
	_rotation += _rotationSpeed;
}