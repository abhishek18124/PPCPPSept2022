#include<iostream>
#include<algorithm>

using namespace std;

bool myComparator(int a, int b) {

	string str_a = to_string(a);
	string str_b = to_string(b);

	string x = str_a+str_b;
	string y = str_b+str_a;

	// for lexicographically decr. order

	// if(x > y) {
	// 	// you don't need a swap
	// 	return true;
	// } else {
	// 	// you need a swap
	// 	return false;
	// }

	return x > y;

}

int main() {

	int arr[] = {98, 9};
	int n = sizeof(arr) / sizeof(int);

	sort(arr, arr+n, myComparator);

	for(int i=0; i<n; i++) {
		cout << arr[i];
	}	

	cout << endl;

	return 0;
}