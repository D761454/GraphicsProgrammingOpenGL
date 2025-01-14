#include "StaticObject.h"

StaticObject::StaticObject(Mesh* mesh, float x, float y, float z) : SceneObject(mesh, nullptr) {
	_rotation = 0.0f;
	_rotationAxis[rand() % 3] = 1.0f;
	_position.x = x;
	_position.y = y;
	_position.z = z;
}

StaticObject::~StaticObject() {
	
}

void StaticObject::Draw() {
	if (_mesh->Vertices != nullptr && _mesh->Normals != nullptr && _mesh->Indices != nullptr) {
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
		glNormalPointer(GL_FLOAT, 0, _mesh->Normals);

		glPushMatrix();
		glTranslatef(_position.x, _position.y, _position.z);
		glRotatef(_rotation, _rotationAxis[0], _rotationAxis[1], _rotationAxis[2]);
		glDrawElements(GL_TRIANGLES, _mesh->IndexCount, GL_UNSIGNED_SHORT, _mesh->Indices); // ni = 36
		glPopMatrix();

		glDisableClientState(GL_NORMAL_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
	}
}

void StaticObject::Update() {

}