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

};

template <typename T>
class stack {

	forward_list<T> fw;

	public : 

		void push(T data) {
			fw.push_front(data);
		}

		void pop() {
			if(empty()) {
				// stack is empty
				return;
			}
			fw.pop_front();
		}

		int size() {
			return fw.size();
		}

		bool empty() {
			return fw.empty();
		}

		T top() {
			return fw.front();
		}

};


int main() {

	stack<int> s;

	cout << "size : " << s.size() << endl;
	cout << "isEmpty ? " << s.empty() << endl;

	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl; 
	cout << "isEmpty ? " << s.empty() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl; 

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl; 

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl; 

    s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl; 

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "isEmpty ? " << s.empty() << endl;

	return 0;
}