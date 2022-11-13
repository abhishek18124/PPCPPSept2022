#include<iostream>

using namespace std;

void print(int(*arr)[4], int m, int n) { // or print(int arr[][4], int m, int n)
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main() {

	int arr[3][4] = {{10, 15, 20, 25}, 
	                 {30, 35, 40, 45}, 
	                 {50, 55, 60, 65}};

	int m = 3;
	int n = 4;

	cout << arr[2][1] << endl;
	cout << *((int*)(arr+2)+1) << endl;

	print(arr, m, n);

	return 0;
}