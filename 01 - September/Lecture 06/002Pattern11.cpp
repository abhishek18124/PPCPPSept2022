#include<iostream>

using namespace std;

int main() {

	int n = 9;

	int m = n-n/2;

	// 1. print upper-part of the pattern
	
	for(int i=1; i<=m; i++) {
		// print 'm-i' spaces
		for(int j=1; j<=m-i; j++) {
			cout << " ";
		}

		// print '2i-1' stars
		for(int j=1; j<=2*i-1; j++) {
			cout << "*";
		}

		cout << endl;
	}

	// 2. print lower-part of the pattern
	
	for(int i=1; i<=m-1; i++) {

		// print 'i' spaces
		for(int j=1; j<=i; j++) {
			cout << " ";
		}

		// print '2(m-i)-1' stars
		for(int j=1; j<=2*(m-i)-1; j++) {
			cout << "*";
		}

		cout << endl;

	}

	return 0;
}