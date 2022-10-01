#include<iostream>

using namespace std;

void increment(int a) {
	cout << "inside increment : before ++ a = " << a << endl;
	a++;
	cout << "inside increment : after ++ a = " << a << endl;
}

int main() {

	int a = 0;

	cout << "inside main : before increment() a = " << a << endl;

	increment(a);

	cout << "inside main : after increment() a = " << a << endl;

	return 0;
}