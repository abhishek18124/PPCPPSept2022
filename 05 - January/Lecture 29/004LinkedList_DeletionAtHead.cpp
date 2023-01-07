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

void deleteAtHead(ListNode*& head) {
	
	// time : O(1)

	if(!head) { // head == NULL
		// LL  is empty
		return;
	}

	ListNode* temp = head;
	head = head->next;
	delete temp;

}

void printLinkedList(ListNode* head) {
	
	while(head) { // head != NULL
		cout << head->val << " ";
		head = head->next;
	}
	
	cout << endl;
}

int main() {

	ListNode* head = NULL; // linked list is initially empty

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);
	
	printLinkedList(head);

	deleteAtHead(head);

	printLinkedList(head);


	return 0;
}