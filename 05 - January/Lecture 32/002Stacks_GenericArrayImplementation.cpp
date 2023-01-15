#include<iostream>

using namespace std;

template <typename T>
class stack {

	T* arr; // pointer to the array that internally represents stack
	int t;    // to store the array index of the stack top
	int n;    // to store the maximum stack capacity

	public :

		stack(int n) {
			arr = new T[n];
			t = -1;
			this->n = n;
		}

		void push(T data) {
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

		T top() {
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

	stack<string> s(5);

	cout << "size : " << s.size() << endl;
	cout << "isEmpty ? " << s.empty() << endl;

	s.push("ankit");
	s.push("harshit");
	s.push("kunwarpreet");
	s.push("prateek");
	s.push("garveet");

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