#include<iostream>

using namespace std;

void read(int** arr, int m, int n) {
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cin >> arr[i][j];
		}
	}
}

void print(int** arr, int m, int n) {
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int main() {

	int m = 3;
	int n = 4;

	int** arr = new int*[m];

	for(int i=0; i<m; i++) {
		arr[i] = new int[n];
	}

	read(arr, m, n);

	print(arr, m, n);

	for(int i=0; i<m; i++) {
		delete [] arr[i];
	}

	delete [] arr;

	return 0;
}