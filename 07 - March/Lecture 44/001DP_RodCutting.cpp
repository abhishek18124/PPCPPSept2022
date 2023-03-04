/*



Given a rod of length 'n' along with prices of its pieces of different lengths, design an algorithm to 
compute the maximum profit we can make by cutting the rod and a selling its pieces. 

Example :
	
	Input : n = 8
	        length : [1,  2,  3,  4,  5,  6,  7,  8]
	        prices : [1,  5,  8,  9,  10, 17, 17, 20]
	Output : 22

	Input : n = 8
	        length : [1,  2,  3,  4,  5,  6,  7,  8]
	        prices : [3,  5,  8,  9, 10, 17, 17, 20]
	Output : 24

	
*/


#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int maxProfit(int n, vector<int> p) {

	// base case
	if(n == 0) {
		// compute the max. profit given a rod of length 0
		return 0;
	}

	// recursive case

	// compute the max. profit given a rod of length n

	int ans = 0; // or INT_MIN
	for(int j=1; j<=n; j++) {
		ans = max(ans, p[j-1]+maxProfit(n-j, p));
	}

	return ans;

}

int maxProfitTopDown(int n, vector<int> p, vector<int>& dp) {

	// lookup
	if(dp[n] != -1) {
		return dp[n];
	}

	// base case
	if(n == 0) {
		// compute the max. profit given a rod of length 0
		return dp[n]=0;
	}

	// recursive case

	// compute the max. profit given a rod of length n

	int ans = 0; // or INT_MIN
	for(int j=1; j<=n; j++) {
		ans = max(ans, p[j-1]+maxProfitTopDown(n-j, p, dp));
	}

	return dp[n]=ans;

}

int maxProfitBottomUp(int n, vector<int> p) {

	vector<int> dp(n+1);
	dp[0] = 0; // dp[0] = f(0) : base case

	for(int i=1; i<=n; i++) {
		// dp[i] = f(i) : max. profit you can make given a rod of length i
		int ans = 0; // or INT_MIN
		for(int j=1; j<=i; j++) {
			ans = max(ans, p[j-1]+dp[i-j]);
		}

		dp[i]=ans;
	}

	return dp[n]; // dp[n] = f(n) : original problem

}

int main() {

	vector<int> p = {1, 5, 8, 9, 10, 17, 17, 20};
	int n = p.size();

	cout << maxProfit(n, p) << endl;

	vector<int> dp(n+1, -1);
	cout << maxProfitTopDown(n, p, dp) << endl;

	cout << maxProfitBottomUp(n, p) << endl;
		
	return 0;
}