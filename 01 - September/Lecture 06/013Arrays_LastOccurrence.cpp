#include<iostream>

using namespace std;

int main() {

	
	int arr[] = {10, 20, 30, 10, 20};
	int n = sizeof(arr) / sizeof(int);

	int t = 100;

	int i;

	for(i=n-1; i >= 0; i--) {

		if(arr[i] == t) {
			// found the target
			cout << i << endl;
			break;
		}

	}

	if(i == -1) {
		// target not found
		cout << -1 << endl;
	}




	return 0;
}