#include "MeshLoader.h"

#include <iostream>
#include <fstream>

using namespace std;

namespace MeshLoader
{
	void LoadVertices(ifstream& inFile, Mesh& mesh);
	void LoadNormals(ifstream& inFile, Mesh& mesh);
	void LoadTexCoords(ifstream& inFile, Mesh& mesh);
	void LoadIndices(ifstream& inFile, Mesh& mesh);

	void LoadVertices(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.VertexCount;

		if (mesh.VertexCount > 0)
		{
			mesh.Vertices = new Vertex[mesh.VertexCount];

			for (int i = 0; i < mesh.VertexCount; i++)
			{
				inFile >> mesh.Vertices[i].x;
				inFile >> mesh.Vertices[i].y;
				inFile >> mesh.Vertices[i].z;
			}
		}
	}

	void LoadNormals(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.NormalCount;

		if (mesh.NormalCount > 0) {
			mesh.Normals = new Vector3[mesh.NormalCount];

			for (int i = 0; i < mesh.NormalCount; i++) {
				inFile >> mesh.Normals[i].x;
				inFile >> mesh.Normals[i].y;
				inFile >> mesh.Normals[i].z;
			}
		}
	}

	void LoadTexCoords(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.TexCoordCount;

		if (mesh.TexCoordCount > 0) {
			mesh.TexCoords = new TexCoord[mesh.TexCoordCount];

			for (int i = 0; i < mesh.TexCoordCount; i++)
			{
				inFile >> mesh.TexCoords[i].u;
				inFile >> mesh.TexCoords[i].v;
			}
		}
	}

	void LoadIndices(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.IndexCount;

		if (mesh.IndexCount > 0) {
			mesh.Indices = new GLushort[mesh.IndexCount];

			for (int i = 0; i < mesh.IndexCount; i++)
			{
				inFile >> mesh.Indices[i];
			}
		}
	}

	Mesh* MeshLoader::Load(char* path)
	{
		Mesh* mesh = new Mesh();

		ifstream inFile;

		inFile.open(path);

		if (!inFile.good())  
		{
			cerr  << "Can't open texture file " << path << endl;
			return nullptr;
		}

		LoadVertices(inFile, *mesh);
		LoadTexCoords(inFile, *mesh);
		LoadNormals(inFile, *mesh);
		LoadIndices(inFile, *mesh);

		return mesh;
	}
}

namespace BasicMeshLoader // used for non textured and non normal things
{
	void LoadVertices(ifstream& inFile, BasicMesh& mesh);
	void LoadIndices(ifstream& inFile, BasicMesh& mesh);

	void LoadVertices(ifstream& inFile, BasicMesh& mesh)
	{
		inFile >> mesh.VertexCount;

		if (mesh.VertexCount > 0)
		{
			mesh.Vertices = new Vertex[mesh.VertexCount];

			for (int i = 0; i < mesh.VertexCount; i++)
			{
				inFile >> mesh.Vertices[i].x;
				inFile >> mesh.Vertices[i].y;
				inFile >> mesh.Vertices[i].z;
			}
		}
	}

	void LoadIndices(ifstream& inFile, BasicMesh& mesh)
	{
		inFile >> mesh.IndexCount;

		if (mesh.IndexCount > 0) {
			mesh.Indices = new GLushort[mesh.IndexCount];

			for (int i = 0; i < mesh.IndexCount; i++)
			{
				inFile >> mesh.Indices[i];
			}
		}
	}

	BasicMesh* BasicMeshLoader::Load(char* path)
	{
		BasicMesh* mesh = new BasicMesh();

		ifstream inFile;

		inFile.open(path);

		if (!inFile.good())
		{
			cerr << "Can't open texture file " << path << endl;
			return nullptr;
		}

		LoadVertices(inFile, *mesh);
		LoadIndices(inFile, *mesh);

		return mesh;
	}
}

namespace OddMeshLoader
{
	void LoadVertices(ifstream& inFile, Mesh& mesh);
	void LoadNormals(ifstream& inFile, Mesh& mesh);
	void LoadTexCoords(ifstream& inFile, Mesh& mesh);
	void LoadIndices(ifstream& inFile, Mesh& mesh);

	void LoadVertices(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.VertexCount;

		if (mesh.VertexCount > 0)
		{
			mesh.Vertices = new Vertex[mesh.VertexCount];

			for (int i = 0; i < mesh.VertexCount; i++)
			{
				inFile >> mesh.Vertices[i].x;
				inFile >> mesh.Vertices[i].y;
				inFile >> mesh.Vertices[i].z;
			}
		}
	}

	void LoadNormals(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.NormalCount;

		if (mesh.NormalCount > 0) {
			mesh.Normals = new Vector3[mesh.VertexCount];

			Vector3 temp; int count = 0;

			for (int i = 0; i < mesh.NormalCount; i++) {
				inFile >> temp.x;
				inFile >> temp.y;
				inFile >> temp.z;
				for (int j = 0; j < mesh.VertexCount / 6; j++)
				{
					mesh.Normals[count] = temp;
					count++;
				}
			}
		}
	}

	void LoadTexCoords(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.TexCoordCount;

		if (mesh.TexCoordCount > 0) {
			mesh.TexCoords = new TexCoord[mesh.VertexCount];

			TexCoord temp;

			for (int i = 0; i < mesh.TexCoordCount; i++)
			{
				inFile >> temp.u;
				inFile >> temp.v;
				for (int j = 0; j < mesh.VertexCount; j++)
				{
					mesh.TexCoords[j] = temp;
				}
			}
		}
	}

	void LoadIndices(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.IndexCount;

		if (mesh.IndexCount > 0) {
			mesh.Indices = new GLushort[mesh.IndexCount / 3];

			GLushort temp;

			for (int i = 0; i < mesh.IndexCount / 3; i++)
			{
				inFile >> mesh.Indices[i];
				inFile >> temp;
				inFile >> temp;
			}
		}
	}

	Mesh* OddMeshLoader::AltLoad(char* path)
	{
		Mesh* mesh = new Mesh();

		ifstream inFile;

		inFile.open(path);

		if (!inFile.good())
		{
			cerr << "Can't open texture file " << path << endl;
			return nullptr;
		}

		LoadVertices(inFile, *mesh);
		LoadTexCoords(inFile, *mesh);
		LoadNormals(inFile, *mesh);
		LoadIndices(inFile, *mesh);

		return mesh;
	}
}