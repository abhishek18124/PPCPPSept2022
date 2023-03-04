/*

Given a m x n grid filled with non-negative numbers, find a path from (0, 0) to (m-1, n-1), 
which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example : 
	Input: grid = [[1,3,1],
	               [1,5,1],
	               [4,2,1]]

	Output: 7
	Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Constraints :
	1 <= m, n <= 200
	0 <= grid[i][j] <= 100

*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int minSumPath(vector<vector<int>> grid, int i, int j) {

	// base case
	if(i == 0 and j == 0) {
		// compute the sum of nos. along the minSum path 
		// to reach the (0,0)th cell from (0,0)th cell.
		
		return grid[0][0];
	}

	// recursive cases

	if(i == 0) {
		// compute the sum of nos. along the minSum path to 
		// reach a cell in (i, j)th cell which is in the 0th 
		// row
		return grid[i][j] + minSumPath(grid, i, j-1);
	}

	if(j == 0) {
		// compute the sum of nos. along the minSum path to 
		// reach a cell in (i, j)th cell which is in the 0th 
		// column
		return grid[i][j] + minSumPath(grid, i-1, j);
	}

	// compute the sum of nos. along the minSum path to 
	// reach a cell in (i, j)th cell which is neither in
	// the 0th row or in the 0th column

	int X = minSumPath(grid, i, j-1);
	int Y = minSumPath(grid, i-1, j);

	return grid[i][j] + min(X, Y);
}

int minSumPathTopDown(vector<vector<int>> grid, int i, int j, vector<vector<int>>& dp) {

	if(dp[i][j] != -1) {
		return dp[i][j];
	}

	// base case
	if(i == 0 and j == 0) {
		// compute the sum of nos. along the minSum path 
		// to reach the (0,0)th cell from (0,0)th cell.
		
		return dp[i][j]=grid[0][0];
	}

	// recursive cases

	if(i == 0) {
		// compute the sum of nos. along the minSum path to 
		// reach a cell in (i, j)th cell which is in the 0th 
		// row
		return dp[i][j] = grid[i][j] + minSumPathTopDown(grid, i, j-1, dp);
	}

	if(j == 0) {
		// compute the sum of nos. along the minSum path to 
		// reach a cell in (i, j)th cell which is in the 0th 
		// column
		return dp[i][j] = grid[i][j] + minSumPathTopDown(grid, i-1, j, dp);
	}

	// compute the sum of nos. along the minSum path to 
	// reach a cell in (i, j)th cell which is neither in
	// the 0th row or in the 0th column

	int X = minSumPathTopDown(grid, i, j-1, dp);
	int Y = minSumPathTopDown(grid, i-1, j, dp);

	return dp[i][j] = grid[i][j] + min(X, Y);
}

// time : O(m.n) space : O(m.n)

int minSumPathBottomUp(vector<vector<int>> grid, int m, int n) {

	vector<vector<int>> dp(m, vector<int>(n));

	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			// dp[i][j] = f(i, j)
			if(i == 0 and j == 0) {
				//  base case
				dp[i][j] = grid[i][j];
			} else if(i == 0) {
				dp[i][j] = grid[i][j] + dp[i][j-1];
			} else if(j == 0) {
				dp[i][j] = grid[i][j] + dp[i-1][j];
			} else {
				dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	return dp[m-1][n-1];

}

int main() {

	vector<vector<int>> grid = {{1, 3, 1},
   								{1, 5, 1},
   								{4, 2, 1}};

   	int m = grid.size();
   	int n = grid[0].size();

   	cout << minSumPath(grid, m-1, n-1) << endl;

   	vector<vector<int>> dp(m, vector<int>(n, -1));
   	cout << minSumPathTopDown(grid, m-1, n-1, dp) << endl;

   	cout << minSumPathBottomUp(grid, m, n) << endl;


	return 0;
}