#include<vector>
#include<iostream>

using namespace std;

int main() {

	// vector<vector<int>> v;

	// vector<vector<int>> v(3, vector<int>(4));

	// vector<vector<int>> v(3, vector<int>(4, 1));

	// int m = v.size(); // rows
	// int n = v[0].size(); // columns

	// for(int i=0; i<m; i++) {
	// 	for(int j=0; j<n; j++) {
	// 		cout << v[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;

	// for(vector<int> x : v) {
	// 	for(int el : x) {
	// 		cout << el << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;


	vector<vector<int>> v = {{1, 2, 3},
							 {4, 5, 6},
							 {7, 8, 9}};

	for(int i=0; i<v.size(); i++) {
		for(int j=0; j<v[0].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;


	return 0;
}