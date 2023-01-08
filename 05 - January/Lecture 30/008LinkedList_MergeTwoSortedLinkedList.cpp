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

ListNode* mergeLinkedList(ListNode* head1, ListNode* head2) {

	// base case
	if(head1 == NULL) {
		// first LL is empty
		return head2;
	}

	if(head2 == NULL) {
		// second LL is empty
		return head1;
	}

	ListNode* head;
	if(head1->val < head2->val) {
		// head1 will be the head of the final LL
		head = head1;
		ListNode* headFromMyFriend = mergeLinkedList(head1->next, head2);
		head->next = headFromMyFriend;
	} else {
		// head2 will be head of the final LL
		head = head2;
		ListNode* headFromMyFriend = mergeLinkedList(head1, head2->next);
		head->next = headFromMyFriend;
	}

	return head;

} 

int main() {

	ListNode* head1 = NULL;

	insertAtHead(head1, 50);
	insertAtHead(head1, 30);
	insertAtHead(head1, 10);

	printLinkedList(head1);

	ListNode* head2 = NULL;

	insertAtHead(head2, 60);
	insertAtHead(head2, 40);
	insertAtHead(head2, 20);

	printLinkedList(head2);

	ListNode* head = mergeLinkedList(head1, head2);

	printLinkedList(head);

	return 0;
}