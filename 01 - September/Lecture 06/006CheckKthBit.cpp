#include<iostream>

using namespace std;

int main() {

	int n = 42;
	int k = 3;

	// cout << (n>>k&1) << endl;

	// k = 4;

	// cout << (n>>k&1) << endl;

	// if(n>>k&1) {
	// 	// kth bit of n is set
	// 	cout << "true" << endl;
	// } else {
	// 	// kth bit of n is not set
	// 	cout << "false" << endl;
	// }

	n>>k&1 ? cout << "true" << endl :
	         cout << "false" << endl;

	1<<k&n ? cout << "true" << endl :
	         cout << "false" << endl;

	k = 4;

	n>>k&1 ? cout << "true" << endl :
	         cout << "false" << endl;

	1<<k&n ? cout << "true" << endl :
	         cout << "false" << endl;

	
	return 0;
}