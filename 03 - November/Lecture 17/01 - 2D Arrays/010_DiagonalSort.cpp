/*

	constraints :

	0 < m, n <= 10

*/

#include<iostream>

using namespace std;

void sortDiagonal(int mat[][10], int m, int n, int i, int j) {
	int diagonalLength = min(m-i, n-j);
	int diagonal[10]; // based on the contraints

	// 1. copy the elements of the diagonal starting from (i, j)th index into an array 'diagonal'
	for(int k=0; k<diagonalLength; k++) {
		diagonal[k] = mat[i+k][j+k];
	}

	// 2. sort the array containing diagonal elements
	sort(diagonal, diagonal+diagonalLength);

	// 3. copy sorted diagonal into matrix
	for(int k=0; k<diagonalLength; k++) {
		mat[i+k][j+k] = diagonal[k];
	}
	
}

void finalSort(int mat[][10], int m, int n) {

	for(int i=m-1; i>=0; i--) {
		// print the diagonal starting at the (i, 0)th index
		sortDiagonal(mat, m, n, i, 0);
	}

	for(int j=1; j<n; j++) {
		// print the diagonal starting at the (0, j)th index
		sortDiagonal(mat, m, n, 0, j);
	}

}

int main() {
	
	int mat[10][10] = {{50, 80, 20},
					   {90, 10, 70},
					   {60, 30, 40}};

	int m = 3;
	int n = 3;

	finalSort(mat, m, n);

	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
	
	return 0;
}