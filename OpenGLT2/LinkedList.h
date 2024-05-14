#pragma once
#include "Structures.h"
#include "SceneObject.h"
#include <iostream>

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	ListNode* MakeNode(ListNode** head, SceneObject* d);
	void InsertAfter(ListNode* lastNode, SceneObject* d);

	void SelectAt(ListNode* head, int pos);

	void MoveSelected(ListNode* node, int x, int y, int z);

	void DeleteList(ListNode** node);
	void DeleteSelected(ListNode** node);

	void UpdateList(ListNode* node);
	void DrawList(ListNode* node);

	int GetSize(ListNode* node, int counter);
private:
	ListNode* head = nullptr;
};

