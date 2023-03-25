/* 
	
	Cycle detection in an undirection graph using the union-find algorithm.

*/

#include<iostream>
#include<unordered_map>
#include<set>
#include<vector>

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
			return x;
		}

		return parentMap[x] = findSet(parentMap[x]); // path compression
	}

	void unionSet(T x, T y) {
		T l_x = findSet(x);
		T l_y = findSet(y);
		if(l_x != l_y) {
			if(rankMap[l_x] > rankMap[l_y]) { // union by rank (size)
				parentMap[l_y] = l_x;
				rankMap[l_x] += rankMap[l_y];
			} else {
				parentMap[l_x] = l_y;
				rankMap[l_y] += rankMap[l_x];
			}
		}
	}

};


template <typename T>
class edge {
	public :

		T u;
		T v;

		edge(T u, T v) {
			this->u = u;
			this->v = v;
		}
};

template <typename T>
class graph {

	set<T>  vertexSet;        // to store the graph representation
	vector<edge<T>> edgeList; // to store the graph representation

	public :

		void addEdge(T u, T v) {
			// add an edge of weight 'w' b/w 'u' and 'v' 
			edgeList.push_back(edge<T>(u, v));
			vertexSet.insert(u);
			vertexSet.insert(v);
		}

		bool isCyclePresent() {
			disjointSet<T> ds;
			for(T vertex : vertexSet) {
				ds.createSet(vertex);
			}
			for(edge<T> e : edgeList) {
				if(ds.findSet(e.u) != ds.findSet(e.v)) {
					ds.unionSet(e.u, e.v);
				} else {
					return true;
				}
			}
			return false;
		}
};

int main() {

	graph<char> g;

	g.addEdge('A', 'B');
	g.addEdge('A', 'C');
	g.addEdge('B', 'C');

	g.isCyclePresent() ? cout << "cycle found!" << endl :
	                     cout << "cycle not found!" << endl;

	return 0;
}
