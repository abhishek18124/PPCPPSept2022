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

ListNode* reverseIterative(ListNode* head) {

	// time : O(n)

	ListNode* prev = NULL;
	ListNode* curr = head;
	while(curr) { // curr != NULL

		ListNode* temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;

	} 

	return prev;

}


int main() {

	ListNode* head = NULL; // initially, linkedList is initially empty

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	head = reverseIterative(head);

	printLinkedList(head);

	return 0;
}