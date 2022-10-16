// constrains : n <= 100

#include<iostream>

using namespace std;

int main() {

	int arr[] = {1, 6, 5, 2, 4, 3};
	int n = sizeof(arr) / sizeof(int);

	int freq[100] = {}; // 0 init
	freq[0] = 1;

	int csum = 0;
	for(int i=0; i<n; i++) {
		csum += arr[i];
		freq[((csum%n)+n)%n]++;
	}

	int count = 0; // to track the num. of good subarrays
	for(int i=0; i<n; i++) {
		int x_i = freq[i];
		if(x_i >= 2) {
			// it will contribute to the count of good subarrays
			count += (x_i*(x_i-1))/2;
		}
	}

	cout << count << endl;


	return 0;
}