/*
	
	Vectors Part II
	
	How to create a vector ? 
		> use fill constructor
		> use range constructor
		> use copy constructor
		> use initialiser list (C++11)
	How to add elements to a vector ?
	    > use vector::insert
	      > single element
	      > fill
	      > range
	      > initialiser list
	How to remove elements from a vector ?
	    > use vector::erase
	      > single element
	      > range

	How to sort a vector ?
      > use built-in comparator
      > use user-defined comparator
      > pass in reverse order

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	// fill constructor 
	vector<int> v(5); // or vector<int> v(5, 100);
	for(int i=0; i<v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	// copy constructor
	vector<int> v2 = v; // or v2(v);
	
	// copy assignment operator
	vector<int> v3;
	v3 = v;

	// range constructor
	vector<int> v4 = {1, 2, 3, 4, 5};
	vector<int> v5(v4.begin()+2, v4.end());

	return 0;
}






