#include<iostream>

using namespace std;

int main() {

	int x = 10;

	int* xptr = &x;
	
	cout << "x = " << x << endl;
	cout << "*xptr = " << *xptr << endl;
	
	return 0;
}