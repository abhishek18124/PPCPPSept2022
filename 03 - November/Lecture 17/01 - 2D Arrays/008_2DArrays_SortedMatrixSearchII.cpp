#include<iostream>

using namespace std;

bool matrixSearch(int mat[][3], int m, int n, int t) {

	int i = 0; // or m-1
	int j = n-1; // or 0

	while(i < m and j >= 0) {
		if(mat[i][j] == t) {
			return true;
		} else if(t > mat[i][j]) {
			// 't' can never be present in the ith row
			i++;
		} else {
			// 't' can never be present in the jth column
			j--;
		}
	}

	return false;

}

int main() {

	int mat[][3] = {{10, 20, 30},
					{40, 50, 60},
					{70, 80, 90}};

	int m = 3;
	int n = 3;

	int t = 100;

	matrixSearch(mat, m, n, t) ? cout << t << " found!" << endl :
	                             cout << t << " not found!" << endl;

	return 0;
}