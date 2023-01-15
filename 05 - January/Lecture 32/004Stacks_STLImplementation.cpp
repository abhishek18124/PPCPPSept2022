#include<iostream>
#include<stack>

using namespace std;

int main() {

	stack<int> s;

	s.push(10);
	s.push(20);
	s.push(30);

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();
	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "empty : " << s.empty() << endl;

	return 0;

}