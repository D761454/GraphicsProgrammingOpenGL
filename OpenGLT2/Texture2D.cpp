#include "Texture2D.h"

Texture2D::Texture2D() {

}

Texture2D::~Texture2D() {

}

bool Texture2D::Load(char* path, int width, int height) {
	char* tempTextureData; int fileSize; ifstream inFile;
	_width = width; _height = height;
	inFile.open(path, ios::binary);

	if (!inFile.good()) {
		cerr << "Can't open texture file: " << path << endl;
		return false;
	}

	inFile.seekg(0, ios::end); // seek to end of file
	fileSize = (int)inFile.tellg(); // get current pos in file - End = total filesize
	tempTextureData = new char[fileSize]; // create new array to store data
	inFile.seekg(0, ios::beg); // seek back to beginning of file
	inFile.read(tempTextureData, fileSize); // read in all data at once
	inFile.close();

	cout << path << " Loaded." << endl;

	glGenTextures(1, &_ID); // get next texture ID
	glBindTexture(GL_TEXTURE_2D, _ID); // bind texture to ID
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, tempTextureData); // specify details of our texture image

	delete[] tempTextureData; // clear up unneeded data
	return true;
}
