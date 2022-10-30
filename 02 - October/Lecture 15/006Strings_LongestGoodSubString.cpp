#include<iostream>
#include<algorithm>

using namespace std;

bool isGoodString(string str) {
	for(int i=0; i<str.size(); i++) {
		char ch = str[i];
		if(!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
			// ch is a consonant therefore, str is not a good string
			return false;
		}
	}
	// str is a good string
	return true;
}


int main() {

	string str = "cbaeicdeiou";
	int n = str.size();

	// // approach 1 - time : O(n^3) space : O(1)
	
	// int max_len = 0; // to track the length of the longest good substring
	// int s_index; // to track the starting index of the longest good substring

	// // iterate over all the possible starting indices
	// for(int i=0; i<n; i++) {
	// 	// iterate over all the possible ending indices
	// 	for(int j=i; j<n; j++) {
	// 		// extract the substring that starts at the ith index and ends at the jth index
	// 		string subString = str.substr(i, j-i+1);
	// 		// check if the subString is a good subString or not
	// 		if(isGoodString(subString)) {
	// 			// track its length
				
	// 			// max_len = max(max_len, j-i+1);
				
	// 			if(j-i+1 > max_len) {
	// 				max_len = j-i+1;
	// 				s_index = i;
	// 			}

	// 		}
	// 	}
	// }

	// cout << str.substr(s_index, max_len);
	// // cout << max_len << endl;

	// approach - 2 time : O(n) space : O(1)

	int count = 0;
	int max_len = 0; // to track the length of the longest good substring

	for(int i=0; i<str.size(); i++) {
		char ch = str[i];
		if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
			// ch is a vowel
			count++;
			max_len = max(max_len, count);
		} else {
			// ch is consonant
			count = 0;
		}
	}

	cout << max_len << endl;
	
	return 0;
}