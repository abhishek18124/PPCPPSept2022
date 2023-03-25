/* 
	
	Implementation of the disjoint set union data structure 
	by using union by rank and path compression heuristics.

*/

#include<iostream>
#include<unordered_map>

using namespace std;

template <typename T>
class disjointSet {

	unordered_map<T, T> parentMap; // to store a mapping b/w vertices & their parents
	unordered_map<T, T> rankMap;   // to store a mapping b/w vertices & their ranks i.e. sizes
	
	public :

	void createSet(T x) {
		// todo ...
	}

	T findSet(T x) {
		// todo ...
	}

	void unionSet(T x, T y) {
		// todo ...
	}

};

int main() {

	disjointSet<int> ds;

	ds.createSet(1); // {1}
	ds.createSet(2); // {2}
	ds.createSet(3); // {3}
	ds.createSet(4); // {4}

	ds.unionSet(1, 2); // {1, 2}, {3}, {4}
	ds.unionSet(2, 3); // {1, 2, 3}, {4}

	cout << ds.findSet(2) << endl;

	ds.unionSet(3, 4); // {1, 2, 3, 4}

	cout << ds.findSet(4) << endl;

	return 0;
}
