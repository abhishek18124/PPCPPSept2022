#include<iostream>

using namespace std;

int main() {

	int x = 10;

	int* xptr; // pointer declaration
	xptr = &x; // pointer assignment
	
	cout << "x = " << x << endl;
	cout << "sizeof(x) = " << sizeof(x) << endl;
	cout << "&x = " << &x << endl;
	cout << "xptr = " << xptr << endl;
	cout << "sizeof(xptr) = " << sizeof(xptr) << "B" << endl;

	cout << endl;

	float y = 3.14;

	float* yptr = &y;

	cout << "y = " << y << endl;
	cout << "sizeof(y) = " << sizeof(y) << "B" << endl;
	cout << "&y = " << &y << endl;
	cout << "yptr = " << yptr << endl;
	cout << "sizeof(yptr) = " << sizeof(yptr) << "B" << endl;

	cout << endl;

	char w = 'A';
	char* wptr = &w;

	cout << "w = " << w << endl;
	cout << "sizeof(w) = " << sizeof(w) << "B" << endl;
	cout << "&w = " << &w << endl;
	cout << "wptr = " << wptr << endl;
	cout << "sizeof(wptr) = " << sizeof(wptr) << "B" << endl;
	
	return 0;
}