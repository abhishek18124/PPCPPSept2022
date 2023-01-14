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

// ListNode* sumOfLinkedList(ListNode* head1, ListNode* head2) {

// 	ListNode* head = NULL; // output LL is initially empty
// 	int carry = 0;

// 	while(head1 != NULL and head2 != NULL) {

// 		int d1 = head1->val;
// 		int d2 = head2->val;
		
// 		int sum = d1+d2+carry;
// 		carry = sum/10;

// 		ListNode* temp = new ListNode(sum%10);
// 		temp->next = head;
// 		head = temp;

// 		head1 = head1->next;
// 		head2 = head2->next;

// 	}

// 	while(head1 != NULL) {

// 		int d1 = head1->val;
		
// 		int sum = d1+carry;
// 		carry = sum/10;

// 		ListNode* temp = new ListNode(sum%10);
// 		temp->next = head;
// 		head = temp;

// 		head1 = head1->next;
		
// 	}

// 	while(head2 != NULL) {

// 		int d2 = head2->val;
		
// 		int sum = d2+carry;
// 		carry = sum/10;

// 		ListNode* temp = new ListNode(sum%10);
// 		temp->next = head;
// 		head = temp;

// 		head2 = head2->next;
		
// 	}


// 	if(carry == 1) {
// 		ListNode* temp = new ListNode(carry);
// 		temp->next = head;
// 		head = temp;
// 	}

// 	return head;

// }

ListNode* sumOfLinkedListRefactored(ListNode* head1, ListNode* head2) {

	ListNode* head = NULL; // output LL is initially empty
	int carry = 0;

	while(head1 != NULL || head2 != NULL || carry == 1) {

		int d1 = head1 != NULL ? head1->val : 0;
		int d2 = head2 != NULL ? head2->val : 0;
		
		int sum = d1+d2+carry;
		carry = sum/10;

		ListNode* temp = new ListNode(sum%10);
		temp->next = head;
		head = temp;

		head1 = head1 != NULL ? head1->next : head1;
		head2 = head2 != NULL ? head2->next : head2;

	}

	return head;

}


int main() {

	ListNode* head1 = NULL;

	insertAtHead(head1, 9);
	insertAtHead(head1, 9);
	insertAtHead(head1, 9);
	insertAtHead(head1, 9);
	insertAtHead(head1, 9);

	printLinkedList(head1);

	ListNode* head2 = NULL;

	insertAtHead(head2, 9);
	insertAtHead(head2, 9);
	insertAtHead(head2, 9);

	printLinkedList(head2);

	ListNode* head = sumOfLinkedListRefactored(head1, head2);

	printLinkedList(head);

	return 0;
}