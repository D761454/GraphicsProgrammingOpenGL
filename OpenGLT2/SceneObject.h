#pragma once
#include "Structures.h"
#include "Texture2D.h"

class SceneObject
{
protected:
	Mesh* _mesh;
	Texture2D* _texture;

	GLfloat _rotation;
	Vector3 _position;
	float _rotationAxis[3] = { 0.0f, 0.0f, 0.0f };
public:
	SceneObject(Mesh* mesh, Texture2D* texture);
	virtual ~SceneObject();

	virtual void Update();
	virtual void Draw();

	Vector3 GetPosition() { return _position; };
};

