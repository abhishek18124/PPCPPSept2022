#include<iostream>

using namespace std;

int computeSum(int arr[], int n) {
	int sum = 0;
	for(int i=0; i<n; i++) {
		sum += arr[i];
	}
	return sum;
}

int main() {

	int arr[] = {10, 20, 30, 40, 50};
	int n = sizeof(arr) / sizeof(int);
	cout << computeSum(arr, n) << endl;

	return 0;
}