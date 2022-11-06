/*

	Constraints :

	0 < m, n <= 10

*/

#include<iostream>

using namespace std;

void transpose(int mat[][10], int m, int n) {

	// for(int i=0; i<m; i++) {
	// 	for(int j=0; j<n; j++) {
	// 		if(i < j) { // or i > j
	// 			swap(mat[i][j], mat[j][i]);
	// 		}
	// 	}
	// }

	for(int i=0; i<m; i++) {
		for(int j=i+1; j<n; j++) {
			swap(mat[i][j], mat[j][i]);
		}
	}
}

int main() {

	int m, n;
	cin >> m >> n;

	int mat[10][10];
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cin >> mat[i][j];
		}
	}

	cout << "matrix before transpose = " << endl;
	
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl << endl;
	
	transpose(mat, m, n);

	cout << "matrix after transpose = " << endl;
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}


	return 0;
}