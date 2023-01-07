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

ListNode* getListNode(ListNode* temp, int j) {

	int k = 0;
	while(temp != NULL and k < j) {
		temp = temp->next;
		k++;
	}

	return temp;

}

void insertAtIndex(ListNode*& head, int val, int i) {


	if(head == NULL || i == 0) {
		insertAtHead(head, val);
		return;
	}

	// 1. create a new node on the heap with the given 'val'
	ListNode* n = new ListNode(val);

	// 2. get hold of the pointer to the node at the (i-1)th index
	ListNode* prev = getListNode(head, i-1);

	if(prev == NULL) {
		// index 'i' is out of range
		return;
	}

	// 3. update the next field of the newly created node
	// such that it now points to the node which comes 
	// after the prev node
	n->next = prev->next;

	// 4. update the next field of the prev node such that
	// it now points to the newly created node;
	prev->next = n;

}

void printLinkedList(ListNode* head) {

	while(head) { // head != NULL
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;

}

int main() {

	ListNode* head = NULL; // initially, linkedList is empty

	// insertAtHead(head, 50);
	// insertAtHead(head, 40);
	// insertAtHead(head, 30);
	// insertAtHead(head, 20);
	// insertAtHead(head, 10);
	
	// printLinkedList(head);

	insertAtIndex(head, 10, 0);
	insertAtIndex(head, 20, 5);

	printLinkedList(head);

	return 0;
}