#include<iostream>

using namespace std;

class ListNode {
public:

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

ListNode* rotateLinkedList(ListNode* head, int k) {

	// 1. form a loop by connecting the tail ListNode of  the
	//    linkedList with the head ListNode of the linkedList
	ListNode* tail = head;
	int n = 1;
	while(tail->next != NULL) {
		tail = tail->next;
		n++;
	}

	tail->next =  head;
	
	// 2. get hold of the pointer to the new tail ListNode 
	//    that can be found at the (n-(k%n)-1)th index
	ListNode* newTail = head;
	for(int i=0; i<n-(k%n)-1; i++) {
		newTail = newTail->next;
	}

	// 3. get hold of the pointer to the new head ListNode
	ListNode* newHead = newTail->next;

	// 4. remove the cycle by updating the next pointer of
	//    the new tail ListNode to contain the NULL address
	newTail->next = NULL;

	return newHead;

}

int main() {

	ListNode* head = NULL;

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	int k = 3;

	head = rotateLinkedList(head, k);

	printLinkedList(head);

	return 0;
}