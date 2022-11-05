#include<iostream>
#include<algorithm>

using namespace std;

/*
	
	assume 'a' is at an index which is less than 'b'

	this function should return true when swap is not required
	and it should return false when swap is required.

*/

bool myComparator(int a, int b) {
	string str_a = to_string(a);
	string str_b = to_string(b);
		
	// lexicographically incr. order

	// if(str_a < str_b) {
	// 	// you don't need a swap
	// 	return true;
	// } else {
	// 	// you need a swap
	// 	return false;
	// }

	// for lexicographically decr. order

	if(str_a > str_b) {
		// you dont' need a swap
		return true;
	} else {
		// you need a swap
		return false;
	}

}

bool myGreaterComparator(int a, int b) {

	// if(a > b) {
	// 	// you don't need a swap
	// 	return true; 
	// } else {
	// 	// you need a swap
	// 	return false;
	// }

	retrun a > b;


}

int main() {

	int arr[] = {60, 54, 546, 548};
	int n = sizeof(arr) / sizeof(int);

	// sort(arr, arr+n);

	// reverse(arr, arr+n);

	// sort(arr, arr+n, greater<int>());

	sort(arr, arr+n, myGreaterComparator);

	// sort(arr, arr+n, myComparator);

	for(int i=0; i<n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}