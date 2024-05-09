#pragma once
#include "Structures.h"
#include "SceneObject.h"
#include <iostream>

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	TreeNode* MakeTreeNode(TreeNode** root, SceneObject* d);

	void DeleteTree(TreeNode** root);

	void PrintTreePreOrder(TreeNode* node);
	void PrintTreeInOrder(TreeNode* node);
	void PrintTreePostOrder(TreeNode* node);

	void UpdateTree(TreeNode* root);
	void DrawTree(TreeNode* root);
private:
	TreeNode* root = nullptr;
};

