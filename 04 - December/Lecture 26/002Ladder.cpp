/*

Suppose there is a ladder with n steps. A person standing at the bottom of the ladder and wants to 
reach to its top. Assume the person can take atmost k steps at a time. Then, count the number 
of ways, the person can reach the top of the ladder.

Example 
	Input : n = 4, k = 3
	Output: 7
	Explanation : [1, 1, 1, 1], 
	              [1, 1, 2], 
	              [1, 2, 1], 
	              [2, 1, 1],
	              [2, 2],
	              [1, 3],
	              [3, 1]

*/
#include<iostream>

using namespace std;

int countNumberOfWays(int n, int k, int i, string out) {

	// base case 

	if(i == n) {
		cout << out << " ";
		return 1;
	}

	if(i > n) {
		return 0;
	}

	// recursive case

	// decide while standing at the ith step, the size of your next jump (1 to k)

	int count = 0;

	for(int j=1; j<=k; j++) {
		// if(i+j <= n) {
		// 	// take a jump of size j to reach the (i+j)step from the ith step
		//	count += countNumberOfWays(n, k, i+j);
		// } else {
		// 	break;
		// }

		// out += to_string(j);
		// count += countNumberOfWays(n, k, i+j, out);
		// out.pop_back(); // back tracking step

		

		count += countNumberOfWays(n, k, i+j, out+to_string(j));
		
	}

	return count;

}

int main() {

	int n = 4;
	int k = 3;

	string out;

	cout << countNumberOfWays(n, k, 0, out) << endl;

	return 0;
}