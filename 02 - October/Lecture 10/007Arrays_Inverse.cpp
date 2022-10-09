// contraints : n <= 100

#include<iostream>

using namespace std;

int main() {	

	int arr[] = {2, 0, 4, 1, 3};
	int n = sizeof(arr) / sizeof(int);
	
	int brr[100]; // based on the constraints

	for(int i=0; i<n; i++) {
		// int x = arr[i];
		// brr[x] = i;

		brr[arr[i]] = i;
	}

	for(int i=0; i<n; i++) {
		cout << brr[i] << " ";
	}

	cout << endl;

	return 0;
}