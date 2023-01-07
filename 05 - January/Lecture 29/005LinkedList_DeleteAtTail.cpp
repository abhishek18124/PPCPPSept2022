#include<iostream>

using namespace std;

class ListNode {

	public :

		int val;
		ListNode* next;

		ListNode(int val) {
			this->val = val;
			this->next = NULL;
		}

};


void insertAtHead(ListNode*& head, int val) {
	
	ListNode* n = new ListNode(val);
	n->next = head;
	head = n;

}

void printLinkedList(ListNode* head) {
	
	while(head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
	
	cout << endl;
}

void deleteAtHead(ListNode*& head) {

	if(!head) { // head == NULL
		// linkedList is empty
		return;
	}

	ListNode* temp = head;
	head = head->next;
	delete temp;
}

void deleteAtTail(ListNode*& head) {

	// time : O(n)

	if(!head) { // head == NULL
		// LL is empty
		return;
	}

	if(!head->next) { // head->next == NULL
		// LL has a single node
		deleteAtHead(head);
		return;
	}

	ListNode* prev = NULL;
	ListNode* tail = head;

	while(tail->next != NULL) {
		prev = tail;
		tail = tail->next;
	}

	prev->next = NULL;
	delete tail;

}

int main() {

	ListNode* head = NULL; // linked list is initially empty

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	// insertAtHead(head, 30);
	// insertAtHead(head, 20);
	// insertAtHead(head, 10);
	
	printLinkedList(head);

	deleteAtTail(head);

	printLinkedList(head);

	return 0;
}