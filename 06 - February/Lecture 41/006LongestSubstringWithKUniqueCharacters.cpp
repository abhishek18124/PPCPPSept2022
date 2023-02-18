#include<iostream>
#include<unordered_map>

using namespace std;

int main() {

	string s = "aabacbebebe";
	int n = s.size();
	int k = 3;

	int i=0; // to store the start of the window
	int j=0; // to store the end of the windw

	int max_len = 0; // to track the length of the longest substring
	                 // i.e. window that contain k unique characters
	
	int count = 0; // to keep track of no. of unique characters in the window
	
	unordered_map<char, int> freqMap; // to store a  mapping  between characters 
								      // present in a window & their frequencies
	
	while(j < n) {

		// expand the window
		freqMap[s[j]]++;
		if(freqMap[s[j]] == 1) {
			// you've found a unique char or you've seen the jth character for the first time
			count++;
		}

		// check for the violation of the window property
		while(count > k) {
			// shrink the window
			freqMap[s[i]]--;
			if(freqMap[s[i]] == 0) {
				count--;
			}
			i++;
		}
		
		// check for the validity of the window, and update the answer
		if(count == k) {
			max_len = max(max_len, j-i+1);
		}

		// continue expansion of the window
		j++;
	}

	cout << max_len << endl;

	return 0;
}