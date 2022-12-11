/*
	
	https://cplusplus.com/reference/set/set/?kw=set
	https://cplusplus.com/reference/set/multiset/?kw=multiset
	
	> insert/erase/find is logarithmic i.e. O(logn)
	> values are inserted in the sorted order
	> set contains only distinct values
	> multiset allows duplicate values

*/

#include<iostream>
#include<set>

using namespace std;

int main() {

	set<int> s;
	
	s.insert(5);
	s.insert(4);
	s.insert(3);
	s.insert(2);
	s.insert(1);
	s.insert(1);

	cout << "size : " << s.size() << endl;

	s.erase(5);

	cout << "size : " << s.size() << endl;

	for(auto it=s.begin(), end=s.end(); it != end; it++) {
		cout << *it << " ";
	}

	cout << endl;

	for(auto x : s) {
		cout << x << " ";
	}

	cout << endl;

	if(s.find(3) != s.end()) {
		cout << "3 is present" << endl;
	} else {
		cout << "3 is absent" << endl;
	}

	if(s.count(5)) {
		cout << "5 is present" << endl;
	} else {
		cout << "5 is absent" << endl;
	}


	s.clear();

	cout << "size : " << s.size() << endl;

	return 0;
}