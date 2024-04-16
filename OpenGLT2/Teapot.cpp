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

	// get line start with letter and final line start with letter, make array of num, used for vertices v and indices f

	int numVertices = 0, numIndices = 0;
	std::string data;

	while (!inFile.eof()) {
		inFile >> data;
		if (data == "v") {
			numVertices++;
		}
		else if (data == "f") {
			numIndices++;
		}
	}
	indexedVertices = new Vertex[numVertices];
	indices = new GLushort[numIndices*3];

	std::cout << numVertices << " " << numIndices << std::endl;

	fseek(stdin, 0, SEEK_SET);

	for (int i = 0; i < numVertices; i++)
	{
		inFile >> data;
		if (data == "v") {
			inFile >> indexedVertices[i].x;
			inFile >> indexedVertices[i].y;
			inFile >> indexedVertices[i].z;
		}
		else if (data == "f") {
			inFile >> indices[i];
			inFile >> indices[i];
			inFile >> indices[i];
		}
	}

	inFile.close();

	return true;
}

void Teapot::Update() {
	_rotation += _rotationSpeed;
}