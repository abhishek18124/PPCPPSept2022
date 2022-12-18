/*

Given a string (sequence of characters) of length n, generate all of its permutations. 

Example
	
	Input : inp[] = "abc"
	Output: ["abc", "acb", "bac", "bca", "cba", "cab"]

*/

#include<iostream>
#include<cstring>

using namespace std;

void generatePermutations(char* inp, int n, int i) {

	// base case
	if(i == n) {
		cout << inp << endl;
		return;
	}

	// recursive case

	// generate the permutations of inp[i...n-1]

	// make a decision for the ith position

	for(int j=i; j<=n-1; j++) {
		swap(inp[i], inp[j]);
		generatePermutations(inp, n, i+1);
		swap(inp[i], inp[j]); // back-tracking
	}

	return;

}

int main() {

	char inp[] = "abc";
	int n = strlen(inp);

	generatePermutations(inp, n, 0);

	return 0;
}
