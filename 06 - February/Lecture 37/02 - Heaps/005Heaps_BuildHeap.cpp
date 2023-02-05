/*

	Given an array of n integers, design a O(n) algorirthm to build a max_heap in-place.

*/

#include<iostream>
#include<vector>

using namespace std;

void heapify(int i, vector<int> v, int n) {

	int min_idx = i;
	int left_idx = 2*i + 1;
	if(left_idx < n && v[left_idx] < v[min_idx]) {
		min_idx = left_idx;
	}

	int right_idx = 2*i + 2;
	if(right_idx < n && v[right_idx] < v[min_idx]) {
		min_idx = right_idx;
	}

	if(min_idx != i) {
		swap(v[min_idx], v[i]);
		heapify(min_idx, v, n);
	}

}

int main() {

	vector<int> v = {1, 3, 2, 7, 5, 4, 6, 9, 8};
	int n = v.size();	


	for(int i=n-1; i>=0; i--) {
		heapify(i, v, n);
	}

	for(int i=0; i<v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	return 0;
}





