#include "Floor.h"

Floor::Floor(Mesh* mesh, Texture2D* texture, Material* material, float x, float y, float z) : SceneObject(mesh, texture) {
	_position.x = x;
	_position.y = y;
	_position.z = z;
	_material = material;
}

Floor::~Floor() {

}

void Floor::Draw() {
	if (_mesh->Vertices != nullptr && _mesh->Normals != nullptr && _mesh->Indices != nullptr && _mesh->TexCoords != nullptr) {
		glBindTexture(GL_TEXTURE_2D, _texture->GetID());
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
		glNormalPointer(GL_FLOAT, 0, _mesh->Normals);

		glTexCoordPointer(2, GL_FLOAT, 0, _mesh->TexCoords);

		glMaterialfv(GL_FRONT, GL_AMBIENT, &(_material->ambient.x));
		glMaterialfv(GL_FRONT, GL_DIFFUSE, &(_material->diffuse.x));
		glMaterialfv(GL_FRONT, GL_SPECULAR, &(_material->specular.x));
		glMaterialfv(GL_FRONT, GL_SHININESS, &(_material->shininess));

		glPushMatrix();
		glTranslatef(_position.x, _position.y, _position.z);
		glDrawElements(GL_TRIANGLES, _mesh->IndexCount, GL_UNSIGNED_SHORT, _mesh->Indices);
		glPopMatrix();

		glDisableClientState(GL_NORMAL_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}
}

void Floor::Update() {
	
}