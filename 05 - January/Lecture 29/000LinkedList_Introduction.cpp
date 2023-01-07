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

int main() {

	ListNode* ptr = new ListNode(10);

	cout << ptr->val << endl;

	ListNode* ptr2 = new ListNode(20);

	cout << ptr2->val << endl;

	cout << ptr2 << endl;

	return 0;
}