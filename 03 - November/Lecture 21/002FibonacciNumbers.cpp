#include<iostream>

using namespace std;

int f(int n) {

	// base case

	// if(n == 0) {
	// 	// compute the 0th fibonacci no.
	// 	return 0;
	// }

	// if(n == 1) {
	// 	// compute the 1st fibonacci no.
	// 	return 1;
	// }

	if(n == 0 || n == 1) {
		return n;
	}

	// recursive case

	// 1. ask your friend to compute the value of (n-1)th fibonacci no.
	int A = f(n-1);

	// 2. ask your friend to compute the value of the (n-2)th fibonacci no.
	int B = f(n-2);

	return A + B;

}

int main() { 

	int n = 7;

	cout << f(n) << endl;

	return 0;
}