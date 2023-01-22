#include<iostream>
#include<vector>
#include<utility>

using namespace std;

bool myComparator(pair<int, char> a, pair<int, char> b) {
	// assume 'a' is present before 'b'
	
	if(a.second < b.second) {
		// swap is not required
		return true;
	}

	// swap is required
	return false;
}

int main() {

	vector<int> v1; // v1 is a vector to store a sequence of integers

	// 1. declarating a vector of pair

	vector<pair<int, int>> v2; // v2 is a vector to store a sequence of pair of integers

	vector<pair<string, string>> v3; // v3 is a vector to store a sequence of pair of strings 

	// 2. initialising a vector of pair

	// a. using {}

	vector<pair<int, int>> v4 = {{1, 2}, {3, 4}, {5, 6}};
	for(int i=0; i<v4.size(); i++) {
		cout << "(" << v4[i].first << ", " << v4[i].second << ") ";
	}

	cout << endl;

	// b. using make_pair

	vector<pair<int, int>> v5 = {make_pair(1, 2), make_pair(3, 4), make_pair(5, 6)};
	for(int i=0; i<v5.size(); i++) {
		cout << "(" << v5[i].first << ", " << v5[i].second << ") ";
	}

	cout << endl;

	// 3. sorting a vector of pair

	vector<pair<int, char>> v6 = {{2, 'B'}, {3, 'A'}, {1, 'C'}};

	sort(v6.begin(), v6.end()); // by default, a vector of pair is sorted in the 
								// increasing order of first element of the pair

	for(int i=0; i<v6.size(); i++) {
		cout << "(" << v6[i].first << ", " << v6[i].second << ") ";
	}

	cout << endl;

	sort(v6.begin(), v6.end(), myComparator); // myComparator ensures vector is sorted
											  // is sorted in the increasing order of 
	                                          // second element of the pair

	// using a for-each loop to iterate over vector of pair<int, char>

	for(pair<int, char> p : v6) {
		cout << "(" << p.first << ", " << p.second << ") ";
	}

	cout << endl;

	// 4. reading data into a vector of pair

	// a. using push_back

	int n; // denotes the size of vector
	cin >> n;

	vector<pair<int, int>> v7; 

	for(int i=0; i<n; i++) {

		// read a pair of values from the user 

		int x, y;
		cin >> x >> y; 

		// insert the pair (x, y) into vector

		v7.push_back({x, y}); // or v7.push_back(make_pair(x, y));
	}

	for(pair<int, int> p : v7) {
		cout << "(" << p.first << ", " << p.second << ") ";
	}

	cout << endl;

	// b. using fixed sized vector

	int m; // denotes the size of vector
	cin >> m;

	vector<pair<int, int>> v8(m); 

	for(int i=0; i<m; i++) {
		// directly read a pair of values from the user into the vector of pair
		cout << v8[i].first << " " << v8[i].second << endl;
	}

	for(pair<int, int> p : v8) {
		cout << "(" << p.first << ", " << p.second << ") ";
	}

	cout << endl;

	return 0;
}