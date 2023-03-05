/*

Example :
	Input : N = 5, W = 4
			weights[] = {1, 2, 3, 2, 2}
			profits[] = {8, 4, 1, 5, 3}
	Output: 13

*/


#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int> weights, vector<int> profits, 
			  int N, int i, int w) {

	// base case
	if(i == N) {
		return 0;
	}

	if(w == 0) {
		return 0;
	}

	// recursive case

	// compute the max. profit you can make given a seq. of object starting from the ith index such that current knapsack capacity is w

	// take a decision for the ith object

	if(weights[i] > w) {
		// we've no option but to exclude the ith object
		return maxProfit(weights, profits, N, i+1, w);
	}

	// 1. include

	int X = maxProfit(weights, profits, N, i+1, w-weights[i]);

	// 2. exclude

	int Y = maxProfit(weights, profits, N, i+1, w);

	return max(profits[i]+X, Y);

}

int maxProfitTopDown(vector<int> weights, vector<int> profits, 
			  int N, int i, int w, vector<vector<int>>& dp) {

	// lookup
	if(dp[i][w] != -1) {
		return dp[i][w];
	}

	// base case
	if(i == N) {
		return dp[i][w]=0;
	}

	if(w == 0) {
		return dp[i][w]=0;
	}

	// recursive case

	// compute the max. profit you can make given a seq. of object starting from the ith index such that current knapsack capacity is w

	// take a decision for the ith object

	if(weights[i] > w) {
		// we've no option but to exclude the ith object
		return maxProfitTopDown(weights, profits, N, i+1, w, dp);
	}

	// 1. include

	int X = maxProfitTopDown(weights, profits, N, i+1, w-weights[i], dp);

	// 2. exclude

	int Y = maxProfitTopDown(weights, profits, N, i+1, w, dp);

	return dp[i][w]=max(profits[i]+X, Y);

}


int maxProfitBottomUp(vector<int> weights, vector<int> profits, int N, int W) {

	vector<vector<int>> dp(N+1, vector<int>(W+1));

	// for(int i=0; i<=N; i++) {
	// 	dp[i][0] = 0;
	// }

	// for(int w=0; w<=W; w++) {
	// 	dp[N][w] = 0;
	// }

	for(int i=N-1; i>=0; i--) {
		for(int w=1; w<=W; w++) {
			// dp[i][w] = f(i, w)
			if(weights[i] > w) {
				// exclude
				dp[i][w] = dp[i+1][w];
			} else {
				dp[i][w] = max(profits[i]+dp[i+1][w-weights[i]], dp[i+1][w]);
			}

		}
	}

	return dp[0][W];

}

int main() {

	int N = 5;
	int W = 4;

	vector<int> weights = {1, 2, 3, 2, 2};
	vector<int> profits = {8, 4, 1, 5, 3};

	cout << maxProfit(weights, profits, N, 0, W) << endl;

	vector<vector<int>> dp(N+1, vector<int>(W+1, -1));

	cout << maxProfitTopDown(weights, profits, N, 0, W, dp) << endl;

	cout << maxProfitBottomUp(weights, profits, N, W) << endl;
	
	return 0;
}