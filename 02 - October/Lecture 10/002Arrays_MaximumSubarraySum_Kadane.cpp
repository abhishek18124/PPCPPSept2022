// constraints : n <= 100

#include<iostream>

using namespace std;

int main() {

	int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	int n = sizeof(arr) / sizeof(int);

	// approach - time : O(n) space : O(n)

	// int x[100]; // based on the constraints

	// x[0] = arr[0];
	// int maxSum = x[0];

	// for(int i=1; i<n; i++) {
	// 	x[i] = max(arr[i], x[i-1]+arr[i]);
	// 	maxSum = max(maxSum, x[i]);
	// }

	// int maxSum = INT_MIN;
	// for(int i=0; i<n; i++) {
	// 	maxSum = max(maxSum, x[i]);
	// }

	// cout << maxSum << endl;

	int x = arr[0]; // x[0]
	int maxSum = x;

	for(int i=1; i<n; i++) {
		x = max(arr[i], x+arr[i]);
		maxSum = max(maxSum, x);
	}

	cout << maxSum << endl;


	return 0;
}