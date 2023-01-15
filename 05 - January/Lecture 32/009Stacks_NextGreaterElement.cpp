#include<iostream>
#include<stack>
#include<vector>

using namespace std;

// time : O(n) space : O(n) (in the worst-case when array is in the inc. order stack size is n, no one will be popped)

int main() {

	int arr[] = {5, 3, 6, 7, 2, 1, 4};
	int n = sizeof(arr) / sizeof(int);

	vector<int> ngr; // nearest_greater_to_the_right
	stack<int> s;

	for(int i=n-1; i>=0; i--) {

		// find the nearest greater to the right of arr[i]

		while(!s.empty() and s.top() <= arr[i]) {
			s.pop();
		}

		if(!s.empty()) {
			ngr.push_back(s.top());
		} else {
			ngr.push_back(-1);
		}

		s.push(arr[i]);

	}

	reverse(ngr.begin(), ngr.end());

	for(int i=0; i<ngr.size(); i++) {
		cout << ngr[i] << " ";
	}

	cout << endl;

	return 0;
}