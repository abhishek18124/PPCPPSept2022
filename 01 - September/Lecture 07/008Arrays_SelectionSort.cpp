#include<iostream>

using namespace std;

int main() {

	int arr[] = {50, 40, 10, 30, 20};
	int n = sizeof(arr) / sizeof(int);

	for(int i=0; i<n-1; i++) {
		// in the ith pass, we have to place the smallest element
		// in the unsorted part of the array to its correct position
		int correct_pos = i;
		int min_idx = i;
		for(int j=i+1; j<n; j++) {
			if(arr[j] < arr[min_idx]) {
				min_idx = j;
			}
		}
		swap(arr[correct_pos], arr[min_idx]);
	}
	
	for(int i=0; i<n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
	
	return 0;
}