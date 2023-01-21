#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main() {

	int arr[] = {100, 80, 60, 70, 60, 75, 85};
	int n = sizeof(arr) / sizeof(int);

	vector<int> span; // to store the span of stock prices
	stack<pair<int, int>> s;

	for(int i=0; i<n; i++) {

		// find the nearest greater to the right of arr[i]

		while(!s.empty() and s.top().first <= arr[i]) {
			s.pop();
		}

		int j;

		if(!s.empty()) {
			j = s.top().second;	
		} else {
			j = -1;
		}

		span.push_back(i-j);

		s.push({arr[i], i}); // pair<int, int> = <value, index>

	}

	for(int i=0; i<span.size(); i++) {
		cout << span[i] << " ";
	}

	return 0;
}