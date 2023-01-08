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

ListNode* reverseIterative(ListNode* head) {

	ListNode* cur = head;
	ListNode* prev= NULL;
	
	while(cur != NULL) {
		ListNode* temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;
	}

	return prev;
}

ListNode* getMidPoint(ListNode* head) {
	if(head == NULL) {
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

bool checkPalindrome(ListNode* head) {

	// 1. find the midPoint of the LL
	ListNode* midPoint = getMidPoint(head);

	// 2. divide the LL around the midPoint
	ListNode* head2 = midPoint->next;
	midPoint->next = NULL;

	// 3. reverse the second subList
	head2 = reverseIterative(head2);

	while(head2 != NULL) {
		if(head->val != head2->val) {
			// given LL is not a palindrome
			return false;
		}
		head = head->next;
		head2 = head2->next;
	}

	return true;

}

int main() {

	ListNode* head = NULL;

	insertAtHead(head, 10);
	insertAtHead(head, 20);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	checkPalindrome(head) ? cout << "LL is a palindrome" << endl :
	                        cout << "LL is not a palindrome" <<endl;

	return 0;
}