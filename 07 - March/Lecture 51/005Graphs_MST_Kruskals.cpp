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
		int w;

		edge(T u, T v, int w) {
			this->u = u;
			this->v = v;
			this->w = w;
		}
};

template <typename T>
bool edgeComparator(edge<T> e1, edge<T> e2) {
		return e1.w < e2.w;
}

template <typename T>
class graph {

	set<T>  vertexSet;        // to store the graph representation
	vector<edge<T>> edgeList; // to store the graph representation

	public :

		void addEdge(T u, T v, int w) {
			// add an edge of weight 'w' b/w 'u' and 'v' 
			edgeList.push_back(edge<T>(u, v, w));
			vertexSet.insert(u);
			vertexSet.insert(v);
		}

		vector<edge<T>> kruskal() {
			disjointSet<T> ds;

			// 1. create a set corresponding to each graph vertex
			for(T vertex : vertexSet) {
				ds.createSet(vertex);
			}

			// 2. sort list of edges
			sort(edgeList.begin(), edgeList.end(), edgeComparator<T>);

			// 3. construct MST
			int sum = 0;
			vector<edge<T>> mst;
			for(edge<T> e : edgeList) {
				if(ds.findSet(e.u) != ds.findSet(e.v)) {
					// u to v is a safe edge
					ds.unionSet(e.u, e.v);
					mst.push_back(e);
					sum += e.w;
					if(mst.size() == vertexSet.size() - 1) {
						// you've selected V-1 safe edges
						break;
					}
				}
			}

			cout << sum << endl;

			return mst;
		}

};

int main() {

	graph<char> g;

	g.addEdge('A', 'B', 4);
	g.addEdge('A', 'C', 5);
	g.addEdge('B', 'D', 2);
	g.addEdge('B', 'E', 7);
	g.addEdge('C', 'D', 6);
	g.addEdge('C', 'F', 9);
	g.addEdge('E', 'F', 1);
	g.addEdge('E', 'G', 3);
	g.addEdge('F', 'G', 8);

	vector<edge<char>> mst = g.kruskal();

	for(edge<char> e : mst) {
		cout << "(" << e.u << ", " << e.v << ", " << e.w << ")" << endl;
	}

	return 0;
}