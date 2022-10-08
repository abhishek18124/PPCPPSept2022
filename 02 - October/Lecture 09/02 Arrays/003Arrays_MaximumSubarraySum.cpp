// contraints : n <= 100

#include<iostream>
#include<climits>

using namespace std;

int main() {

	int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	int n = sizeof(arr) / sizeof(int);

	// brute-force approach : O(N^3)

	int maxSum = INT_MIN; // to track the maximum subarray sum we've computed so far

	// iterate over all the possible starting indices
	for(int i=0; i<=n-1; i++) {
		// for each starting index 'i', iterate over all the possible ending indices
		for(int j=i; j<=n-1; j++) {
			// compute the sum of the subarray that starts at the ith index and ends at the jth index
			int sum = 0;
			for(int k=i; k<=j; k++) {
				sum += arr[k];
			}
			if(sum > maxSum) {
				maxSum = sum;
			}
		}
	}

	cout << "maximum subarray sum : " << maxSum << endl;


	return 0;
}