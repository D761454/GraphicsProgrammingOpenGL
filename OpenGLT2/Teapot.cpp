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

	// edit for obj file format

	inFile >> numVertices;
	indexedVertices = new Vertex[numVertices];
	for (int i = 0; i < numVertices; i++)
	{
		inFile >> indexedVertices[i].x;
		inFile >> indexedVertices[i].y;
		inFile >> indexedVertices[i].z;
	}

	inFile >> numColors;
	indexedColors = new Color[numColors];
	for (int i = 0; i < numColors; i++)
	{
		inFile >> indexedColors[i].r;
		inFile >> indexedColors[i].g;
		inFile >> indexedColors[i].b;
	}

	inFile >> numIndices;
	indices = new GLushort[numIndices];
	for (int i = 0; i < numIndices; i++)
	{
		inFile >> indices[i];
	}

	inFile.close();

	return true;
}

void Teapot::Update() {
	_rotation += _rotationSpeed;
}