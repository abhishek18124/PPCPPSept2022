// contraints : n <= 100

#include<iostream>

using namespace std;

int main() {

	int nums[] = {1, 2, 3, 4, 5};
	int n = sizeof(nums) / sizeof(int);

	int answer[100]; 

	// // time complexity : O(n^2)

	// for(int i=0; i<n; i++) {

	// 	int l = 1;
	// 	for(int j=i-1; j>=0; j--) {
	// 		l *= arr[j];
	// 	}

	// 	int r = 1;
	// 	for(int j=i+1; j<n; j++) {
	// 		r *= arr[j];
	// 	}

	// 	answer[i] = l*r;
	// }

	int l[100];

	l[0] = 1;
	for(int i=1; i<=n-1; i++) {
		l[i] = l[i-1]*nums[i-1];
	}

	int r[100];

	r[n-1] = 1;
	for(int i=n-2; i>=0; i--) {
		r[i] = r[i+1]*nums[i+1];
	}

	for(int i=0; i<=n-1; i++) {
		answer[i] = l[i]*r[i];
	}

	for(int i=0; i<n; i++) {
		cout << answer[i] << " ";
	}

	cout << endl;
	
	return 0;
}