#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int arr[] = {50, 40, 40, 30, 30, 30, 20, 10, 10};
	int n = sizeof(arr) / sizeof(int);

	// sorting a sequence (nlogn)
	sort(arr, arr+n);

	for(int i=0; i<n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	// reversing a sequence
	reverse(arr, arr+n);

	for(int i=0; i<n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	// finding the minimum value in a sequence 
	cout << *min_element(arr, arr+n) << endl;

	// finding the maximum value in a sequence
	cout << *max_element(arr, arr+n) << endl;

	// finding a value in a sequence
	int key = 10;
	auto ptr = find(arr, arr+n, key);
	if(ptr != arr+n) {
		cout << key << " found at index " << (ptr-arr) << endl;
	}

	// counting a value in a sequence - O(n)
	cout << count(arr, arr+n, key) << endl;

	// reverse the array again, so that it is sorted
	reverse(arr, arr+n);

	for(int i=0; i<n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	// testing if a value is present in a sorted sequence
	key = 10;
	binary_search(arr, arr+n, key) ? cout << key << " is found!" << endl :
	                                 cout << key << " is not found!" << endl;

	// finding lower bound for a value in a sorted sequence

	// it will give the pointer to the first element in the sequence which is not less the key
	key = 30;
	cout << lower_bound(arr, arr+n, key)-arr << endl;                             

	// finding upper bound for a value in a sorted sequence

	// it will give the pointer to the first element in the sequence which is greater than the key
	cout << upper_bound(arr, arr+n, key)-arr << endl;

	// counting a value in a sorted sequence
	key = 10;
	cout << upper_bound(arr, arr+n, key) - lower_bound(arr, arr+n, key) << endl;
	cout<<-2%5;
	return 0;
}
