// constraints : n <= 100

#include<iostream>

using namespace std;

void merge(int* arr, int s, int m, int e) {

	// merge the subarrays arr[s...m] and arr[m+1...e]

	int i = s;
	int j = m+1;
	int k = s;

	int brr[100];

	while(i <= m and j <= e) {
		if(arr[i] < arr[j]) {
			brr[k] = arr[i];
			i++;
			k++;
		} else {
			brr[k] = arr[j];
			j++;
			k++;
		}
	}

	while(i <= m) {
		brr[k] = arr[i];
		i++;
		k++;
	}

	while(j <= e) {
		brr[k] = arr[j];
		j++;
		k++;
	}

	// copy contents of brr into arr

	for(int l=s; l<=e; l++) {
		arr[l] = brr[l];
	}

}

void mergeSort(int* arr, int s, int e) {

	if(s == e) {
		// arr[s...e] is already sorted
		return;
	}

	// 1. compute the midPoint and divide the array around it
	int m = s+(e-s)/2;

	// 2. sort the subarrays arr[s...m] and arr[m+1...e] recursively -> friend
	mergeSort(arr, s, m);
	mergeSort(arr, m+1, e);

	// 3. merge the two sorted subarrays such that the merged array is sorted
	merge(arr, s, m, e);

}

int main() {

	int arr[] = {50, 40, 30, 20, 10};
	int n = sizeof(arr) / sizeof(int);

	mergeSort(arr, 0, n-1);
	
	for(int i=0; i<n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}