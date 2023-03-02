/*

given a number n, find the nth fibonacci no.

Example :
	Input : n = 7
	Output : 13

*/

#include<iostream>
#include<vector>

using namespace std;

int fibo(int n) {

	// base case
	if(n == 0 || n == 1) {
		return n;
	}

	// recursive case
	return fibo(n-1) + fibo(n-2);
}


int fiboTopDown(int n, vector<int>& dp) {

	//  lookup
	if(dp[n] != -1) {
		return dp[n];
	}

	// base case
	if(n == 0 || n == 1) {
		return dp[n] = n;
	}

	// recursive case
	return dp[n] = fiboTopDown(n-1, dp) + fiboTopDown(n-2, dp);
}

// time : O(n) space : O(n)

int fiboBottomUp(int n) {

	vector<int> dp(n+1);

	dp[0] = 0; // since at the 0th index, we store the result of f(0) which is 0
	dp[1] = 1; // since at the 1st index, we store the result of f(1) which is 1

	for(int i=2; i<=n; i++) {
		// compute dp[i] = f(i) is a function which computes the ith fibonacci no.
		dp[i] = dp[i-1] + dp[i-2];
	}

	return dp[n];

}

// time : O(n) space : O(1)

int fiboBottomUpSpaceOptimised(int n) {
	int a = 0; // to track the n-2th fibonacci no (initially it is 0th fibonacci no.)
	int b = 1; // to track the n-1th fibonacci no (initially it is 1st fibonacci no.)

	for(int i=2; i<=n; i++) {
		int c = a+b;
		a = b;
		b = c;
	}

	return b;
}

int main() {

	int n = 7;

	// cout << fibo(n) << endl;

	vector<int> dp(n+1, -1);

	cout << fiboTopDown(n, dp) << endl;

	cout << fiboBottomUp(n) << endl;

	cout << fiboBottomUpSpaceOptimised(n) << endl;

	return 0;
}