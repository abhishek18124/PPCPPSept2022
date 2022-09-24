#include<iostream>

using namespace std;

int main() {

	int arr[1000];

	int n;
	cout << "enter the value of n : ";
	cin >> n;

	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}

	int t;
	cout << "enter the target : ";
	cin >> t;


	bool flag = false; // assume 'target' is not present in the array

	for(int i=0; i<n; i++) {
		if(arr[i] == t) {
			// target found at index i
			cout << i << " ";
			flag = true;
		}
	}

	if(!flag) { // flag == false
		// initial assumption was correct, target not found
		cout << -1 << endl;
	}

	return 0;
}