/*

	Constraints :

	0 < m, n <= 10

*/

#include<iostream>

using namespace std;

int main() {
	
	// int mat[10][10] = {{11, 12, 13, 14},
	// 				   {22, 23, 24, 15},
	// 				   {21, 26, 25, 16},
	// 				   {20, 19, 18, 17}};

	// int m = 4;
	// int n = 4;

	int mat[10][10] = {{11, 12, 13, 14},
					   {22, 23, 24, 15},
					   {21, 26, 25, 16}};

	int m = 3;
	int n = 4;

	int sr = 0;
	int sc = 0;
	int er = m-1;
	int ec = n-1;

	while(sr <= er and sc <= ec) {

		// 1. print the sr -> it. from sc to ec
		for(int j=sc; j<=ec; j++) {
			cout << mat[sr][j] << " ";
		}

		sr++;

		// 2. print the ec -> it. from sr to er
		for(int i=sr; i<=er; i++) {
			cout << mat[i][ec] << " ";
		}

		ec--;

		// 3. print the er -> it. from ec to sc

		if(sr <= er) {
			for(int j=ec; j>=sc; j--) {
				cout << mat[er][j] << " ";
			}

			er--;
		}

		// 4. print the sc -> it. from er to sr
		if(sc <= ec) {
			for(int i=er; i>=sr; i--) {
				cout << mat[i][sc] << " ";
			}

			sc++;
		}
	}
	
	return 0;
}