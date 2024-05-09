#pragma once
#include "Structures.h"
#include "SceneObject.h"
#include <iostream>

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	TreeNode* MakeNode(TreeNode** root, int d);

	void DeleteTree(ListNode** root);


private:
	ListNode* head = nullptr;
};

