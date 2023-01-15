#include<iostream>

using namespace std;

template <typename T>
class ListNode {
public:

	T val;
	ListNode<T>* next;

	ListNode(T val) {
		this->val = val;
		this->next = NULL;
	}

};

template <typename T>
class forward_list {

	ListNode<T>* head;
	int  count;

	public : 

		forward_list() {
			head = NULL;
			count = 0;
		}

		void push_front(T val) {
			ListNode<T>* n = new ListNode<T>(val);
			n->next = head;
			head = n;

			count++;
		}

		void pop_front() {
			if(!head) { // head == NULL
				return;
			}

			ListNode<T>* temp = head;
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

		T front() {
			return head->val;
		}

		void traverse() {
			ListNode<T>* temp = head;
			while(temp) {
				cout << temp->val << " ";
				temp = temp->next;
			}
			cout << endl;
		}

};

int main() {

	forward_list<string> fw;

	fw.push_front("aarushi");
	fw.push_front("peeyush");
	fw.push_front("mohit");
	fw.push_front("vaibhav");
	fw.push_front("sahil");

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