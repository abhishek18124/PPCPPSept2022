#include<iostream>

using namespace std;

int x = 100; // global variable

int main() {

	int x = 10; // local variable

	cout << x << " " << ::x << endl;
	
	::x = ::x + 1;
	x = x+1;

	cout << x << " " << ::x << endl;
	
	return 0;
}