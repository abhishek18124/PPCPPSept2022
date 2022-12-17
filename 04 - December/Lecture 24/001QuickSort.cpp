// constraints : n <= 100

#include<iostream>

using namespace std;

int partition(int* arr, int s, int e) {

	int j = s;
	int i = s-1; // represents the boundary of the leftPartition
	int pivot = arr[e];

	while(j < e) {
		if(arr[j] < pivot) {
			// insert the jth element in the leftPartition
			i++;
			swap(arr[i], arr[j]);
		}
		j++;
	}

	swap(arr[i+1], arr[e]);
	return i+1;

}

void quickSort(int* arr, int s, int e) {

	if(s >= e) {
		return;
	}

	// 1. partition the array around the pivot element
	int p = partition(arr, s, e);

	// 2. quickSort the leftPartition
	quickSort(arr, s, p-1);

	// 3. quickSort the rightPartition
	quickSort(arr, p+1, e);

}

int main() {

	int arr[] = {60, 50, 20, 10, 40, 30};
	int n = sizeof(arr) / sizeof(int);

	quickSort(arr, 0, n-1);
	
	for(int i=0; i<n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}