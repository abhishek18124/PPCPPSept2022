#include<iostream>

using namespace std;

int main() {

	// int x = 516;
	// int *xptr = &x;
	
	// cout << "x = " << x << endl;
	// cout << "sizeof(x) = " << sizeof(x) << endl;
	// cout << "xptr = " << xptr << endl;
	// cout << "sizeof(xptr) = " << sizeof(xptr) << endl;
	// cout << "*xptr = " << *xptr << endl;

	// char* chptr = (char*)&x;
	// cout << "*chptr = " << (int)*chptr << endl;

	int y = 10;
	int* yptr = &y;

	cout << "yptr = " << yptr << endl;

	yptr++; // yptr = yptr + 1;

	cout << "yptr = " << yptr << endl;

	yptr++;

	cout << "yptr = " << yptr << endl;
	
	return 0;
}