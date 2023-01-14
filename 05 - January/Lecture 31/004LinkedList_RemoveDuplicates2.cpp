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

ListNode* removeDuplicates(ListNode* head) {

	// base case

	if(head == NULL || head->next == NULL) {
		// LL is empty or it contains a single node
		return head;
	}
	
	if(head->val != head->next->val) {

		// head will remain the head of the final LL

		// ask your friend to delete all the duplicates from the subList which starts from head->next
		ListNode* headFromMyFriend = removeDuplicates(head->next);
		head->next = headFromMyFriend;
		return head;

	} else {

		// head node is a duplicate node

		// skip the subList that contains nodes with val equal head->val

		while(head->next != NULL && head->val == head->next->val) {
			head = head->next;
		}

		// ask your friend to delete all the duplicates from the subList which starts from head->next
		ListNode* headFromMyFriend = removeDuplicates(head->next);
		return headFromMyFriend;

	}

}

int main() {

	ListNode* head = NULL;

	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 20);
	insertAtHead(head, 10);
	insertAtHead(head, 10);
	insertAtHead(head, 10);
	insertAtHead(head, 10);
	
	printLinkedList(head);

	head = removeDuplicates(head);

	printLinkedList(head);

	return 0;
}