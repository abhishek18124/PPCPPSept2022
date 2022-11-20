#include<iostream>

using namespace std;

int f(int x, int y) {

	// base case
	if(y == 0) {
		// compute the product of x and y(0)
		return 0;
	}

	// recursive case

	// 1. ask your friend to compute the product of x and y-1 i.e. add x, y-1 times
	int A = f(x, y-1);

	return x + A;

}

int main() {

	int x = 10;
	int y = 10;

	cout << f(x, y) << endl;

	return 0;
}