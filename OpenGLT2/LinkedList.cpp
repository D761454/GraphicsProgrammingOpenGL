#include "LinkedList.h"

LinkedList::LinkedList() {

}

LinkedList::~LinkedList() {

}

ListNode* LinkedList::MakeNode(ListNode** head, SceneObject* d) {
	ListNode* newNode = new ListNode;
	ListNode* last = *head;

	newNode->data = d;
	newNode->next = nullptr;

	if (*head == nullptr) {
		*head = newNode;
		return newNode;
	}

	while (last->next != nullptr) {
		last = last->next;
	}

	last->next = newNode;

	return newNode;
}

void LinkedList::InsertAfter(ListNode* lastNode, SceneObject* d) {
	ListNode* newNode = new ListNode;

	newNode->data = d;
	newNode->next = lastNode->next;
	lastNode->next = newNode;
}

// recursive
void LinkedList::DeleteList(ListNode** node) {
	ListNode* pTemp = *node;

	if (pTemp != nullptr) {
		DeleteList(&pTemp->next);
		delete pTemp;
	}
	*node = nullptr;
}

void LinkedList::DeleteAt(ListNode* node, int pos) {
	int count = 0;
	ListNode* pTemp;

	// find item before target
	// if target exists
	// get item after target
	// set pointer for item before target to point to item after target
	// if item after target doesnt exist, set item before target to point to nullptr

	while (node != nullptr) {
		if (count == pos - 1) {
			if (node->next != nullptr) {
				pTemp = node->next;
				if (pTemp->next != nullptr) {
					node->next = pTemp->next;
				}
				else {
					node->next = nullptr;
				}

				delete pTemp;
			}
		}
		count++;
		node = node->next;
	}
}

// recursive
void LinkedList::UpdateList(ListNode* node) {
	if (node != nullptr) {
		node->data->Update();
		UpdateList(node->next);
	}
	else {
		std::cout << "| NULL |" << std::endl;
	}
}

// recursive
void LinkedList::DrawList(ListNode* node) {
	if (node != nullptr) {
		node->data->Update();
		DrawList(node->next);
	}
	else {
		std::cout << "| NULL |" << std::endl;
	}
}