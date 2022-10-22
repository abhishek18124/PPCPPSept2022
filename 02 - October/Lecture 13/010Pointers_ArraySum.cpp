#include<iostream>

using namespace std;

int computeSum(int* arr, int n) {

	int sum = 0;
	for(int i=0; i<n; i++) {
		sum += arr[i]; // or *(arr+i);	
	}
	
	return sum;
}

void modifyArray(int* arr, int n) {
	for(int i=0; i<n; i++) {
		(*(arr+i))++;
		// arr[i]++;
	}
}

int main() {

	int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr) / sizeof(int);

	// cout << computeSum(arr, n) << endl; 

	modifyArray(arr, n); // modifyArray(&arr[0], n)

	for(int i=0; i<n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}