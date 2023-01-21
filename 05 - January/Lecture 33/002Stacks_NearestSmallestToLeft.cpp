#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main() {

	int arr[] = {0, 3, 5, 4, 1, 6, 2};
	int n = sizeof(arr) / sizeof(int);

	vector<int> nsl; // nearest_smaller_to_the_left
	stack<pair<int, int>> s;

	for(int i=0; i<n; i++) {

		// find the index of the nearest smaller element to the left of arr[i]

		while(!s.empty() and s.top().first >= arr[i]) {
			s.pop();
		}

		if(!s.empty()) {
			nsl.push_back(s.top().second);
		} else {
			nsl.push_back(-1);
		}

		s.push({arr[i], i}); // or s.push(make_pair(arr[i], i))

	}

	for(int i=0; i<nsl.size(); i++) {
		cout << nsl[i] << " ";
	}


	return 0;
}