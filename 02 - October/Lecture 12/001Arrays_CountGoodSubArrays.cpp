// constrains : n <= 100

#include<iostream>

using namespace std;

int main() {

	int arr[] = {1, 6, 5, 2, 4, 3};
	int n = sizeof(arr) / sizeof(int);

	// approach - time : O(n^2) space : O(n) due to csum array

	int csum[101];
	csum[0] = 0;
	for(int i=1; i<=n; i++) {
		csum[i] = csum[i-1] + arr[i-1];
	}

	int count = 0; // to track the num. of good subarrays

	for(int i=0; i<n; i++) {
		for(int j=i; j<n; j++) {
			int sum = csum[j+1] - csum[i];
			if(sum%n == 0) {
				// the subarray that starts at the ith index and 
				// ends at the jth index is a good subarray
				count++;
			}
		}
	}

	cout << count << endl;

	return 0;
}