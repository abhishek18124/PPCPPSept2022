#include<iostream>

using namespace std;

int main() {

	int x = 516;
	int *xptr = &x;
	
	cout << "x = " << x << endl;
	cout << "sizeof(x) = " << sizeof(x) << endl;
	cout << "xptr = " << xptr << endl;
	cout << "sizeof(xptr) = " << sizeof(xptr) << endl;
	
	return 0;
}