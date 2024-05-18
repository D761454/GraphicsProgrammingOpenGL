#include "VoxelObject.h"

VoxelObject::VoxelObject(Mesh* mesh, Texture2D* texture, Material* material[Materials], int mat, float x, float y, float z) : SceneObject(mesh, texture) {
	_materialBase = material[mat];
	for (int i = 0; i < Materials; i++)
	{
		_materialArray[i] = material[i];
	}
	_rotation = 0.0f;
	_rotationSpeed = (rand() % 2) + 1;
	_rotationAxis[rand() % 3] = 1.0f;
	_position.x = x;
	_position.y = y;
	_position.z = z;
}

VoxelObject::~VoxelObject() {

}

void VoxelObject::ApplyMaterial() {
	if (_selected) {
		_material = _materialArray[6];
	}
	else {
		_material = _materialBase;
	}
}

void VoxelObject::Draw() {
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

void VoxelObject::Update() {
	
}