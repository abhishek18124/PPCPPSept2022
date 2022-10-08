#include<iostream>

using namespace std;

void modify(int arr[], int n) {
	for(int i=0; i<n; i++) {
		arr[i]++;
	}
}

int main() {

	int arr[] = {10, 20, 30, 40, 50};
	int n = sizeof(arr) / sizeof(int);

	for(int i=0; i<n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	modify(arr, n);

	for(int i=0; i<n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}