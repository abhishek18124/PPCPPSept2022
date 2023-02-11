#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

bool containsDuplicate(vector<int> v) {

	// unordered_map<int, int> freqMap;
	// for(int num : v) {
	// 	freqMap[num]++;
	// 	if(freqMap[num] > 1) {
	// 		// we've found a duplicate
	// 		return true;
	// 	}
	// }

	// // no duplicates found
	// return false;

	unordered_set<int> s;
	for(int num : v) {
		if(s.find(num) != s.end()) {
			// num is already present in the set, you've found a duplicate
			return true;
		}
		s.insert(num);
	}

	// no duplicate found
	return false;
	
}

int main() {

	vector<int> v = {1, 2, 3, 1};

	containsDuplicate(v) ? cout << "true" << endl :
	                       cout << "false" << endl;

	return 0;
}