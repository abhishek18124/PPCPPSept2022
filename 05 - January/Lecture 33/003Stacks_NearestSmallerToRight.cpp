#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	int arr[] = {2, 5, 1, 3, 6, 4, 0};
	int n = sizeof(arr) / sizeof(int);

	vector<int> nsr; // nearest_smaller_to_the_right
	stack<pair<int, int>> s;

	for(int i=n-1; i>=0; i--) {

		// find the index of the nearest smaller element to the right of arr[i]

		while(!s.empty() and s.top().first >= arr[i]) {
			s.pop();
		}

		if(!s.empty()) {
			nsr.push_back(s.top().second);
		} else {
			nsr.push_back(n);
		}

		s.push({arr[i], i}); // or s.push(make_pair(arr[i], i))

	}

	reverse(nsr.begin(), nsr.end());

	for(int i=0; i<nsr.size(); i++) {
		cout << nsr[i] << " ";
	}

	return 0;
}