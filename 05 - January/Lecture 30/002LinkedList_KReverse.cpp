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
	
	while(head) { 
		cout << head->val << " ";
		head = head->next;
	}
	
	cout << endl;

}

ListNode* kReverse(ListNode* head, int k) {

	// base case
	if(head == NULL) {
		// LL is empty
		return head;
	}

	// recursive case

	// 1. reverse the first k nodes of the given LL

	ListNode* prev = NULL;
	ListNode* curr = head;
	int i = 0;

	while(curr and i < k) {

		ListNode* temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
		i++;
	} 

	// 2. k-reverse the remaining subList of size n-k

	ListNode* headFromMyFriend = kReverse(curr, k);
	head->next = headFromMyFriend;
	return prev;

}

int main() {

	ListNode* head = NULL;

	insertAtHead(head, 80);
	insertAtHead(head, 70);
	insertAtHead(head, 60);
	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	int k = 3;

	head = kReverse(head, k);

	printLinkedList(head);

	return 0;
}