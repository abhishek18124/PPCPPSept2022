#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// time : O(n) space : O(n)

bool containDuplicates(vector<int> v, int k) {

	unordered_map<int, int> indexMap; // val -> idx of last occ. of val

	for(int i=0; i<v.size(); i++) {
		if(indexMap.find(v[i]) != indexMap.end()) {
			// you've seen v[i] previously
			if(abs(indexMap[v[i]]-i) <= k) {
				return true;
			}
		}
		indexMap[v[i]] = i;
	}

	return false;

}

int main() {

	vector<int> v = {1, 2, 3, 1, 2, 3};
	int k = 2;

	containDuplicates(v, k) ? cout << "true" << endl :
	                          cout << "false" << endl;
	
	return 0;
}