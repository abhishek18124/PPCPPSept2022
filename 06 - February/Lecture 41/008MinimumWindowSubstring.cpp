#include<iostream>
#include<unordered_map>

using namespace std;

string minWindow(string s, string t) {

	int m = s.size();
	int n = t.size();

	unordered_map<char, int> tFreqMap; // to store a mapping  b/w characters 
								       // present in 't' & their frequencies

	int tCount = 0; // to store the no. of unique characters in 't'.

	                // to keep track of number of chacters of 't' with the
	                // required frequeny NOT present in the current window

	for(int i=0; i<n; i++) {
		char ch = t[i];
		tFreqMap[ch]++;
		if(tFreqMap[ch] == 1) tCount++;
	}

	// tCount = tFreqMap.size();

	int i=0; // to store the start of the window
	int j=0; // to store the end of the windw

	int min_len = INT_MAX; // to track the length of the minimum window 
	int s_index;   // to store the starting index of the minimum window 
	
	while(j < m) {

		// expand the window
		char ch = s[j];
		if(tFreqMap.find(ch) != tFreqMap.end()) {
			tFreqMap[ch]--;
			if(tFreqMap[ch] == 0) {
				// window has sufficient occurrences of 'ch'
				tCount--;
			}
		}

		// check for validity of the window
		if(tCount == 0) {
			// found a valid window
			if(min_len > j-i+1) {s_index=i; min_len=j-i+1;}
			// optimise the window length by shrinking it
			while(tCount == 0) {
				char out = s[i];
				if(tFreqMap.find(out) != tFreqMap.end()) {
					// 'out' is present in 't'
					tFreqMap[out]++;
					if(tFreqMap[out] == 1) {
						// window no longer has sufficient occurrences
						// of 'out' therefore it is no longer valid.
						i++;
						tCount++;
					} else {
						// you have sufficient occurrences of 'out'
						// in the  window  hence it is still valid.
						i++;
						if(min_len > j-i+1) {s_index=i; min_len=j-i+1;}
					}
				} else {
					// 'out' was an  unnecessary character in the
					// window therefore the window is still valid.
					i++;
					if(min_len > j-i+1) {s_index=i; min_len = j-i+1;}
				}
			}
		}

		// continue with the expansion of the window
		j++;

	}

	return min_len == INT_MAX ? "" : s.substr(s_index, min_len);
}

int main() {

	string s = "adobecodebanc";
	string t = "abc";

	cout << minWindow(s, t) << endl;

	return 0;
}