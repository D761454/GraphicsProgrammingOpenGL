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

	void SelectNode(ListNode** head, Camera* camera);

	void DeleteList(ListNode** node);
	void DeleteSelected(ListNode** head, Camera* camera);

	void UpdateList(ListNode* node);
	void DrawList(ListNode* node);
private:
	ListNode* head = nullptr;
};

