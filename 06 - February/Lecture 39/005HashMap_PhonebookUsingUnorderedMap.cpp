/*

	Implement a phonebook storing mapping between person's name and 
	their phone numbers using an unordered_map.

*/

#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int main() {

	unordered_map<string, vector<string>> phoneMap;

	phoneMap["Rishabh"].push_back("1234");
	phoneMap["Rishabh"].push_back("4567");

	phoneMap["Yashika"].push_back("0000");

	phoneMap["Yash"].push_back("1111");

	for(pair<string, vector<string>> p : phoneMap) {
		string name = p.first;
		vector<string> numbers = p.second;
		cout << name << " : ";
		for(string num : numbers) {
			cout << num << " ";
		}
		cout << endl;
	}

	return 0;
}