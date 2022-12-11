#include<iostream>

using namespace std;

int f(int* x, int t, int s, int e) {

	// base case
	if(s > e) {
		// search space is now empty
		return -1;
	}

	// recursive case

	// search for the 't' in x[s...e]

	int m = s+(e-s)/2;
	if(x[m] == t) {
		// you've found the 't'
		return m;
	} else if(t < x[m]) {
		// search for the 't' in x[s...m-1] -> friend
		return f(x, t, s, m-1);
	} else {
		// search for the 't' in x[m+1...e] -> friend
		return f(x, t, m+1, e);
	}

}

int main() {

	int x[] = {10, 20, 30, 40, 50};
	int n = sizeof(x) / sizeof(int);
	int t = 100;

	cout << f(x, t, 0, n-1) << endl;

	return 0;
}