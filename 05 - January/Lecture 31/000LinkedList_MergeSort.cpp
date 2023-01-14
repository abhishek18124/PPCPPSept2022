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

ListNode* getMidPoint(ListNode* head) {
	if(!head) { // head == NULL
		return head;
	}

	ListNode* slow = head;
	ListNode* fast = head->next;

	while(fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
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


ListNode* mergeSort(ListNode* head1) {

	// base case
	if(head1 == NULL || head1->next == NULL) {
		// LL is empty or LL has a single node
		return head1;
	}

	// 1. divide the linkedList around the midPoint into two sub-lists
	ListNode* midPoint = getMidPoint(head1);
	ListNode* head2 = midPoint->next;
	midPoint->next = NULL;

	// 2. recursively sort the two sub-lists
	head1 = mergeSort(head1);
	head2 = mergeSort(head2);

	// 3. merge the two sorted sub-lists such that the entire LL is sorted
	return mergeLinkedList(head1, head2);
}


int main() {

	ListNode* head = NULL;

	insertAtHead(head, 10);
	insertAtHead(head, 20);
	insertAtHead(head, 30);
	insertAtHead(head, 40);
	insertAtHead(head, 50);

	printLinkedList(head);

	head = mergeSort(head);

	printLinkedList(head);

	return 0;
}