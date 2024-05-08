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

void LinkedList::DeleteAtPos(ListNode** head, Camera* camera) {
	ListNode* pTemp = *head;

	if (pTemp != nullptr) {
		// head
		if (pTemp->data->GetPosition().x <= (camera->eye.x + camera->center.x * 50) + 5 && pTemp->data->GetPosition().x >= (camera->eye.x + camera->center.x * 50) - 5 &&
			pTemp->data->GetPosition().y <= (camera->eye.y + camera->center.y * 50) + 5 && pTemp->data->GetPosition().y >= (camera->eye.y + camera->center.y * 50) - 5 &&
			pTemp->data->GetPosition().z <= (camera->eye.z + camera->center.z * 50) + 5 && pTemp->data->GetPosition().z >= (camera->eye.z + camera->center.z * 50) - 5) {
			*head = pTemp->next;

			cout << "Head Deleted" << endl;
			return;
		}
		// other
		if (pTemp->next != nullptr) {
			if (pTemp->next->data->GetPosition().x <= (camera->eye.x + camera->center.x * 50) + 5 && pTemp->next->data->GetPosition().x >= (camera->eye.x + camera->center.x * 50) - 5 &&
				pTemp->next->data->GetPosition().y <= (camera->eye.y + camera->center.y * 50) + 5 && pTemp->next->data->GetPosition().y >= (camera->eye.y + camera->center.y * 50) - 5 &&
				pTemp->next->data->GetPosition().z <= (camera->eye.z + camera->center.z * 50) + 5 && pTemp->next->data->GetPosition().z >= (camera->eye.z + camera->center.z * 50) - 5) {
				if (pTemp->next->next != nullptr) {
					pTemp->next = pTemp->next->next;
				}
				else {
					pTemp->next = nullptr;
				}
				cout << "Node Deleted" << endl;
				return;
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