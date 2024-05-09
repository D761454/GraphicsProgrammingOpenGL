#include "BinaryTree.h"

BinaryTree::BinaryTree() {

}

BinaryTree::~BinaryTree() {

}

TreeNode* BinaryTree::MakeTreeNode(TreeNode** root, int d) {
	TreeNode* newNode = new TreeNode;
	TreeNode* last = *root;

	bool placed = false;

	newNode->data = d;
	newNode->left = nullptr;
	newNode->right = nullptr;

	if (*root == nullptr) {
		*root = newNode;
		return newNode;
	}

	while (!placed) {
		if (newNode->data > last->data) {
			if (last->right != nullptr) {
				last = last->right;
			}
			else {
				last->right = newNode;
				placed = true;
				return newNode;
			}
		}
		else if (newNode->data < last->data) {
			if (last->left != nullptr) {
				last = last->left;
			}
			else {
				last->left = newNode;
				placed = true;
				return newNode;
			}
		}
		else {
			last = last->left;
		}
	}
}

void BinaryTree::DeleteTree(TreeNode** root) {
	TreeNode* pTemp = *root;

	if (pTemp != nullptr) {
		DeleteTree(&pTemp->left);
		DeleteTree(&pTemp->right);
		delete pTemp;
	}

	*root = nullptr;
}

void BinaryTree::PrintTreePreOrder(TreeNode* node) {
	if (node != NULL) {
		cout << node->data << " --> ";
		PrintTreePreOrder(node->left);
		PrintTreePreOrder(node->right);
	}
}

void BinaryTree::PrintTreeInOrder(TreeNode* node) {
	if (node != NULL) {
		PrintTreeInOrder(node->left);
		cout << node->data << " --> ";
		PrintTreeInOrder(node->right);
	}
}

void BinaryTree::PrintTreePostOrder(TreeNode* node) {
	if (node != NULL) {
		PrintTreePostOrder(node->left);
		PrintTreePostOrder(node->right);
		cout << node->data << " --> ";
	}
}
