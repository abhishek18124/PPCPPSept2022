/* 
	
	Implementation of the disjoint set union data structure.

*/

#include<iostream>
#include<unordered_map>

using namespace std;

template <typename T>
class disjointSet {

	unordered_map<T, T> parentMap; // to store a mapping b/w vertices & their parents
	
	public :

	void createSet(T x) {
		parentMap[x] = x; // O(1)
	}

	T findSet(T x) {
		if(parentMap[x] == x) {
			// leader is x
			return x;
		}

		return findSet(parentMap[x]);
	}

	void unionSet(T x, T y) {
		T l_x = findSet(x);
		T l_y = findSet(y);
		if(l_x != l_y) {
			// do the union between sets of x and y

			// 1. option 1 
			parentMap[l_x] = l_y;

			// // 2. option 2
			// parentMap[l_y] = l_x;
		}
	}

};

int main() {

	disjointSet<int> ds;

	ds.createSet(1);
	ds.createSet(2);
	ds.createSet(3);
	ds.createSet(4);

	ds.unionSet(2, 3);

	cout << ds.findSet(2) << endl;

	ds.unionSet(1, 4);

	cout << ds.findSet(1) << endl;

	ds.unionSet(3, 4);

	cout << ds.findSet(1) << endl;
	cout << ds.findSet(2) << endl;
	cout << ds.findSet(3) << endl;
	cout << ds.findSet(4) << endl;

	return 0;
}