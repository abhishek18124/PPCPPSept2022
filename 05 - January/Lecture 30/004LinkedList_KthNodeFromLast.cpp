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
	
	while(head) { // head != NULL
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;
}

ListNode* kthNodeFromLast(ListNode* head, int k) {

	ListNode* fast = head;
	int i = 0;
	while(i < k) {
		fast = fast->next;
		i++;
	}

	ListNode* slow = head;
	while(fast != NULL) {
		slow = slow->next;
		fast = fast->next;
	}

	return slow;

}

int main() {

	ListNode* head = NULL;

	insertAtHead(head, 70);
	insertAtHead(head, 60);
	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	int k = 7;

	ListNode* kthNode = kthNodeFromLast(head, k);

	cout << kthNode->val << endl;

	return 0;
}