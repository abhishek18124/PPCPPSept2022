#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main() {

	// time : O(n+k) space : O(n)

	int arr[] = {10, 10, 10, 20, 20, 30, 40, 50, 50, 60, 60, 60};
	int n = sizeof(arr) / sizeof(int);
	int k = 3;

	unordered_map<int, int> freqMap;
	for(int i=0; i<n; i++) {
		freqMap[arr[i]]++;
	}

	vector<vector<int>> v(n+1); // reverse freqMap
	for(pair<int, int> p : freqMap) {
		v[p.second].push_back(p.first);
	}

	bool flag = false; // we've not found the k-most frequent elements

	for(int i=n; i>=1; i--) {
		vector<int> temp = v[i];
		for(int j=0; j<temp.size(); j++) {
			cout << temp[j] << " ";
			k--;
			if(k == 0) {
				// we've found k-most frequent elements
				flag = true;
				break;
			}
		}

		if(flag) {
			// we've found k-most frequent elements
			break;
		}
	}

	return 0;
}

