/*

You are given an integer array coins representing coins of different denominations 
and an integer amount representing a total amount of money.Return the fewest number 
of coins that you need to make up that amount. 

You may assume that you have an infinite number of each kind of coin.

Don't forget to handle the case if that amount of money cannot be made up by any 
combination of the coins.

Example 1:

	Input: coins = [1,2,5], amount = 11
	Output: 3

	Input: coins = [3, 6], amount = 13
	Output: - 

*/

#include<iostream>
#include<vector>

using namespace std;

int minCoins(int n, vector<int>& c) {

	// base case
	if(n == 0) {
		// count min. no. of coins required to reduce 0 to 0
		return 0;
	}

	// recursive case

	// count min. no. of coins required to reduce n to 0

	int k = c.size();
	int res = INT_MAX;

	for(int j=0; j<k; j++) {
		if(n-c[j] >= 0) {
			// compute the min. no. of coins required to reduce n-c[j] to 0 -> friend
			res = min(res, minCoins(n-c[j], c));
		}
	}

	return res == INT_MAX ? INT_MAX : 1 + res;

}

int main() {

	int n = 3;
	vector<int> c = {2, 5};

	int res = minCoins(n, c);

	res == INT_MAX ? cout << "no solution exists" << endl :
	                 cout << res << endl;

	return 0;
}