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
		parentMap[x] = x;
		rankMap[x] = 1;
	}

	T findSet(T x) {
		if(parentMap[x] == x) {
			return x; // x is the leader
		}

		return parentMap[x] = findSet(parentMap[x]); // path compression
	}

	void unionSet(T x, T y) {
		T l_x = findSet(x);
		T l_y = findSet(y);

		if(l_x != l_y) {
			// we can do the union
			int r_x = rankMap[l_x];
			int r_y = rankMap[l_y];
			if(r_x > r_y) {
				// make l_x as the new leader
				parentMap[l_y] = l_x;
				rankMap[l_x] += rankMap[l_y];
			} else {
				// make l_y as the new leader
				parentMap[l_x] = l_y;
				rankMap[l_y] += rankMap[l_x];
			}
		}
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
