#include<iostream>

using namespace std;

bool isAnagram(char* str1, char* str2) {

	// 1. build a frequency array corr. to str1
	int freq1[26] = {};
	
	// for(char ch : str1) {
	// 	int idx = ch-'a';
	// 	freq1[idx]++;
	// }

	for(int i=0; str1[i] != '\0'; i++) {
		char ch = str1[i];
		int idx = ch-'a';
		freq1[idx]++;
	}

	for(int i=0; i<26; i++) {
		cout << freq1[i] << " ";
	}

	cout << endl;

	// 2. build a frequency array corr. to str2
	int freq2[26] = {};
	
	// for(char ch : str2) {
	// 	freq2[ch-'a']++;
	// } 

	for(int i=0; str2[i] != '\0'; i++) {
		freq2[str2[i]-'a']++;
	}


	for(int i=0; i<26; i++) {
		cout << freq2[i] << " ";
	}

	cout << endl;

	// 3. compare the two frequency arrays
	for(int i=0; i<26; i++) {
		if(freq1[i] != freq2[i]) {
			// str1 and str2 are not anagrams
			return false;
		}
	}

	// str1 and str2 are anagrams
	return true;

}

int main() {

	char str1[] = "state";
	char str2[] = "taste";

	isAnagram(str1, str2) ? cout << "true" << endl :
	                        cout << "false" << endl;

	return 0;
}