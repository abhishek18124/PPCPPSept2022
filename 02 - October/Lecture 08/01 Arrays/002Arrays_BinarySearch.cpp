#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 40, 50, 60, 70};
	int n = sizeof(arr) / sizeof(int);

	int t = 10;

	int s = 0; // denotes the start of the search space
	int e = n-1; // denotes the end of the search space

	while(s <= e) {
		int m = s + ((e-s)>>1); // s + (e-s)/2; // (s+e)/2;
		if(arr[m] == t) {
			// you've found the target 't' at index 'm'
			cout << t << " found at index " << m << endl;
			break;
		} else {
			if(arr[m] > t) {
				// reduce the search space from  [s, e] to [s, m-1]
				e = m-1;
			} else { // arr[m] < t
				// reduce the search space from [s, e] to [m+1, e]
				s = m+1;
			}
		}
	}

	if(s > e) {
		cout << t << " not found!" << endl;
	}

	return 0;
}