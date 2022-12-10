#include<iostream>

using namespace std;

// int f(int x, int y) {
// 	// base case
// 	if(y == 0) {
// 		// compute x^0
// 		return 1;
// 	}

// 	// recursive case

// 	// 1. ask your friend to compute the value of x^(y-1)
// 	int A = f(x, y-1);

// 	return x*A;
// }

int f2(int x, int y) {
	// base case
	// if(y == 0) {
	// 	// compute x^0
	// 	return 1;
	// }

	if(y == 1) {
		// compute x^1
		return x;
	}

	// recursive case

	// 1. ask your friend to compute the value of x^(y/2)
	int A = f2(x, y/2);

	if(y%2 == 0) {
		// y is even
		return A*A;
	} else {
		// y is odd
		return A*A*x;
	}

}
 
int main() {

	int x = 2;
	int y = 5;

	// cout << f(x, y) << endl;

	cout << f2(x, y) << endl;

	return 0;
}