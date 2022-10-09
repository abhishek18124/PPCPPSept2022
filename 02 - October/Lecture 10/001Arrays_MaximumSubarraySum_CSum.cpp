// constraints : n <= 100

#include<iostream>

using namespace std;

int main() {

	int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	int n = sizeof(arr) / sizeof(int);

	// approach 2 -> time : O(N^2) space : O(N)

	int csum[101]; // based on the constraints

	csum[0] = 0;
	for(int i=1; i<=n; i++) {
		csum[i] = csum[i-1] + arr[i-1];
	}

	// for(int i=0; i<=n; i++) {
	// 	cout << csum[i] << " ";
	// }

	// cout << endl;

	int maxSum = INT_MIN;

	// iterate over all the possible starting indices
	for(int i=0; i<n; i++) {
		// iterate over all the possible ending indiices
		for(int j=i; j<n; j++) {
			// compute the sum of the arr[i...j]
			int sum = csum[j+1]-csum[i];
			if(sum > maxSum) {
				maxSum = sum;
			}
		}
	}

	cout << maxSum << endl;

	return 0;
}






