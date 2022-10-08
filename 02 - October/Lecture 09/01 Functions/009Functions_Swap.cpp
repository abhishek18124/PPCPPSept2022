#include<iostream>

using namespace std;

void mySwap(int& a, int& b) { // parameter or formal parameter
	int temp = a;
	a = b;
	b = temp;
}

int main() {

	int a = 0;
	int b = 1;

	cout << "a : " << a << " b : " << b << endl;

	mySwap(a, b); // argument or actual parameter

	cout << "a : " << a << " b : " << b << endl;

	return 0;
}