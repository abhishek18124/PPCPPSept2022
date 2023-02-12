#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int longestPalindrome(string str) {

	int count = 0;
	unordered_set<char> seen;
	string out = "";
	for(char ch : str) {
		if(seen.find(ch) != seen.end()) {
			out = out + string(1, ch);
			out = string(1, ch) + out;
			count += 2;
			seen.erase(ch);
		} else {
			seen.insert(ch);
		}
	}

	if(seen.size() > 0) {
		char ch = *(seen.begin());
		cout << out.substr(0, count/2) + string(1, ch) + out.substr(count/2) << endl;
	}  else {

		cout << out << endl;
	}
	
	return seen.size() > 0 ? count+1 : count;

}

int main() {

	string str = "abccccdd";

	cout << longestPalindrome(str) << endl;
	
	return 0;
}