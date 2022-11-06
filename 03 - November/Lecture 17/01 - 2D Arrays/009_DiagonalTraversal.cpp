/*

	constraints :

	0 < m, n <= 10

*/

#include<iostream>

using namespace std;

void printDiagonal(int mat[][10], int m, int n, int i, int j) {
	int diagonalLength = min(m-i, n-j);
	for(int k=0; k<diagonalLength; k++) {
		cout << mat[i+k][j+k] << " ";
	}
}

void traverse(int mat[][10], int m, int n) {

	for(int i=m-1; i>=0; i--) {
		// print the diagonal starting at the (i, 0)th index
		printDiagonal(mat, m, n, i, 0);
	}

	for(int j=1; j<n; j++) {
		// print the diagonal starting at the (0, j)th index
		printDiagonal(mat, m, n, 0, j);
	}

}

int main() {
	
	int mat[10][10] = {{11, 12, 13, 14},
					   {15, 16, 17, 18},
					   {19, 20, 21, 22}};

	int m = 3;
	int n = 4;

	traverse(mat, m, n);
	
	return 0;
}