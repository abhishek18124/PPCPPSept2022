#include<iostream>

using namespace std;

int main() {

	int m;
	cout << "enter the no. of rows : ";
	cin >> m;

	int n;
	cout << "enter the no. of columns : ";
	cin >> n;

	// create a 2D array of dimension 'mxn' on the heap memory

	int** arr = new int*[m];

	// arr[0] = new int[n];
	// arr[1] = new int[n];
	// arr[2] = new int[n];
	// ...
	// arr[m-1] = new int[n];

	for(int i=0; i<m; i++) {
		arr[i] = new int[n];
	}


	// read values into the 2D array

	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cin >> arr[i][j];
		}
	}

	// print value of the 2D array

	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			// cout << arr[i][j] << " ";
			cout << *(*(arr+i)+j) << " ";
		}
		cout << endl;
	}

	// deallocate memory for 2D array 

	for(int i=0; i<m; i++) {
		delete [] arr[i];
	}

	delete [] arr;

	return 0;
}