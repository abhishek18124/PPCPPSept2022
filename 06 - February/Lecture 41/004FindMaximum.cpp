#include<iostream>
#include<vector>
#include<deque>

using namespace std;

int main() {

	int arr[] = {1, 4, 0, 1, 2, 3, 5};
	int n = sizeof(arr) / sizeof(int);
	int k = 4;

	int i = 0;     // to store the start of the window
	int j = 0;     // to store the end of the window
	deque<int> q;  // to store numbers of interest in a window
	vector<int> v; // to store the maximum element for each k-sized window
	
	// find the maximum element in the 1st window
	
	while(j < k) {
		while(!q.empty() && q.back() < arr[j]) q.pop_back();
		q.push_back(arr[j]);
		j++;
	}

	v.push_back(q.front());
	
	// find the maximum element in the remaining windows
	
	while(j < n) {
		// slide the window
		if(q.front() == arr[i]) q.pop_front();
		i++;
		while(!q.empty() && q.back() < arr[j]) q.pop_back();
		q.push_back(arr[j]);
		
		v.push_back(q.front());
		
		j++;
	}

	for(int i=0; i<v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;
	
	return 0;
}

