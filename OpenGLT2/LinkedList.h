#pragma once
#include "Structures.h"
#include <iostream>

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	ListNode* MakeNode(ListNode** head, int d);
	void InsertAfter(ListNode* lastNode, int d);

	void DeleteList(ListNode** node);
	void DeleteAt(ListNode* node, int pos);

	ListNode* GetNode(ListNode* node, int pos);
	ListNode* Find(ListNode* node, int val);
	void PrintList(ListNode* node);
private:
	ListNode* head = nullptr;
};

