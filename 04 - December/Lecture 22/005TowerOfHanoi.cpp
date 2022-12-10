#include<iostream>

using namespace std;

void f(int n, char src, char helper, char dst) {

	// base case
	if(n == 0) {
		return;
	}

	// recursive case

	// 1. ask your friend to move n-1 disks from 'A'(src) to 'B'(helper) using 'C'(destn)
	f(n-1, src, dst, helper);

	// 2. move disk from 'A'(src) to 'C'(dst)
	cout << "move disk from " << src << " to " << dst << endl;

	// 3. ask your friend to move n-1 disks from 'B'(helper) to  'C'(dst) using 'A'(src)
	f(n-1, helper, src, dst);
}

int main() {

	int n = 3;

	f(n, 'A', 'B', 'C');

	return 0;
}