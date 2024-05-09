#pragma once
#include "Structures.h"
#include "SceneObject.h"
#include <iostream>

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	TreeNode* MakeTreeNode(TreeNode** root, int d);

	void DeleteTree(TreeNode** root);

	void PrintTreePreOrder(TreeNode* node);
	void PrintTreeInOrder(TreeNode* node);
	void PrintTreePostOrder(TreeNode* node);
private:
	TreeNode* root = nullptr;
};

