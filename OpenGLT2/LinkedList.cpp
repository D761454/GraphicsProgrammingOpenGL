#include "LinkedList.h"

LinkedList::LinkedList() {

}

LinkedList::~LinkedList() {

}

int LinkedList::GetSize(ListNode* node, int counter) {
	if (node != nullptr) {
		counter++;
		GetSize(node->next, counter);
	}
	else {
		return counter;
	}
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

void LinkedList::DeleteSelected(ListNode** node) {
	ListNode* pTemp = *node;
	ListNode* last = nullptr;

	if (pTemp != nullptr) {
		if (pTemp->data->GetSelected()) { // root
			if (pTemp->next != nullptr) {
				last = pTemp;
				pTemp = pTemp->next;
				*node = pTemp;
				delete last;
				last = nullptr;
				DeleteSelected(node);
			}
			else {
				delete *node;
				*node = nullptr;
			}
		}
		else if (pTemp->next != nullptr) {
			if (pTemp->next->data->GetSelected()) {
				if (pTemp->next->next != nullptr) {
					last = pTemp->next;
					pTemp->next = pTemp->next->next;
					delete last;
					last = nullptr;
				}
				else {
					pTemp->next = nullptr;
				}
				*node = pTemp;
				DeleteSelected(&pTemp);
			}
			DeleteSelected(&pTemp->next);
		}
	}


	//if (pTemp != nullptr) {
	//	// head
	//	if (pTemp->data->GetSelected()) {
	//		if (pTemp->next != nullptr) {
	//			*head = pTemp->next;
	//		}
	//		else {
	//			*head = nullptr;
	//		}
	//		//return;
	//	}
	//	// other
	//	else if (pTemp->next != nullptr) {
	//		if (pTemp->next->data->GetSelected()) {
	//			if (pTemp->next->next != nullptr) {
	//				pTemp->next = pTemp->next->next;
	//			}
	//			else {
	//				pTemp->next = nullptr;
	//			}
	//			//return;
	//		}
	//	}
	//	DeleteSelected(&pTemp->next);
	//}
}

void LinkedList::SelectAt(ListNode* head, int pos) {
	int count = 0;

	while (head != nullptr) {
		if (count == pos) {
			if (!head->data->GetSelected()) {
				head->data->Selected(true);
			}
			else {
				head->data->Selected(false);
			}
		}
		count++;
		head = head->next;
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