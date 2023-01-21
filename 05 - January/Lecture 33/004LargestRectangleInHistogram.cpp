#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	int h[] = {2, 1, 5, 6, 2, 3};
	int n = sizeof(h) / sizeof(int);

	vector<int> nsl; // nearest_smaller_to_the_left
	stack<pair<int, int>> s;

	for(int i=0; i<n; i++) {

		// find the index of the nearest smaller element to the left of h[i]

		while(!s.empty() and s.top().first >= h[i]) {
			s.pop();
		}

		if(!s.empty()) {
			nsl.push_back(s.top().second);
		} else {
			nsl.push_back(-1);
		}

		s.push({h[i], i}); // or s.push(make_pair(arr[i], i))

	}

	// empty to stack to reuse it for computing nsr

	while(!s.empty()) {
		s.pop();
	}

	vector<int> nsr; // nearest_smaller_to_the_right
	
	for(int i=n-1; i>=0; i--) {

		// find the index of the nearest smaller element to the right of h[i]

		while(!s.empty() and s.top().first >= h[i]) {
			s.pop();
		}

		if(!s.empty()) {
			nsr.push_back(s.top().second);
		} else {
			nsr.push_back(n);
		}

		s.push({h[i], i}); // or s.push(make_pair(h[i], i))

	}

	reverse(nsr.begin(), nsr.end());

	int maxArea = 0;

	for(int i=0; i<n; i++) {

		// compute the area of the largest rectangle under the historgram which completely uses the ith bar

		int w_i = nsr[i]-nsl[i]-1;
		int a_i = w_i*h[i];
		maxArea = max(maxArea, a_i);

	}

	cout << maxArea << endl;


	return 0;
}