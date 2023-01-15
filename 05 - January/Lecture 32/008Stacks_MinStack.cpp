#include<iostream>
#include<stack>

using namespace std;

class custom_stack {

	stack<int> org_stack;
	stack<int> min_stack;

	public : 

		void push(int data) {
			org_stack.push(data);
			if(min_stack.empty() || data <= min_stack.top()) {
				min_stack.push(data);
			}
		}

		void pop() {
			if(empty()) {
				return;
			}

			int temp = org_stack.top();
			org_stack.pop();
			if(min_stack.top() == temp) {
				min_stack.pop();
			}
		}

		int size() {
			return org_stack.size();
		}

		bool empty() {
			return org_stack.empty();
		}

		int top() {
			return org_stack.top();
		}

		int getMin() {
			return min_stack.top();
		}

};

int main() {

	custom_stack cs;

	cs.push(10);
	cs.push(20);
	cs.push(10);
	cs.push(30);

	cout << "top : " << cs.top() << endl;
	cout << "getMin : " << cs.getMin() << endl;

	cs.pop();

	cout << "top : " << cs.top() << endl;
	cout << "getMin : " << cs.getMin() << endl;

	cs.pop();

	cout << "top : " << cs.top() << endl;
	cout << "getMin : " << cs.getMin() << endl;

	cs.push(0);

	cout << "top : " << cs.top() << endl;
	cout << "getMin : " << cs.getMin() << endl;

	cs.pop();

	cout << "top : " << cs.top() << endl;
	cout << "getMin : " << cs.getMin() << endl;

	return 0;
}
