#include "RedCube.h"

RedCube::RedCube(Mesh* mesh, Texture2D* texture, float x, float y, float z) : SceneObject(mesh, texture) {
	_rotation = 0.0f;
	_rotationSpeed = (rand() % 2) + 1;
	_rotationAxis[rand() % 3] = 1.0f;
	_position.x = x;
	_position.y = y;
	_position.z = z;
}

RedCube::~RedCube() {
	
}

void RedCube::ApplyMaterial() {
	_material = new Material();
	_material->ambient.x = 0.8; _material->ambient.y = 0.05; _material->ambient.z = 0.05; // uniform
	_material->ambient.w = 1.0;
	_material->diffuse.x = 0.8; _material->diffuse.y = 0.05; _material->diffuse.z = 0.05; // bounce off
	_material->diffuse.w = 1.0;
	_material->specular.x = 1.0; _material->specular.y = 1.0; _material->specular.z = 1.0; // shiny and localised
	_material->specular.w = 1.0;
	_material->shininess = 100.0f;
}

void RedCube::Draw() {
	if (_mesh->Vertices != nullptr && _mesh->Normals != nullptr && _mesh->Indices != nullptr && _mesh->TexCoords != nullptr) {
		glBindTexture(GL_TEXTURE_2D, _texture->GetID());
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
		glNormalPointer(GL_FLOAT, 0, _mesh->Normals);

		glTexCoordPointer(2, GL_FLOAT, 0, _mesh->TexCoords);
		ApplyMaterial();
		glMaterialfv(GL_FRONT, GL_AMBIENT, &(_material->ambient.x));
		glMaterialfv(GL_FRONT, GL_DIFFUSE, &(_material->diffuse.x));
		glMaterialfv(GL_FRONT, GL_SPECULAR, &(_material->specular.x));
		glMaterialfv(GL_FRONT, GL_SHININESS, &(_material->shininess));

		glPushMatrix();
		glTranslatef(_position.x, _position.y, _position.z);
		glRotatef(_rotation, _rotationAxis[0], _rotationAxis[1], _rotationAxis[2]);
		glDrawElements(GL_TRIANGLES, _mesh->IndexCount, GL_UNSIGNED_SHORT, _mesh->Indices);
		glPopMatrix();

		glDisableClientState(GL_NORMAL_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}
}

void RedCube::Update() {
	_rotation += _rotationSpeed;
}