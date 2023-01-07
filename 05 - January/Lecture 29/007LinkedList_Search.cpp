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

bool search(ListNode* head, int target) {

	while(head) { // head != NULL
		if(head->val == target) {
			return true;
		}
		head = head->next;
	}

	return false;

}

bool searchRecursive(ListNode* head, int target) {

	// base case
	if(!head) { // head == NULL
		// LL is empty
		return false;
	}

	// recursive case

	if(head->val == target) {
		return true;
	}

	// ask  your friend to check if the target is present
	// in the subList that starts from the node which comes
	// after the head node

	return searchRecursive(head->next, target);

}

int main() {

	ListNode* head = NULL; // initially, linkedList is empty

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	int target = 30;

	search(head, target) ? cout << target << " found!" << endl :
	                       cout << target << " not found!" << endl;

	searchRecursive(head, target) ? cout << target << " found!" << endl :
	                                cout << target << " not found!" << endl;
                  

	return 0;
}