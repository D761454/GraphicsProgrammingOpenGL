#include "LinkedList.h"

LinkedList::LinkedList() {

}

LinkedList::~LinkedList() {

}

ListNode* LinkedList::MakeNode(ListNode** head, int d) {
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

void LinkedList::InsertAfter(ListNode* lastNode, int d) {
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

ListNode* LinkedList::GetNode(ListNode* node, int pos) {
	int count = 0;

	while (node != nullptr) {
		if (count == pos) {
			std::cout << "Data stored at position " << pos << " is: " << node->data << std::endl;
			return node;
		}
		count++;
		node = node->next;
	}
	std::cout << pos << " was not a valid position..." << std::endl;
	return nullptr;
}

// recursive
ListNode* LinkedList::Find(ListNode* node, int val) {
	if (node != nullptr) {
		if (node->data == val) {
			std::cout << val << " is present in the list." << std::endl;
			return node;
		}
		Find(node->next, val);
	}
	else {
		std::cout << val << " was not a valid item..." << std::endl;
		return nullptr;
	}
}

// recursive
void LinkedList::PrintList(ListNode* node) {
	if (node != nullptr) {
		std::cout << "| " << node->data << " |-->";
		PrintList(node->next);
	}
	else {
		std::cout << "| NULL |" << std::endl;
	}
}