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

class forward_list {

	ListNode* head;
	int  count;

	public : 

		forward_list() {
			head = NULL;
			count = 0;
		}

		void push_front(int val) {
			ListNode* n = new ListNode(val);
			n->next = head;
			head = n;

			count++;
		}

		void pop_front() {
			if(!head) { // head == NULL
				return;
			}

			ListNode* temp = head;
			head = head->next;
			delete temp;

			count--;
		}

		int size() {
			return count;
		}

		bool empty() {
			return !head; // count == 0 or head == NULL;
		}

		int front() {
			return head->val;
		}

		void traverse() {
			ListNode* temp = head;
			while(temp) {
				cout << temp->val << " ";
				temp = temp->next;
			}
			cout << endl;
		}

};

int main() {

	forward_list fw;

	fw.push_front(50);
	fw.push_front(40);
	fw.push_front(30);
	fw.push_front(20);
	fw.push_front(10);

	cout <<  "head->val : " << fw.front() << endl;

	fw.traverse();

	cout << "size : " << fw.size() << endl;

	fw.pop_front();
	fw.pop_front();

	cout <<  "head->val : " << fw.front() << endl;

	fw.traverse();

	cout << "size : " << fw.size() << endl;

	fw.pop_front();
	fw.pop_front();
	fw.pop_front();

	fw.empty() ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}


