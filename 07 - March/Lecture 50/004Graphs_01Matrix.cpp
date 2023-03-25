// https://leetcode.com/problems/01-matrix/

#include<iostream>
#include<vector>
#include<climits>
#include<queue>

using namespace std;

// 1. brute-force approach - time : O(m^2.n^2)

// vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    
// 	int m = mat.size();
// 	int n = mat[0].size(); 

// 	vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

// 	// time : O(m^2.n^2)

// 	for(int i=0; i<m; i++) {
// 		for(int j=0; j<n; j++) {
// 			if(mat[i][j] == 0) {
// 				for(int ii=0; ii<m; ii++) {
// 					for(int jj=0; jj<n; jj++) {
// 						dist[ii][jj] = min(dist[ii][jj], abs(ii-i)+abs(jj-j));
// 					}
// 				}
// 			}
// 		}
// 	}

// 	return dist;

// }

// approach 2 - multi-source BFS

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    
	int m = mat.size();
	int n = mat[0].size(); 

	vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

	// for multi-source BFS, initialise the queue with all the source vertices i.e. vertices with the values 0
	queue<pair<int, int>> q;
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			if(mat[i][j] == 0) {
				// (i, j)th cell corresponds to a source vertex
				dist[i][j] = 0;
				q.push({i, j});
			}
		}
	}

	while(!q.empty()) {
		pair<int, int> front = q.front(); q.pop();
		int i = front.first;
		int j = front.second;

		int dx[] = {0, 0, 1, -1};
		int dy[] = {1, -1, 0, 0};
		for(int k=0; k<4; k++) {
			int n_x = i+dx[k];
			int n_y = j+dy[k];
			if(n_x >= 0 and n_x < m and n_y >= 0 and n_y < n && dist[n_x][n_y] == INT_MAX) {
				// vertex corresponding to the cell at (n_x, n_y) is not yet visited since its dist. is not cal.
				dist[n_x][n_y] = 1+dist[i][j];
				q.push({n_x, n_y});
			}
		}

	}

 	return dist;

}


int main() {

	vector<vector<int>> mat = {{0, 1, 1, 1, 0}, 
                               {1, 1, 1, 1, 1}, 
                               {1, 1, 0, 1, 1}, 
                               {1, 1, 1, 1, 1},
                               {0, 1, 1, 1, 0}};

	vector<vector<int>> dist = updateMatrix(mat);
	for(vector<int> row : dist) {
		for(int col : row) {
			cout << col << " ";
		}
		cout << endl;
	}

	return 0;
}