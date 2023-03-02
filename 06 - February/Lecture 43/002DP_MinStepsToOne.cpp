/*

Given a number n, count the minimum steps to reduce n to 1 
such that at each step you may

	reduce n to n/2 if n is divisible by 2
	or reduce n to n/3 if n is divisible by 3
	or reduce n to n-1 by decrementing n by 1

Example :
	Input : n = 10
	Output : 3

	Input : 6
	Output : 2

*/

#include<iostream>
#include<vector>

using namespace std;

int minSteps(int n) {

	// base case
	if(n == 1) {
		// count min. steps required to reduce 1 to 1
		return 0;
	}

	// recursive case 

	// count min. steps requried to reduce n to 1

	// option 1 : reduce n to n-1
	int x = minSteps(n-1);

	// option 2 : reduce n to n/2 given that n%2 == 0
	int y = INT_MAX;
	if(n%2 == 0) {
		y = minSteps(n/2);
	}

	// option 3 : reduce n to n/3 given that n%3 == 0
	int z = INT_MAX;
	if(n%3 == 0) {
		z = minSteps(n/3);
	}

	return 1 + min(x, min(y, z));

}


int minStepsTopDown(int n, vector<int>& dp) {

	// lookup
	if(dp[n] != -1) {
		return dp[n];
	}

	// base case
	if(n == 1) {
		// count min. steps required to reduce 1 to 1
		return dp[n]=0;
	}

	// recursive case 

	// count min. steps requried to reduce n to 1

	// option 1 : reduce n to n-1
	int x = minStepsTopDown(n-1, dp);

	// option 2 : reduce n to n/2 given that n%2 == 0
	int y = INT_MAX;
	if(n%2 == 0) {
		y = minStepsTopDown(n/2, dp);
	}

	// option 3 : reduce n to n/3 given that n%3 == 0
	int z = INT_MAX;
	if(n%3 == 0) {
		z = minStepsTopDown(n/3, dp);
	}

	return dp[n] = 1 + min(x, min(y, z));

}

// time : O(n) space : O(n)

int minStepsBottomUp(int n) {

	vector<int> dp(n+1); // we will not use the 0th index

	dp[1] = 0; // dp[1] = f(1) is a function which computes min. steps required to reduce 1 to 1

	for(int i=2; i<=n; i++) {

		// compute dp[i] = f(i)

		// option 1 : reduce i to i-1
		int x = dp[i-1];

		// option 2 : reduce i to i/2 given that i%2 == 0
		int y = INT_MAX;
		if(i%2 == 0) {
			y = dp[i/2];
		}

		// option 3 : reduce i to i/3 given that i%3 == 0
		int z = INT_MAX;
		if(i%3 == 0) {
			z = dp[i/3];
		}

		dp[i] = 1 + min(x, min(y, z));

	}

	return dp[n]; // stores the result of f(n) which is our original problem

}


int main() {

	int n = 10;

	cout << minSteps(n) << endl;

	vector<int> dp(n+1, -1); // we will not use the 0th index

	cout << minStepsTopDown(n, dp) << endl;

	cout << minStepsBottomUp(n) << endl;
		
	return 0;
}