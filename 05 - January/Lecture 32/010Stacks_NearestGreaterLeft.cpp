#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main() {

	int arr[] = {5, 2, 0, 4, 1, 3, 6};
	int n = sizeof(arr) / sizeof(int);

	vector<int> ngl; // nearest_greater_to_the_left
	stack<int> s;

	for(int i=0; i<n; i++) {

		// find the nearest greater to the right of arr[i]

		while(!s.empty() and s.top() <= arr[i]) {
			s.pop();
		}

		if(!s.empty()) {
			ngl.push_back(s.top());
		} else {
			ngl.push_back(-1);
		}

		s.push(arr[i]);

	}

	// reverse(ngr.begin(), ngr.end());

	for(int i=0; i<ngl.size(); i++) {
		cout << ngl[i] << " ";
	}


	return 0;
}