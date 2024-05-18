#include "SceneObject.h"

SceneObject::SceneObject(Mesh* mesh, Texture2D* texture) {
	_mesh = mesh;
	_texture = texture;
}
SceneObject::SceneObject(VoxelMesh* mesh, Texture2D* texture) {
	_vMesh = mesh;
	_texture = texture;
}


SceneObject::~SceneObject() {

}

void SceneObject::Update() {

}

void SceneObject::Draw() {

}