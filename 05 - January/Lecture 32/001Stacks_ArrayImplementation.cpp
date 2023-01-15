#include<iostream>

using namespace std;

class stack {

	int* arr; // pointer to the array that internally represents stack
	int t;    // to store the array index of the stack top
	int n;    // to store the maximum stack capacity

	public :

		stack(int n) {
			arr = new int[n];
			t = -1;
			this->n = n;
		}

		void push(int data) {
			if(t == n-1) {
				return;
			}

			t = t+1;
			arr[t] = data;
		}

		void pop() {
			if(t == -1) {
				// underflow condition
				return;
			}

			t = t-1;
		}

		int top() {
			return arr[t];
		}

		bool empty() {
			return t == -1;
		}

		int size() {
			return t+1;
		}

};

int main() {

	stack s(5);

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