#include<iostream>
#include<vector>

using namespace std;

bool isPalindrome(string str) {
	int i = 0;
	int j = str.size()-1;
	while(i < j) {
		if(str[i] != str[j]) {
			return false;
		}
		i++;
		j--;
	}
	return true;
}

int countPalindromicPartitioning(string str, int i, vector<string>& partition) {
	
	// base case
	
	if(i == str.size()) {
		// count the number of palindromic partitioning of str[n...n-1] 
		for(string subString : partition) {
			cout << subString << " ";
		}
		cout << endl;
		return 1;
	}

	// recursive case
	
	// count the number of palindromic partitioning of str[i...n-1] 
	
	// decide the next cut

	int count = 0;
	for(int j=i; j<str.size(); j++) {
		// can you make a cut at the jth index ?
		string subString = str.substr(i, j-i+1);
		if(isPalindrome(subString)) {
			// you can make a cut at the the jth index
			// ask your friend to count no. of palindromic partitioning of str[j+1...n-1]
			partition.push_back(subString);
			count += countPalindromicPartitioning(str, j+1, partition);
			partition.pop_back(); // back-tracking

		}
	}

	return count;

}

int countPalindromicPartitioningBottomUp(string str) {
	int n = str.size();
	vector<int> dp(n+1);

	dp[n] = 1; // dp[n] = f(n)

	for(int i=n-1; i>=0; i--) {
		// dp[i] = f(i)
		int count = 0;
		for(int j=i; j<n; j++) {
			// can you make a cut at the jth index ?
			string subString = str.substr(i, j-i+1);
			if(isPalindrome(subString)) {
				// you can make a cut at the the jth index
				// ask your friend to count no. of palindromic partitioning of str[j+1...n-1]
				count += dp[j+1];
			}
		}

		dp[i]=count;
	}

	return dp[0];
}

int main() {

	string str = "aaa";
	vector<string> partition;

	cout << countPalindromicPartitioning(str, 0, partition) << endl;
	cout << countPalindromicPartitioningBottomUp(str) << endl;
	
	return 0;
}