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

void LinkedList::DeleteAtPos(ListNode** head, Camera* camera) {
	ListNode* pTemp = *head;

	if (pTemp != nullptr) {
		// head
		if (pTemp->data->GetPosition().x <= camera->center.x + 5 && pTemp->data->GetPosition().x >= camera->center.x - 5 &&
			pTemp->data->GetPosition().y <= camera->center.y + 5 && pTemp->data->GetPosition().y >= camera->center.y - 5 &&
			pTemp->data->GetPosition().z <= camera->center.z + 5 && pTemp->data->GetPosition().z >= camera->center.z - 5) {
			delete pTemp;
			*head = nullptr;
		}
		// other
		else if (pTemp->next->data->GetPosition().x <= camera->center.x + 5 && pTemp->next->data->GetPosition().x >= camera->center.x - 5 &&
			pTemp->next->data->GetPosition().y <= camera->center.y + 5 && pTemp->next->data->GetPosition().y >= camera->center.y - 5 &&
			pTemp->next->data->GetPosition().z <= camera->center.z + 5 && pTemp->next->data->GetPosition().z >= camera->center.z - 5) {
			if (pTemp->next->next != nullptr) {
				pTemp->next = pTemp->next->next;
			}
			else {
				pTemp->next = nullptr;
			}
		}
		DeleteAtPos(&pTemp->next, camera);
	}
}

// recursive
void LinkedList::UpdateList(ListNode* node) {
	if (node != nullptr) {
		node->data->Update();
		UpdateList(node->next);
	}
}

// recursive
void LinkedList::DrawList(ListNode* node) {
	if (node != nullptr) {
		node->data->Draw();
		DrawList(node->next);
	}
}