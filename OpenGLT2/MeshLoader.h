#pragma once

#include "Structures.h"

namespace MeshLoader
{
	Mesh* Load(char* path);
};

namespace BasicMeshLoader {
	BasicMesh* Load(char* path);
}

namespace ComplexMeshLoader {
	Mesh* Load(char* path);
}