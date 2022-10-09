// contraints : n <= 100, k <= 9

#include<iostream>

using namespace std;

int main() {	

	int arr[] = {1, 0, 3, 2, 3, 1, 2, 0, 2};
	int n = sizeof(arr) / sizeof(int);
	
	int k = 3; // denotes the maximum element in the array

	int cnt[10]; // since cnt array should be of size k+1

	// 1. count and store the occurrences of each element in the given array

	for(int i=0; i<n; i++) {
		int x = arr[i];
		cnt[x]++;
	}

	// for(int i=0; i<=k; i++) {
	// 	cout << cnt[i] << " ";
	// }

	// cout << endl;

	// for(int i=0; i<=k; i++) {
	// 	int y = cnt[i];
	// 	// cout << i << " : " << y << endl;
	// 	while(y--) {
	// 		cout << i << " ";
	// 	}
	// }

	// 2. find the starting position of each unique element in the output array

	// 2.a add each element to the right cumulatively

	for(int i=1; i<=k; i++) {
		cnt[i] += cnt[i-1];
	}

	// 2.b right shift each element by a single step

	for(int i=k; i>=1; i--) {
		cnt[i] = cnt[i-1];
	}

	cnt[0] = 0;

	// 2.c build the output array using right-shifted starting position in the cnt array

	int out[100]; // based on the constraints

	for(int i=0; i<n; i++) {
		// int x = arr[i];
		// int start_pos_of_x = cnt[x];
		// out[start_pos_of_x] = x;
		// cnt[x]++;

		out[cnt[arr[i]]++] = arr[i];

	}

	// print the output array

	for(int i=0; i<n; i++) {
		cout << out[i] << " ";
	}

	cout << endl;


	return 0;
}