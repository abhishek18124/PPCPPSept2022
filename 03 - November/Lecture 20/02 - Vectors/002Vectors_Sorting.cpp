#include<iostream>
#include<vector>

using namespace std;

/* 
	return 'true' when a swap isn't required.

	at present, idx(a) < idx(b), therefore swap won't be required 
	if 'a' is already greater than 'b'.
*/

bool myGreaterComparator(int a, int b) { 
	return a > b;
}

/* 
	return 'true' when a swap isn't required.

	at present, idx(a) < idx(b), therefore swap won't be required 
	if 'a' is already lesser than 'b'.
*/

bool myLesserComparator(int a, int b) { 
	return a < b;
}

int main() {

	// create a vector using initialiser list
	vector<int> v = {1, 0, 2, 4, 3};
	cout << "size : " << v.size() << endl;
	int n = v.size();
	for(int i=0; i<n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	// reverse a vector
	
	reverse(v.begin(), v.end());

	for(int i=0; i<n; i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	// sort a vector
	
	sort(v.begin(), v.end()); 
	for(int i=0; i<n; i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	// vector<int> v2 = {30, 20, 0, 10, 60, 50};
	
	// // 1. using rbegin() & rend()

	// sort(v2.rbegin(), v2.rend());
	// for(int i=0; i<v2.size(); i++) {
	// 	cout << v2[i] << " ";
	// }

	// // 2. using greater<int>

	// sort(v2.begin(), v2.end(), greater<int>()); // default is less<int> for sorting in inc. order
	// for(int i=0; i<v2.size(); i++) {
	// 	cout << v2[i] << " ";
	// }
	// cout << endl;

	// // 3. using custom comparator
	// sort(v2.begin(), v2.end(), myGreaterComparator);
	// for(int i=0; i<v2.size(); i++) {
	// 	cout << v2[i] << " ";
	// }
	// cout << endl;

	return 0;
}