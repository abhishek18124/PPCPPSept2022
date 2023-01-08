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

ListNode* reverseRecursive(ListNode* head) {

	// base case 
	
	// if(head == NULL) {
	// 	// LL is empty
	// 	return head;
	// }

	// if(head->next == NULL) {
	// 	// LL has a single node
	// 	return head;
	// }

	if(head == NULL || head->next == NULL) {
		return head;
	}

	// recursive case

	// 1. ask your friend to reverse the subList that
	// starts from the node which comes after the head
	// node

	ListNode* revHead = reverseRecursive(head->next);
	ListNode* revTail = head->next;
	revTail->next = head;
	head->next = NULL;

	return revHead;

}


int main() {

	ListNode* head = NULL; // initially, linkedList is initially empty

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	// head = reverseIterative(head);

	// printLinkedList(head);

	head = reverseRecursive(head);

	printLinkedList(head);

	return 0;
}