#include<iostream>

using namespace std;

bool flag = false; // assume 't' is not present

void f(int* x, int n, int t, int i) {

	// base case
	
	if(i == n) {
		if(flag == false) {
			// 't' is not present in the array
			cout << -1 << endl;
			return;
		} else {
			return;
		}
	}

	// recursive case

	// search for the index of the all occ. of the 't' in x[i...n-1]

	if(x[i] == t) {
		// you've found the one occ. of the 't' at index 'i'
		flag = true;
		cout << i << " ";
	}

	// search for the index of the remaining occ. of the 't' in x[i+1...n-1]
	f(x, n, t, i+1);

}

int main() {

	int x[] = {10, 20, 30, 20, 30};
	int n = sizeof(x) / sizeof(int);
	int t = 20;

	f(x, n, t, 0);

	return 0;
}