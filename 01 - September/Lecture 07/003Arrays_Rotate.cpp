#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 40, 50, 60, 70};
	int n = sizeof(arr) / sizeof(int);

	int temp = arr[n-1];

	// shift all the values from the 0th index to (n-2)th index one step to the right

	for(int i=n-1; i>=1; i--) {
		arr[i] = arr[i-1];
	}
	
	arr[0] = temp;

	for(int i=0; i<n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}