#include<iostream>

using namespace std;

bool isEven(int n) {
	if(n%2 == 0) {
		return true; // n is even
	}
	return false; // n is odd
}

int main() {

	bool ans;

	ans = isEven(2);

	// cout << ans << endl;

	ans ? cout << "true" << endl :
	      cout << "false" << endl;

	ans = isEven(3);

	if(ans) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}

	// any fn. call that returns a value can be treated as an expr
	// and therefore it can be passed an argument to cout << 

	cout << isEven(4) << endl;
	cout << isEven(5) << endl;
	
	return 0;
}