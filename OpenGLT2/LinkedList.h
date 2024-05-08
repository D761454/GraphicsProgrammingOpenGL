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

	void DeleteList(ListNode** node);
	void DeleteAt(ListNode* node, int pos);
	void DeleteAtPos(ListNode** head, Camera* camera);

	void UpdateList(ListNode* node);
	void DrawList(ListNode* node);
private:
	ListNode* head = nullptr;
};

